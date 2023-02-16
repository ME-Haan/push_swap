/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_parsing.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/06 13:34:18 by mhaan         #+#    #+#                 */
/*   Updated: 2023/02/16 12:40:38 by mhaan         ########   odam.nl         */
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
		node = ps_stacknew(num, i - 1);
		ps_stackadd_back(&stack, node);
		i++;
	}
	return (stack);
}
