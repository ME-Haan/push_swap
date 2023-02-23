/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_sorting.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/17 13:52:20 by mhaan         #+#    #+#                 */
/*   Updated: 2023/02/23 15:31:09 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

static unsigned int	get_max_idx(t_stack *stack);
static unsigned int	get_bitlen(unsigned int num);
static int			ps_is_sorted(t_stack *stack);

void	simple_sort(t_stack **stack_a, int stacklen)
{
	t_stack	*stack_b;
	t_stack	*last_a;
	int		count;

	stack_b = NULL;
	count = 0;
	while (ps_stacklen(*stack_a) < stacklen || !ps_is_sorted(*stack_a))
	{
		last_a = ps_stacklast(*stack_a);
		if ((*stack_a)->index > (*stack_a)->next->index)
			ops_switch(stack_a, &stack_b, "sa");
		else if ((*stack_a)->index > last_a->index)
			ops_switch(stack_a, &stack_b, "rra");
		else if (!ps_is_sorted(*stack_a))
			ops_switch(stack_a, &stack_b, "pb");
		else if (ps_is_sorted(*stack_a) && ps_stacklen(*stack_a) != stacklen)
			ops_switch(stack_a, &stack_b, "pa");
		test_print(*stack_a, stack_b);
		count++;
	}
	printf("Max bitlen: %i\n", get_bitlen(get_max_idx(*stack_a)));
	printf("Operations performed: %i\n", count);
}

void	ps_radix_sort(t_stack **stack_a, int stacklen)
{
	t_stack				*stack_a_ptr;
	t_stack				*stack_b;
	const unsigned int	max = get_max_idx(*stack_a);
	const unsigned		bitlen = get_bitlen(max);
	unsigned int		i;

	printf("Max index:%i\n", max);
	printf("Max bitlen:%i\n", bitlen);
	printf("Stacklen:%i\n", stacklen);
	printf("---------------\n");

	stack_b = NULL;
	i = 0;
	while (i < bitlen || !ps_is_sorted(*stack_a))
	{
		stack_a_ptr = *stack_a;
		while (stack_a_ptr)
		{
			if ((stack_a_ptr->index >> i ) & 1)
				ops_switch(stack_a, &stack_b, "ra");
			else
				ops_switch(stack_a, &stack_b, "pb");
			stack_a_ptr = stack_a_ptr->next;
		}
		while (stack_b)
			ops_switch(stack_a, &stack_b, "pa");
		i++;
	}
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

static unsigned int	get_max_idx(t_stack *stack)
{
	unsigned int	max;

	max = stack->index;
	stack = stack->next;
	while (stack)
	{
		if (stack->index > max)
			max = stack->index;
		stack = stack->next;
	}
	return (max);
}

static unsigned int	get_bitlen(unsigned int num)
{
	unsigned int	count;

	count = 1;
	while (num != 0 && num != 1)
	{
		count++;
		num /= 2;
	}
	return (count);
}
