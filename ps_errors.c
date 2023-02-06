/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_errors.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/31 14:25:09 by mhaan         #+#    #+#                 */
/*   Updated: 2023/02/06 12:15:27 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"
#include	<limits.h>

#include <stdio.h>

static int	check_int(char *str);
static int	check_limits(const char *str);
static int	check_dups(int argc, char *argv[]);

int	check_error(int argc, char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		check_int(argv[i]);
		i++;
	}
	check_dups(argc, argv);
	return (write(1, "OK\n", 3), 0);
}

static int	check_int(char *str)
{
	check_limits(str);
	if (*str == '-' && *(str + 1))
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
		{
			write(STDERR_FILENO, "Error\n", 6);
			exit (EXIT_FAILURE);
		}
		str++;
	}
	return (0);
}

static int	check_limits(const char *str)
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
		return (0);
	else if (val < 0 || val > INT_MAX)
	{
		write(STDERR_FILENO, "Error\n", 6);
		exit (EXIT_FAILURE);
	}
	return (0);
}

static int	check_dups(int argc, char *argv[])
{
	int	arg1;
	int	arg2;
	int	i;
	int	j;

	i = 0;
	while (++i < argc)
	{
		arg1 = ft_atoi(argv[i]);
		j = i;
		while (++j < argc)
		{
			arg2 = ft_atoi(argv[j]);
			if (arg1 == arg2)
			{
				write(STDERR_FILENO, "Error\n", 6);
				exit (EXIT_FAILURE);
			}
		}
	}
	return (0);
}
