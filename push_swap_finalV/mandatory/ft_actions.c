/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaouni <aaouni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 18:35:50 by aaouni            #+#    #+#             */
/*   Updated: 2022/07/06 00:32:38 by aaouni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *stacka, int index)
{
	int	t;

	if (ft_lstsize(stacka) < 2)
		return ;
	else
	{
		t = stacka->content;
		stacka->content = stacka->next->content;
		stacka->next->content = t;
		t = stacka->index;
		stacka->index = stacka->next->index;
		stacka->next->index = t;
	}
	if (index == 1)
		ft_putstr("sa\n");
	else
		ft_putstr("sb\n");
}

void	pa(t_stack **stacka, t_stack **stackb, int index)
{
	t_stack	*head;
	int		tmp;

	if (index == 2)
	{
		head = *stacka;
		tmp = (*stacka)->content;
		(*stacka) = (*stacka)->next;
		ft_lstadd_front(stackb, ft_lstnew(tmp, 1));
		free (head);
	}
	else
	{
		if (!stackb)
			return ;
		head = *stackb;
		tmp = (*stackb)->content;
		(*stackb) = (*stackb)->next;
		ft_lstadd_front(stacka, ft_lstnew(tmp, 1));
		free (head);
	}
	if (index == 1)
		ft_putstr("pa\n");
	else
		ft_putstr("pb\n");
}

void	ra(t_stack **stacka, int index)
{
	t_stack	*first;
	t_stack	*last;

	if (ft_lstsize(*stacka) <= 1)
		return ;
	first = ft_lstnew((*stacka)->content, 1);
	last = (*stacka);
	(*stacka) = (*stacka)->next;
	ft_lstadd_back(stacka, first);
	free (last);
	if (index == 1)
		ft_putstr("ra\n");
	else if (index == 2)
		ft_putstr("rb\n");
}

void	rra(t_stack **stacka, int index)
{
	t_stack	*last;
	t_stack	*new_last;
	int		tmp;

	last = *stacka;
	new_last = *stacka;
	while (last->next)
	{
		new_last = last;
		last = last->next;
	}
	new_last->next = NULL;
	tmp = last->content;
	ft_lstadd_front(stacka, ft_lstnew(tmp, 1));
	if (index == 1)
		ft_putstr("rra\n");
	else if (index == 2)
		ft_putstr("rrb\n");
	free(last);
}
