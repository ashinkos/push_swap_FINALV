/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaouni <aaouni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 21:59:17 by aaouni            #+#    #+#             */
/*   Updated: 2022/07/06 00:06:50 by aaouni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_a_5(t_stack **stack_a, t_stack **stack_b, int *ins)
{
	int	i;

	i = 0;
	while (i < ft_abs(ins[0]))
	{
		rra(stack_a, 1);
		i++;
	}
	i = 0;
	while (i < ins[1])
	{
		ra(stack_b, 2);
		i++;
	}
}

void	ft_push_all(t_stack **stack_a, t_stack **stack_b, int *ins)
{
	if (ins[0] >= 0 && ins[1] >= 0)
	{
		if (ins[0] >= ins[1])
			ft_push_a(stack_a, stack_b, ins);
		else
			ft_push_a_1(stack_a, stack_b, ins);
	}
	else if (ins[0] < 0 && ins[1] < 0)
	{
		if (ft_abs(ins[0]) >= ft_abs(ins[1]))
			ft_push_a_2(stack_a, stack_b, ins);
		else
			ft_push_a_3(stack_a, stack_b, ins);
	}
	else if (ins[0] >= 0 && ins[1] < 0)
		ft_push_a_4(stack_a, stack_b, ins);
	else if (ins[0] < 0 && ins[1] >= 0)
		ft_push_a_5(stack_a, stack_b, ins);
	pa(stack_a, stack_b, 1);
}
