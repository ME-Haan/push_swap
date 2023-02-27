/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/31 13:57:24 by mhaan         #+#    #+#                 */
/*   Updated: 2023/02/24 17:42:40 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// includes:
# include <libft.h>
# include <limits.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

// includes for testing !!!!
# include	<stdio.h>

// structs:
typedef struct s_stack
{
	int				num;
	unsigned int	index;
	struct s_stack	*next;
}	t_stack;

// base functions:
int		check_error(int argc, char **argv);
t_stack	*parse_arguments(int argc, char **argv);

// stack functions:
t_stack	*ps_stacknew(int num);
t_stack	*ps_stacklast(t_stack *stack);
void	ps_stackadd_back(t_stack **stack, t_stack *new);
void	ps_stackclear(t_stack **stack);
int		ps_stacklen(t_stack *stack);

// sorting:
void	simple_sort(t_stack **stack_a);
void	ps_radix_sort(t_stack **stack_a);

// operation functions:
void	ops_switch(t_stack **stack_a, t_stack **stack_b, char *op);
void	ps_swap(t_stack **stack);
void	ps_push(t_stack **stack1, t_stack **stack2);
void	ps_rotate(t_stack **stack);
void	ps_rev_rotate(t_stack **stack);

// test functions:
void	print_stack(t_stack *stack);
void	test_print(t_stack *stack_a, t_stack *stack_b);

#endif