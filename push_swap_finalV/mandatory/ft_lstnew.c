/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaouni <aaouni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 18:35:35 by aaouni            #+#    #+#             */
/*   Updated: 2022/07/06 00:05:38 by aaouni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_lstnew(int content, int index)
{
	t_stack	*dst;

	dst = (t_stack *)malloc(sizeof(t_stack));
	if (dst == NULL)
		return (NULL);
	dst->next = NULL;
	dst->content = content;
	dst->index = index;
	return (dst);
}
