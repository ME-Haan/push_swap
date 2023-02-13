/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_stack.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/13 09:29:44 by mhaan         #+#    #+#                 */
/*   Updated: 2023/02/13 12:08:08 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

t_stack	*ps_stacknew(int num)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->num = num;
	stack->next = NULL;
	return (stack);
}

void	ps_stackadd_back(t_stack **stack, t_stack *new)
{
	t_stack	*ptr;

	if (!new)
		return ;
	if (!*stack)
		*stack = new;
	else
	{
		ptr = ps_stacklast(*stack);
		ptr->next = new;
	}
}

t_stack	*ps_stacklast(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	if (!tmp)
		return (0);
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

void	ps_stackclear(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}
