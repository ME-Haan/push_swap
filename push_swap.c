/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/31 12:30:02 by mhaan         #+#    #+#                 */
/*   Updated: 2023/01/31 14:21:13 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	int	i;
	(void)argc;

	i = 1;
	while (argv[i])
	{
		printf("%s\n", argv[i]);
		i++;
	}

	/*
	1. Error handling.
	2. Sorting stack from smalles to biggest integer.
			a. Check if the list is sorted. If so, exit. Else continue.
			b. Check which instruction should be used next.
			3. Print instruction, followed by a newline.
	*/
}