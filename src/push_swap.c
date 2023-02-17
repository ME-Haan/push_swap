/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/31 12:30:02 by mhaan         #+#    #+#                 */
/*   Updated: 2023/02/17 14:02:54 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_b = NULL;
	// 1. Error handling.
	check_error(argc, argv);

	// 2. Parsing arguments into linked list.
	stack_a = parse_arguments(argc, argv);

	// **Testing the operations**
	// stack_b = parse_arguments(argc, argv);
	ops_switch(&stack_a, &stack_b, "pb");

	// **Testing by printing the contents of the list **
	printf("Stack A:\n");
	print_stack(stack_a);
	printf("Stack B:\n");
	print_stack(stack_b);

	// *3. Sorting stack from smalles to biggest integer.
	// 	a. Check if the list is sorted. If so, exit. Else continue.
	// 	b. Check which instruction should be used next.
	// 	c. Print instruction, followed by a newline.

	// 4. Free the list
	ps_stackclear(&stack_a);

	// Test leaks:
	// system("leaks push_swap");
}

void	print_stack(t_stack *stack)
{
	while (stack)
	{
		printf("Index:%i, ", stack->index);
		printf("Num: %i\n", stack->num);
		stack = stack->next;
	}
	printf("--------\n");
}
