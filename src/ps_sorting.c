/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_sorting.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/17 13:52:20 by mhaan         #+#    #+#                 */
/*   Updated: 2023/02/24 17:24:31 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

// static unsigned int	get_max_idx(t_stack *stack);
// static unsigned int	get_bitlen(unsigned int num);
static int			ps_is_sorted(t_stack *stack);
// static int			ps_is_revsorted(t_stack *stack);

void	simple_sort(t_stack **stack_a)
{
	t_stack	*stack_b;
	t_stack	*last_a;
	int		count = 0;

	stack_b = NULL;
	while (stack_b || !ps_is_sorted(*stack_a))
	{
		last_a = ps_stacklast(*stack_a);
		if ((*stack_a)->index > (*stack_a)->next->index)
			ops_switch(stack_a, &stack_b, "sa");
		else if ((*stack_a)->index > last_a->index)
			ops_switch(stack_a, &stack_b, "rra");
		else if (!ps_is_sorted(*stack_a))
			ops_switch(stack_a, &stack_b, "pb");
		else if (ps_is_sorted(*stack_a) && stack_b)
			ops_switch(stack_a, &stack_b, "pa");
		count++;
		test_print(*stack_a, stack_b);
	}
	printf("Operations performed: %i\n", count);
}

// void	simple_sort(t_stack **stack_a, int stacklen)
// {
// 	t_stack	*stack_b;
// 	t_stack	*last_a;
// 	t_stack	*last_b;
// 	int		count = 0;

// 	stack_b = NULL;
// 	(void)stacklen;
// 	while (stack_b || !ps_is_sorted(*stack_a))
// 	{
// 		last_a = ps_stacklast(*stack_a);
// 		if ((*stack_a)->index > (*stack_a)->next->index)
// 			ops_switch(stack_a, &stack_b, "sa");
// 		else if ((*stack_a)->index > last_a->index)
// 			ops_switch(stack_a, &stack_b, "rra");
// 		else if (!ps_is_sorted(*stack_a))
// 		{
// 			ops_switch(stack_a, &stack_b, "pb");
// 			if (stack_b->next)
// 			{
// 				while (stack_b && !ps_is_revsorted(stack_b))
// 				{
// 					last_b = ps_stacklast(stack_b);
// 					if (stack_b->index < stack_b->next->index)
// 						ops_switch(stack_a, &stack_b, "sb");
// 					else if (stack_b->index < last_b->index)
// 						ops_switch(stack_a, &stack_b, "rrb");
// 					count++;
// 				}
// 			}
// 		}
// 		else if (ps_is_sorted(*stack_a) && stack_b)
// 				ops_switch(stack_a, &stack_b, "pa");
// 		count++;
// 		test_print(*stack_a, stack_b);
// 	}
// 	printf("Operations performed: %i\n", count);
// }

void	ps_radix_sort(t_stack **stack_a, int stacklen)
{
	t_stack				*stack_b;
	// const unsigned int	max = get_max_idx(*stack_a);
	// const unsigned int	bitlen = get_bitlen(max);
	unsigned int		i;
	int					j;

	int		count = 0;

	stack_b = NULL;
	i = 0;
	while (stack_b || !ps_is_sorted(*stack_a))
	{
		j = 0;
		while (j < stacklen && ps_stacklen(*stack_a) > 1)
		{
			if (((*stack_a)->index >> i) & 1)
				ops_switch(stack_a, &stack_b, "ra");
			else
				ops_switch(stack_a, &stack_b, "pb");
			test_print(*stack_a, stack_b);
			count++;
			j++;
		}
		while (stack_b)
		{
			ops_switch(stack_a, &stack_b, "pa");
			test_print(*stack_a, stack_b);
			count++;
		}
		i++;
	}
	printf("Operations performed: %i\n", count);
}

static int	ps_is_sorted(t_stack *stack)
{
	while (stack->next)
	{
		if (stack->index > stack->next->index)
			return (0);
		stack = stack->next;
	}
	return (1);
}

// static int	ps_is_revsorted(t_stack *stack)
// {
// 	while (stack->next)
// 	{
// 		if (stack->index < stack->next->index)
// 			return (0);
// 		stack = stack->next;
// 	}
// 	return (1);
// }

// static unsigned int	get_max_idx(t_stack *stack)
// {
// 	unsigned int	max;

// 	max = stack->index;
// 	stack = stack->next;
// 	while (stack)
// 	{
// 		if (stack->index > max)
// 			max = stack->index;
// 		stack = stack->next;
// 	}
// 	return (max);
// }

// static unsigned int	get_bitlen(unsigned int num)
// {
// 	unsigned int	count;

// 	count = 1;
// 	while (num != 0 && num != 1)
// 	{
// 		count++;
// 		num /= 2;
// 	}
// 	return (count);
// }
