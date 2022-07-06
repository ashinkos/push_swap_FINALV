/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaouni <aaouni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 01:09:58 by aaouni            #+#    #+#             */
/*   Updated: 2022/07/06 00:09:52 by aaouni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sorting_3(t_stack **stacka)
{
	int	first;
	int	second;
	int	third;

	first = (*stacka)->content;
	second = (*stacka)->next->content;
	third = (*stacka)->next->next->content;
	if (first > second && first < third)
		sa(*stacka, 1);
	if (first > second && second > third)
	{
		sa(*stacka, 1);
		rra(stacka, 1);
	}
	if (first > third && second < third)
		ra(stacka, 1);
	if (first < third && second > third)
	{
		sa(*stacka, 1);
		ra(stacka, 1);
	}
	if (first < second && first > third)
		rra(stacka, 1);
}

void	ft_sorting_2(t_stack **stacka)
{
	if ((*stacka)->content > (*stacka)->next->content)
		sa(*stacka, 1);
}

void	ft_sorting_4_5(t_stack **stacka, t_stack **stackb)
{
	int	i;
	int	len;
	int	index;

	i = 0;
	len = ft_lstsize(*stacka);
	while (i < len - 3)
	{
		index = ft_check_min(*stacka);
		if (index < ft_lstsize(*stacka) / 2)
			while (index--)
				ra(stacka, 1);
		else
			while (ft_lstsize(*stacka) - index++)
				rra(stacka, 1);
		pa(stacka, stackb, 2);
		i++;
	}
	ft_sorting_3(stacka);
	pa(stacka, stackb, 1);
	if (*stackb)
		pa(stacka, stackb, 1);
}
