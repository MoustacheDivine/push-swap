/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbruscan <gbruscan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 20:30:47 by gbruscan          #+#    #+#             */
/*   Updated: 2024/10/29 04:18:45 by gbruscan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol_scam(const char *str)
{
	int		i;
	long	result;
	int		sign;

	sign = 1;
	i = 0;
	result = 0;
	if (str[i] != '+' && str[i] != '-' && !ft_isdigit(str[i]))
		return (ERROR_VALUE);
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	result *= sign;
	if (str[i] == '\0' && result >= -2147483648 && result <= 2147483647)
		return (result);
	return (ERROR_VALUE);
}

int	checktab(int *tab, int end)
{
	int	i;
	int	n;

	n = 0;
	while (n < end)
	{
		i = n + 1;
		while (i < end)
		{
			if (tab[i] == tab[n])
				return (0);
			i++;
		}
		n++;
	}
	return (1);
}

int	len_check(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] == '0')
		i++;
	j = i;
	while (str[i])
		i++;
	return (i - j);
}

int	parse_args(int argc, char **argv, int *tab)
{
	int		i;
	long	value;

	i = 1;
	while (i < argc)
	{
		if (len_check(argv[i]) > 10)
			return (0);
		value = ft_atol_scam(argv[i]);
		if (value == ERROR_VALUE)
			return (0);
		tab[i - 1] = (int)value;
		i++;
	}
	return (i - 1);
}
