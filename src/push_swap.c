/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/31 12:30:02 by mhaan         #+#    #+#                 */
/*   Updated: 2023/02/27 16:15:30 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;

	// 1. Error handling.
	check_error(argc, argv);

	// 2. Parsing arguments into linked list.
	stack_a = parse_arguments(argc, argv);

	// *3. Sorting stack from smalles to biggest integer.
	if (argc <= 6 )
		simple_sort(&stack_a);
	else
		ps_radix_sort(&stack_a);

	// 4. Free the list
	ps_stackclear(&stack_a);

	// Test leaks:
	// system("leaks push_swap");
	return (0);
}
