/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_actions_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaouni <aaouni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 14:07:42 by aaouni            #+#    #+#             */
/*   Updated: 2022/07/05 23:24:19 by aaouni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_stack **stacka, t_stack **stackb)
{
	ra(stacka, 0);
	ra(stackb, 0);
	ft_putstr("rr\n");
}

void	rrr(t_stack **stacka, t_stack **stackb)
{
	rra(stacka, 0);
	rra(stackb, 0);
	ft_putstr("rrr\n");
}

void	ss(t_stack *stacka, t_stack *stackb)
{
	sa(stacka, 0);
	sa(stackb, 0);
	ft_putstr("ss\n");
}

int	*ft_list_to_array(t_stack *a)
{
	int		*dst;
	int		len;
	int		i;
	t_stack	*tmp;

	tmp = a;
	i = 0;
	len = ft_lstsize(a);
	dst = (int *)malloc(sizeof(int) * len);
	if (!dst)
		return (NULL);
	while (tmp)
	{
		dst[i] = tmp->content;
		tmp = tmp->next;
		i++;
	}
	return (dst);
}

void	ft_sorting_array(int **str, int len)
{
	int		i;
	int		temp;
	int		*t;

	i = 0;
	t = *str;
	while (i < len - 1)
	{
		if (t[i] > t[i + 1])
		{				
			temp = t[i];
			t[i] = t[i + 1];
			t[i + 1] = temp;
			i = 0;
		}
		else
			i++;
	}
}
