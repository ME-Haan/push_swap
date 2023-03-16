/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/31 12:30:02 by mhaan         #+#    #+#                 */
/*   Updated: 2023/03/16 15:05:35 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;

	check_error(argc, argv);
	stack_a = parse_arguments(argc, argv);
	if (!stack_a)
	{
		write(STDERR_FILENO, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	if (argc <= 6)
		ps_short_sort(&stack_a);
	else
		ps_radix_sort(&stack_a);
	ps_stackclear(&stack_a);
	exit (EXIT_SUCCESS);
}
