/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/31 13:57:24 by mhaan         #+#    #+#                 */
/*   Updated: 2023/02/06 17:25:11 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// includes
# include "./libft/libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

// includes for testing !!!!
#include	<stdio.h>

// prototypes
int		check_error(int argc, char **argv);
void	parse_arguments(int argc, char *argv[], t_list *list);
// t_list	*parse_arguments(int argc, char *argv[]);

// test functions
void	print_list(t_list *list);

#endif