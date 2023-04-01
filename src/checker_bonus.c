/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker_bonus.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/09 10:17:09 by mhaan         #+#    #+#                 */
/*   Updated: 2023/04/01 17:33:01 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

static char	**ops_parser(int fd);
static int	check_valid_op(char *op);
static int	checker(t_stack **stack_a, char **ops);
static void	free_ops(char **ops);

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	char	**ops;

	check_error(argc, argv);
	stack_a = parse_arguments(argc, argv);
	ops = ops_parser(STDIN_FILENO);
	if (!stack_a || !ops)
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	if (checker(&stack_a, ops))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_ops(ops);
	ps_stackclear(&stack_a);
	exit (EXIT_SUCCESS);
}

static char	**ops_parser(int fd)
{
	char	*tmp;
	char	*op;
	char	**ops;

	tmp = NULL;
	tmp = gnl_strjoin(tmp, "");
	while (1)
	{
		op = get_next_line(fd);
		if (!op)
			break ;
		if (!check_valid_op(op))
		{
			ft_putstr_fd("Error\n", STDERR_FILENO);
			exit(EXIT_FAILURE);
		}
		tmp = gnl_strjoin(tmp, op);
		free(op);
	}
	ops = ft_split(tmp, '\n');
	return (free(tmp), ops);
}

static int	check_valid_op(char *op)
{
	if (!ft_strncmp("sa\n", op, 3) || !ft_strncmp("sb\n", op, 3))
		return (1);
	else if (!ft_strncmp("ss\n", op, 3))
		return (1);
	else if (!ft_strncmp("pa\n", op, 3) || !ft_strncmp("pb\n", op, 3))
		return (1);
	else if (!ft_strncmp("ra\n", op, 3) || !ft_strncmp("rb\n", op, 3))
		return (1);
	else if (!ft_strncmp("rra\n", op, 4) || !ft_strncmp("rrb\n", op, 4))
		return (1);
	else if (!ft_strncmp("rr\n", op, 3) || !ft_strncmp("rrr\n", op, 4))
		return (1);
	else
		return (0);
}

static int	checker(t_stack **stack_a, char **ops)
{
	t_stack	*stack_b;

	stack_b = NULL;
	while (*ops)
	{
		op_switch(stack_a, &stack_b, *ops, 0);
		ops++;
	}
	if (is_sorted(*stack_a) && !stack_b)
		return (1);
	else
		return (0);
}

static void	free_ops(char **ops)
{
	char	**tmp;

	if (!*ops)
		return ;
	tmp = ops;
	while (*ops)
	{
		free(*ops);
		ops++;
	}
	ops = tmp;
	free(ops);
}
