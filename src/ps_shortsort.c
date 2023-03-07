/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_shortsort.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/06 16:01:05 by mhaan         #+#    #+#                 */
/*   Updated: 2023/03/07 16:01:28 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

static void			push_lowest(t_stack **stack_a, t_stack **stack_b);
static unsigned int	find_lowest_idx(t_stack *stack_a, t_stack *stack_b);
static void			sort_3_max(t_stack **stck);

void	ps_short_sort(t_stack **stack_a)
{
	t_stack	*stack_b;

	stack_b = NULL;
	while (ps_stacklen(*stack_a) > 3)
		push_lowest(stack_a, &stack_b);
	if (!is_sorted(*stack_a) && ps_stacklen(*stack_a) <= 3)
		sort_3_max(stack_a);
	while (stack_b)
		ops_switch(stack_a, &stack_b, "pa");
}

static void	push_lowest(t_stack **stack_a, t_stack **stack_b)
{
	unsigned int	idx_low;
	unsigned int	i;
	unsigned int	stack_a_len;

	stack_a_len = ps_stacklen(*stack_a);
	idx_low = find_lowest_idx(*stack_a, *stack_b);
	if (idx_low > stack_a_len / 2)
	{
		i = stack_a_len - idx_low;
		while (i-- > 0)
			ops_switch(stack_a, stack_b, "rra");
	}
	else
	{
		i = idx_low;
		while (i-- > 0)
			ops_switch(stack_a, stack_b, "ra");
	}
	ops_switch(stack_a, stack_b, "pb");
}

static unsigned int	find_lowest_idx(t_stack *stack_a, t_stack *stack_b)
{
	t_stack			*ptr;
	unsigned int	idx_low;
	unsigned int	stack_b_len;

	ptr = stack_a;
	idx_low = 0;
	stack_b_len = ps_stacklen(stack_b);
	while (ptr && ptr->idx != stack_b_len)
	{
		idx_low++;
		ptr = ptr->next;
	}
	return (idx_low);
}

static void	sort_3_max(t_stack **stk)
{
	t_stack	*last;

	while (!is_sorted(*stk))
	{
		last = ps_stacklast(*stk);
		if ((*stk)->idx > (*stk)->next->idx && (*stk)->idx < last->idx)
			ops_switch(stk, NULL, "sa");
		else if ((*stk)->idx > (*stk)->next->idx && (*stk)->idx > last->idx)
			ops_switch(stk, NULL, "ra");
		else
			ops_switch(stk, NULL, "rra");
	}
}
