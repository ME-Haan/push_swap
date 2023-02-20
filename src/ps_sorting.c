/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_sorting.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/17 13:52:20 by mhaan         #+#    #+#                 */
/*   Updated: 2023/02/20 16:21:52 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

static int	get_max(t_stack *stack);
static int	num_len(int num);
static int	ps_is_sorted(t_stack *stack);

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
		printf("****************\n");
		if ((*stack_a)->num > (*stack_a)->next->num)
			ops_switch(stack_a, &stack_b, "sa");
		else if ((*stack_a)->num > last_a->num)
			ops_switch(stack_a, &stack_b, "rra");
		else if (!ps_is_sorted(*stack_a))
			ops_switch(stack_a, &stack_b, "pb");
		else if (ps_is_sorted(*stack_a) && ps_stacklen(*stack_a) != stacklen)
			ops_switch(stack_a, &stack_b, "pa");
		printf("----------------\n");
		printf("Stack A:\n");
		print_stack(*stack_a);
		printf("Stack B:\n");
		print_stack(stack_b);
		printf("****************\n\n");
		count++;
	}
	printf("Operations performed: %i\n", count);
}

void	ps_radix_sort(t_stack **stack_a, int stacklen)
{
	t_stack		*stack_b;
	const int	max = get_max(*stack_a);
	const int	maxlen = num_len(max);

	(void)stack_b;
	printf("Max:%i\n", max);
	printf("Maxlen:%i\n", maxlen);
	printf("Stacklen:%i\n", stacklen);
	printf("---------------\n");
}

static int	ps_is_sorted(t_stack *stack)
{
	while (stack->next)
	{
		if (stack->num > stack->next->num)
			return (0);
		stack = stack->next;
	}
	return (1);
}

static int	get_max(t_stack *stack)
{
	int	max;

	max = stack->num;
	stack = stack->next;
	while (stack)
	{
		if (stack->num > max)
			max = stack->num;
		stack = stack->next;
	}
	return (max);
}

static int	num_len(int num)
{
	int	count;

	count = 1;
	num /= 10;
	while (num)
	{
		count++;
		num /= 10;
	}
	return (count);
}
