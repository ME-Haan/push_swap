/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/03 13:10:09 by mhaan         #+#    #+#                 */
/*   Updated: 2023/02/06 11:24:36 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_atoi(const char *str)
{
	long long	val;
	int			sign;

	val = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-')
		sign *= -1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str && *str > 47 && *str < 58)
		val = val * 10 + (*str++ - 48);
	if (val == 2147483648 && sign == -1)
		return (INT_MIN);
	else if (val < 0 || val > INT_MAX)
	{
		write(STDERR_FILENO, "Error\n", 6);
		exit (EXIT_FAILURE);
	}
	return (val * sign);
}
