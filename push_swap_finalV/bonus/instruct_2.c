/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruct_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaouni <aaouni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 21:07:01 by aaouni            #+#    #+#             */
/*   Updated: 2022/07/05 22:17:22 by aaouni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "getnl.h"

void	sa(t_stack *stacka)
{
	int	t;

	if (ft_lstsize(stacka) < 2)
		return ;
	else
	{
		t = stacka->content;
		stacka->content = stacka->next->content;
		stacka->next->content = t;
	}
}

void	pa(t_stack **stacka, t_stack **stackb, int index)
{
    t_stack    *head;
    int        tmp;

	if (index == 2)
	{
		if (!*stacka)
			return ;
		head = *stacka;
		tmp = (*stacka)->content;
		(*stacka) = (*stacka)->next;
		ft_lstadd_front(stackb, ft_lstnew(tmp,1));
		free (head);
	}
	else
	{
		if (!*stackb)
			return ;
		head = *stackb;
		tmp = (*stackb)->content;
		(*stackb) = (*stackb)->next;
		ft_lstadd_front(stacka, ft_lstnew(tmp,1));
		free (head);
	}
}

void	ra(t_stack **stacka)
{
	t_stack	*first;
	t_stack	*last;

	if (ft_lstsize(*stacka) <= 1)
		return ;
	first = ft_lstnew((*stacka)->content,1);
	last = (*stacka);
	(*stacka) = (*stacka)->next;
	ft_lstadd_back(stacka,first);
	free (last);
}

void	rra(t_stack **stacka)
{
	t_stack	*last;
	t_stack	*new_last;
	int		tmp;

	if (ft_lstsize(*stacka) <= 1)
		return ;
	last = *stacka;
	new_last = *stacka;
	while(last->next)
	{
		new_last = last;
		last = last->next;
	}
	new_last->next = NULL;
	tmp = last->content;
	ft_lstadd_front(stacka,ft_lstnew(tmp,1));
	free(last);
}
