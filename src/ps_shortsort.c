/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_shortsort.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/06 16:01:05 by mhaan         #+#    #+#                 */
/*   Updated: 2023/03/06 17:56:16 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

static void	push_lowest(t_stack **stack_a, t_stack **stack_b);
static void	sort_3(t_stack **stck);

void	ps_short_sort(t_stack **stack_a)
{
	t_stack			*stack_b;

	stack_b = NULL;
	while (ps_stacklen(*stack_a) > 3)
		push_lowest(stack_a, &stack_b);
	if (!is_sorted(*stack_a))
		sort_3(stack_a);
	while (stack_b)
		ops_switch(stack_a, &stack_b, "pa");
}

static void	push_lowest(t_stack **stack_a, t_stack **stack_b)
{
	unsigned int	idx_low;
	unsigned int	i;
	unsigned int	stack_a_len;
	unsigned int	stack_b_len;
	t_stack			*ptr;

	idx_low = 0;
	stack_a_len = ps_stacklen(*stack_a);
	stack_b_len = ps_stacklen(*stack_b);
	ptr = (*stack_a);
	while (ptr && ptr->index != stack_b_len)
	{
		idx_low++;
		ptr = ptr->next;
	}
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

static void	sort_3(t_stack **stck)
{
	t_stack	*last;

	while (!is_sorted(*stck))
	{
		last = ps_stacklast(*stck);
		if ((*stck)->index > (*stck)->next->index && (*stck)->index < last->index)
			ops_switch(stck, NULL, "sa");
		else if ((*stck)->index > (*stck)->next->index && (*stck)->index > last->index)
			ops_switch(stck, NULL, "ra");
		else
			ops_switch(stck, NULL, "rra");
	}
}
