/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaouni <aaouni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 00:14:51 by aaouni            #+#    #+#             */
/*   Updated: 2022/07/05 03:14:53 by aaouni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_digit(int argc, char **argv)
{
	int	i;
	int	k;

	k = 0;
	while (++k < argc)
	{
		if (!ft_strcmp(argv[k], "-") || !ft_strcmp(argv[k], "+"))
			return (0);
		i = -1;
		if (argv[k][0] == '-' || argv[k][0] == '+')
			i++;
		while (argv[k][++i])
		{
			if (!ft_isdigit(argv[k][i]))
				return (0);
		}
	}
	return (1);
}

int	check_limits(char *str, char signe)
{
	if (signe == '+' && ft_strcmp(str, "2147483647") > 0)
		return (0);
	else if (signe == 'p' && ft_strcmp(str + 1, "2147483647") > 0)
		return (0);
	else if (signe == '-' && ft_strcmp(str + 1, "2147483648") > 0)
		return (0);
	else
		return (1);
}

int	is_integer(char *str)
{
	int		len;
	char	signe;

	signe = '+';
	len = ft_strlen(str);
	if (str[0] == '-')
	{
		signe = '-';
		len--;
	}
	if (str[0] == '+')
	{
		signe = 'p';
		len--;
	}
	if (len > 10)
		return (0);
	else if (len < 10)
		return (1);
	else
		return (check_limits(str, signe));
}

int	ft_issorted(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (++i < argc - 1)
	{
		if (ft_atoi(argv[i]) < ft_atoi(argv[i + 1]))
			j++;
	}
	if (argc - 2 == j)
		return (0);
	return (1);
}

int	check_arg(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	if (!check_digit(argc, argv))
		return (0);
	while (++i < argc)
	{
		if (!is_integer(argv[i]))
			return (0);
		j = i;
		while (++j < argc)
		{
			if (!ft_strcmp(argv[i], argv[j]))
				return (0);
		}		
	}
	return (1);
}
