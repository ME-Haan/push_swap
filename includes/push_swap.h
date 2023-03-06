/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/31 13:57:24 by mhaan         #+#    #+#                 */
/*   Updated: 2023/03/06 17:23:41 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// Includes:
# include <libft.h>
# include <limits.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

// Structs:
typedef struct s_stack
{
	int				num;
	unsigned int	index;
	struct s_stack	*next;
}	t_stack;

// Parsing functions:
int				check_error(int argc, char **argv);
t_stack			*parse_arguments(int argc, char **argv);

// Stack functions:
t_stack			*ps_stacknew(int num);
t_stack			*ps_stacklast(t_stack *stack);
void			ps_stackadd_back(t_stack **stack, t_stack *new);
void			ps_stackclear(t_stack **stack);
unsigned int	ps_stacklen(t_stack *stack);

// Sorting functions:
int				is_sorted(t_stack *stack);
// void			simple_sort(t_stack **stack_a);
void			ps_short_sort(t_stack **stack_a);
void			ps_radix_sort(t_stack **stack_a);

// Operation functions:
void			ops_switch(t_stack **stack_a, t_stack **stack_b, char *op);
void			ps_swap(t_stack **stack);
void			ps_push(t_stack **stack1, t_stack **stack2);
void			ps_rotate(t_stack **stack);
void			ps_rev_rotate(t_stack **stack);

#endif