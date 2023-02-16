/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/31 12:30:02 by mhaan         #+#    #+#                 */
/*   Updated: 2023/02/16 10:20:00 by mhaan         ########   odam.nl         */
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

	// **Testing by printing the contents of the list **
	print_stack(stack_a);

	/*3. Sorting stack from smalles to biggest integer.
			a. Check if the list is sorted. If so, exit. Else continue.
			b. Check which instruction should be used next.
			c. Print instruction, followed by a newline.
	*/

	// 4. Free the list
	ps_stackclear(&stack_a);
	system("leaks push_swap");
}
