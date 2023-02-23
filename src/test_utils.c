/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_utils.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/23 13:40:07 by mhaan         #+#    #+#                 */
/*   Updated: 2023/02/23 13:41:16 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

void	print_stack(t_stack *stack)
{
	while (stack)
	{
		printf("Index:%i, ", stack->index);
		printf("%i\n", stack->num);
		stack = stack->next;
	}
}

void	test_print(t_stack *stack_a, t_stack *stack_b)
{
	printf("----------------\n");
	printf("Stack A:\n");
	print_stack(stack_a);
	printf("----------------\n");
	printf("Stack B:\n");
	print_stack(stack_b);
	printf("****************\n\n");
}
