/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_lis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaouni <aaouni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 01:06:01 by aaouni            #+#    #+#             */
/*   Updated: 2022/07/06 00:39:02 by aaouni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*alloc_and_fill_lis(t_stack *stack_a)
{
	int		*lis;
	int		i;

	lis = malloc(sizeof(int) * ft_lstsize(stack_a));
	if (!lis)
		return (NULL);
	i = 0;
	while (i < ft_lstsize(stack_a))
	{
		lis[i] = 1;
		i++;
	}
	return (lis);
}

int	*ft_lis(t_stack *stack_a)
{
	t_stack		*head;
	t_stack		*next_one;
	t_compt		v;	
	int			*lis;

	head = stack_a;
	lis = alloc_and_fill_lis(stack_a);
	v.i = 0;
	while (head)
	{
		v.j = v.i + 1;
		next_one = head->next;
		while (next_one)
		{
			if (next_one->content > head->content && lis[v.j] < lis[v.i] + 1)
				lis[v.j] += 1;
			v.j++;
			next_one = next_one->next;
		}
		head = head->next;
		v.i++;
	}
	free(head);
	free(next_one);
	return (lis);
}

int	*ft_index(int index, t_stack **stack_a, t_len *len)
{
	int				max;
	int				*arr;
	int				*lis;
	int				*stack;

	lis = ft_lis(*stack_a);
	max = lis[index];
	stack = ft_list_to_array(*stack_a);
	arr = malloc(sizeof(int) * max);
	if (!arr)
		return (NULL);
	len->len = 0;
	while (index >= 0)
	{
		if (lis[index] == max)
		{
			arr[len->len] = stack[index];
			max--;
			len->len++;
		}
		index--;
	}
	free (lis);
	free (stack);
	return (arr);
}
