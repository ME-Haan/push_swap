/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_parsing.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/06 13:34:18 by mhaan         #+#    #+#                 */
/*   Updated: 2023/02/13 12:08:24 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

t_stack	*parse_arguments(int argc, char **argv)
{
	int		i;
	int		num;
	t_stack	*node;
	t_stack	*stack;

	i = 1;
	stack = NULL;
	while (i < argc)
	{
		num = ft_atoi(argv[i]);
		node = ps_stacknew(num);
		ps_stackadd_back(&stack, node);
		i++;
	}
	return (stack);
}

void	print_stack(t_stack *stack)
{
	while (stack)
	{
		printf("%i\n", stack->num);
		stack = stack->next;
	}
}
