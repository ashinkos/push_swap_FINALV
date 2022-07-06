/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaouni <aaouni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 11:36:12 by aaouni            #+#    #+#             */
/*   Updated: 2022/06/26 13:55:30 by aaouni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_is_whitespace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' \
			|| c == '\f' || c == '\r' || c == 32)
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	unsigned int	nb_debut;
	long long		nb;
	long long		nb_signe;

	nb_debut = 0;
	nb_signe = 1;
	nb = 0;
	while (ft_is_whitespace(str[nb_debut]) == 1)
		nb_debut++;
	if (str[nb_debut] == '-' || str[nb_debut] == '+')
	{
		if (str[nb_debut] == '-')
			nb_signe = -1;
		nb_debut++;
	}
	while (str[nb_debut] >= '0' && str[nb_debut] <= '9')
	{
		nb = nb * 10 + str[nb_debut] - '0';
		nb_debut++;
	}
	return (nb * nb_signe);
}
