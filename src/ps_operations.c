/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_operations.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/31 14:23:27 by mhaan         #+#    #+#                 */
/*   Updated: 2023/02/20 14:48:46 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

void	ps_swap(t_stack **stack)
{
	t_stack	*tmp;

	if (*stack && (*stack)->next)
	{
		tmp = (*stack)->next;
		(*stack)->next = (*stack)->next->next;
		tmp->next = (*stack);
		(*stack) = tmp;
	}
}

void	ps_push(t_stack **stack1, t_stack **stack2)
{
	t_stack	*new_head;

	if (*stack2)
	{
		new_head = (*stack2)->next;
		(*stack2)->next = *stack1;
		*stack1 = *stack2;
		*stack2 = new_head;
	}
}

void	ps_rotate(t_stack **stack)
{
	t_stack	*new_head;
	t_stack	*last;

	if (*stack && (*stack)->next)
	{
		last = ps_stacklast(*stack);
		new_head = (*stack)->next;
		(*stack)->next = NULL;
		last->next = *stack;
		*stack = new_head;
	}
}

void	ps_rev_rotate(t_stack **stack)
{
	t_stack	*new_last;
	t_stack	*new_head;

	if (*stack && (*stack)->next)
	{
		new_head = ps_stacklast(*stack);
		new_last = *stack;
		while (new_last->next && new_last->next->next)
			new_last = new_last->next;
		new_head->next = *stack;
		new_last->next = NULL;
		*stack = new_head;
	}
}

void	ops_switch(t_stack **stack_a, t_stack **stack_b, char *op)
{
	if (!ft_strncmp("sa", op, 2) || !ft_strncmp("ss", op, 2))
		ps_swap(stack_a);
	if (!ft_strncmp("sb", op, 2) || !ft_strncmp("ss", op, 2))
		ps_swap(stack_b);
	if (!ft_strncmp("pa", op, 2))
		ps_push(stack_a, stack_b);
	if (!ft_strncmp("pb", op, 2))
		ps_push(stack_b, stack_a);
	if (!ft_strncmp("ra", op, 3) || !ft_strncmp("rr", op, 3))
		ps_rotate(stack_a);
	if (!ft_strncmp("rb", op, 3) || !ft_strncmp("rr", op, 3))
		ps_rotate(stack_b);
	if (!ft_strncmp("rra", op, 3) || !ft_strncmp("rrr", op, 3))
		ps_rev_rotate(stack_a);
	if (!ft_strncmp("rrb", op, 3) || !ft_strncmp("rrr", op, 3))
		ps_rev_rotate(stack_b);
	// TO DO: Import ft_printf!!!!
	printf("%s\n", op);
}
