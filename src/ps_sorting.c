/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_sorting.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/17 13:52:20 by mhaan         #+#    #+#                 */
/*   Updated: 2023/02/17 16:37:31 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

static int	get_max(t_stack *stack);
static int	num_len(int num);

void	ps_radix_sort(t_stack **stack_a, t_stack **stack_b, int stacklen)
{
	const int	max = get_max(*stack_a);
	const int	maxlen = num_len(max);

	(void)*stack_b;
	printf("Max:%i\n", max);
	printf("Maxlen:%i\n", maxlen);
	printf("Stacklen:%i\n", stacklen);
	printf("---------------\n");

	

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
