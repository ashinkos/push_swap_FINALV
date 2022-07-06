/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_actions_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaouni <aaouni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 18:56:05 by aaouni            #+#    #+#             */
/*   Updated: 2022/07/05 23:26:47 by aaouni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_min(t_stack *stacka)
{
	int		i;
	t_stack	*tmp;
	int		min;
	int		index;

	tmp = stacka;
	i = 0;
	index = 0;
	min = tmp->content;
	while (tmp)
	{
		if (min > tmp->content)
		{
			min = tmp->content;
			index = i;
		}
		tmp = tmp->next;
		i++;
	}
	free(tmp);
	return (index);
}

void	ft_first_stack_min(t_stack **stacka)
{
	int	index;

	index = ft_check_min(*stacka);
	if (index < ft_lstsize(*stacka) / 2)
	{
		while (index != 0)
		{
			ra(stacka, 1);
			index--;
		}
	}
	else
	{
		while (ft_lstsize(*stacka) - index)
		{
			rra(stacka, 1);
			index++;
		}
	}
}

int	isbetween(int number, int a, int b)
{
	if (number > a && number < b)
		return (1);
	return (0);
}

int	ft_abs(int a)
{
	if (a < 0)
		return (a * -1);
	return (a);
}

int	sp(int index, int len)
{
	if (index > len / 2)
		return ((len - index) * -1);
	return (index);
}
