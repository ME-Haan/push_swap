/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_operations.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/31 14:23:27 by mhaan         #+#    #+#                 */
/*   Updated: 2023/02/16 15:30:55 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"


void	ps_swap(t_stack **stack)
{
	int		tmp;

	if (*stack && (*stack)->next)
	{
		tmp = (*stack)->next->num;
		(*stack)->next->num = (*stack)->num;
		(*stack)->num = tmp;
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

/*
void	ps_rotate(t_stack stack)
{

}

void	ps_rev_rotate(t_stack stack)
{

}
*/
