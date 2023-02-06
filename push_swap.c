/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/31 12:30:02 by mhaan         #+#    #+#                 */
/*   Updated: 2023/02/06 17:25:40 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_list	*list;

	list = NULL;
	// 1. Error handling.
	check_error(argc, argv);
	// 2. Parsing arguments into linked list.
	// list = parse_arguments(argc, argv);
	parse_arguments(argc, argv, list);
	/*3. Sorting stack from smalles to biggest integer.
			a. Check if the list is sorted. If so, exit. Else continue.
			b. Check which instruction should be used next.
			c. Print instruction, followed by a newline.
	*/

	// **Testing by printing the contents of the list **
	// printf("Test: %i\n", *(int *)list->content);
	print_list(list);
	// 4. Free the list
	// ft_lstclear(list, del);
}
