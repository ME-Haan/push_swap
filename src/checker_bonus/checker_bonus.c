/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker_bonus.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/09 10:17:09 by mhaan         #+#    #+#                 */
/*   Updated: 2023/03/15 17:38:14 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include	"checker_bonus.h"

static char	**ops_parser(int fd);
static int	check_valid_ops(char *ops);
static int	checker(t_stack **stack_a, char **ops);

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	char	**ops;

	check_error(argc, argv);
	stack_a = parse_arguments(argc, argv);
	ops = ops_parser(0);
	if (!check_valid_ops(*ops))
	{
		write(STDERR_FILENO, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	if (checker(&stack_a, ops))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

static char	**ops_parser(int fd)
{
	char	*tmp;
	char	**ops;
	char	buff[100];
	int		bytes_read;

	bytes_read = 1;
	tmp = NULL;
	tmp = gnl_strjoin(tmp, "");
	while (bytes_read)
	{
		bytes_read = read(fd, buff, 100);
		if (bytes_read == -1)
			return (free(tmp), NULL);
		buff[bytes_read] = '\0';
		tmp = gnl_strjoin(tmp, buff);
		if (!tmp)
			return (NULL);
	}
	ops = ft_split(tmp, '\n');
	return (free(tmp), ops);
}

static int	check_valid_ops(char *ops)
{
	char	*tmp;

	tmp = ops;
	while (*ops)
	{
		if (!ft_strncmp("sa", ops, 3) || !ft_strncmp("sb", ops, 3))
			ops++;
		else if (!ft_strncmp("ss", ops, 3))
			ops++;
		else if (!ft_strncmp("pa", ops, 3) || !ft_strncmp("pb", ops, 3))
			ops++;
		else if (!ft_strncmp("ra", ops, 3) || !ft_strncmp("rb", ops, 3))
			ops++;
		else if (!ft_strncmp("rra", ops, 4) || !ft_strncmp("rrb", ops, 4))
			ops++;
		else if (!ft_strncmp("rr", ops, 3) || !ft_strncmp("rrr", ops, 4))
			ops++;
		else
			return (0);
	}
	return (1);
}

static int	checker(t_stack **stack_a, char **ops)
{
	t_stack	**stack_b;

	stack_b = NULL;
	while (*ops)
	{
		ops_switch(stack_a, stack_b, *ops);
		ops++;
	}
	if (is_sorted(*stack_a) && !stack_b)
		return (1);
	else
		return (0);
}
