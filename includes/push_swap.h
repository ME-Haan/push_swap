/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/31 13:57:24 by mhaan         #+#    #+#                 */
/*   Updated: 2023/02/16 15:19:40 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// includes
# include <libft.h>
# include <limits.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

// includes for testing !!!!
# include	<stdio.h>

typedef struct s_stack
{
	int				num;
	unsigned int	index;
	struct s_stack	*next;
}	t_stack;

// base functions
int		check_error(int argc, char **argv);
t_stack	*parse_arguments(int argc, char **argv);

// stack functions
t_stack	*ps_stacknew(int num, int i);
t_stack	*ps_stacklast(t_stack *stack);
void	ps_stackadd_back(t_stack **stack, t_stack *new);
void	ps_stackclear(t_stack **stack);

// operation functions
void	ps_swap(t_stack **stack);
void	ps_push(t_stack **stack1, t_stack **stack2);

// test functions
void	print_stack(t_stack *stack);

#endif