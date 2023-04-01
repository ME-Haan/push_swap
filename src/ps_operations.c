/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_operations.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/31 14:23:27 by mhaan         #+#    #+#                 */
/*   Updated: 2023/04/01 17:38:13 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

static void	ps_swap(t_stack **stack);
static void	ps_push(t_stack **stack1, t_stack **stack2);
static void	ps_rotate(t_stack **stack);
static void	ps_rev_rotate(t_stack **stack);

void	op_switch(t_stack **stk_a, t_stack **stk_b, char *op, int prnt)
{
	if (!ft_strncmp("sa", op, 3) || !ft_strncmp("ss", op, 3))
		ps_swap(stk_a);
	if (!ft_strncmp("sb", op, 3) || !ft_strncmp("ss", op, 3))
		ps_swap(stk_b);
	if (!ft_strncmp("pa", op, 3))
		ps_push(stk_a, stk_b);
	if (!ft_strncmp("pb", op, 3))
		ps_push(stk_b, stk_a);
	if (!ft_strncmp("ra", op, 3) || !ft_strncmp("rr", op, 3))
		ps_rotate(stk_a);
	if (!ft_strncmp("rb", op, 3) || !ft_strncmp("rr", op, 3))
		ps_rotate(stk_b);
	if (!ft_strncmp("rra", op, 4) || !ft_strncmp("rrr", op, 4))
		ps_rev_rotate(stk_a);
	if (!ft_strncmp("rrb", op, 4) || !ft_strncmp("rrr", op, 4))
		ps_rev_rotate(stk_b);
	if (prnt)
		ft_printf("%s\n", op);
}

static void	ps_swap(t_stack **stack)
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

static void	ps_push(t_stack **stack1, t_stack **stack2)
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

static void	ps_rotate(t_stack **stack)
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

static void	ps_rev_rotate(t_stack **stack)
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
