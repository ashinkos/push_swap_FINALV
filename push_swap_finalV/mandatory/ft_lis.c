/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaouni <aaouni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 19:49:47 by aaouni            #+#    #+#             */
/*   Updated: 2022/07/06 00:08:46 by aaouni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find(int *stack_arr, int *content_lis, int len)
{
	int	j;

	j = 0;
	while (j < len)
	{
		if (stack_arr[0] == content_lis[j])
			return (1);
		j++;
	}
	return (-1);
}

void	rotate_push(t_stack **stacka, t_stack **stackb,
	int *content_lis, int len)
{
	int	*stack_arr;
	int	i;
	int	f;

	i = ft_lstsize(*stacka);
	while (i > 0)
	{
		stack_arr = ft_list_to_array(*stacka);
		f = find(stack_arr, content_lis, len);
		if (f == -1)
			pa(stacka, stackb, 2);
		else
			ra(stacka, 1);
		free(stack_arr);
		i--;
	}
}

int	find_max_lis(t_stack **stack_a)
{
	int		max;
	int		i;
	int		index;
	int		*lis;

	i = 0;
	lis = ft_lis(*stack_a);
	max = 0;
	while (i < ft_lstsize(*stack_a))
	{
		if (max < lis[i])
		{
			max = lis[i];
			index = i;
		}
		i++;
	}
	free (lis);
	return (index);
}

void	ft_list(t_stack **stacka, t_stack **stackb)
{
	int		*arr_lis;
	t_len	*len;

	len = malloc(sizeof(t_len));
	ft_first_stack_min(stacka);
	arr_lis = ft_index(find_max_lis(stacka), stacka, len);
	rotate_push(stacka, stackb, arr_lis, len->len);
	free(len);
	free(arr_lis);
	return ;
}
