/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_errors.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/31 14:25:09 by mhaan         #+#    #+#                 */
/*   Updated: 2023/03/06 14:13:38 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

static int	check_int(char *str);
static int	check_limits(const char *str);
static int	check_dups(int argc, char *argv[], int i);

int	check_error(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc < 2)
		exit (EXIT_FAILURE);
	while (i < argc)
	{
		check_int(argv[i]);
		check_dups(argc, argv, i);
		i++;
	}
	if (argc == 2)
		exit (EXIT_SUCCESS);
	return (0);
}

static int	check_int(char *str)
{
	int	i;

	i = 0;
	if ((str[i] == '+' || str[i] == '-') && str[i + 1])
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
		{
			write(STDERR_FILENO, "Error\n", 6);
			exit (EXIT_FAILURE);
		}
		i++;
	}
	check_limits(str);
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

static int	check_dups(int argc, char *argv[], int i)
{
	int	arg1;
	int	arg2;
	int	j;

	while (i < argc)
	{
		arg1 = ft_atoi(argv[i]);
		j = i + 1;
		while (j < argc)
		{
			arg2 = ft_atoi(argv[j]);
			if (arg1 == arg2)
			{
				write(STDERR_FILENO, "Error\n", 6);
				exit (EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
	return (0);
}
