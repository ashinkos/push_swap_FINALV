/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_push_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaouni <aaouni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 18:49:23 by aaouni            #+#    #+#             */
/*   Updated: 2022/07/06 00:29:06 by aaouni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	ft_push_a(t_stack **stack_a, t_stack **stack_b, int *ins)
{
	int	i;

	i = 0;
	while (i < ins[1])
	{
		rr(stack_a, stack_b);
		i++;
	}
	i = 0;
	while (i < ins[0] - ins[1])
	{
		ra(stack_a, 1);
		i++;
	}
}

void	ft_push_a_1(t_stack **stack_a, t_stack **stack_b, int *ins)
{
	int	i;

	i = 0;
	while (i < ins[0])
	{
		rr(stack_a, stack_b);
		i++;
	}
	i = 0;
	while (i < ins[1] - ins[0])
	{
		ra(stack_b, 2);
		i++;
	}
}

void	ft_push_a_2(t_stack **stack_a, t_stack **stack_b, int *ins)
{
	int	i;

	i = 0;
	while (i < ft_abs(ins[1]))
	{
		rrr(stack_a, stack_b);
		i++;
	}
	i = 0;
	while (i < ft_abs(ins[0]) - ft_abs(ins[1]))
	{
		rra(stack_a, 1);
		i++;
	}
}

void	ft_push_a_3(t_stack **stack_a, t_stack **stack_b, int *ins)
{
	int	i;

	i = 0;
	while (i < ft_abs(ins[0]))
	{
		rrr(stack_a, stack_b);
		i++;
	}
	i = 0;
	while (i < ft_abs(ins[1]) - ft_abs(ins[0]))
	{
		rra(stack_b, 2);
		i++;
	}
}

void	ft_push_a_4(t_stack **stack_a, t_stack **stack_b, int *ins)
{
	int	i;

	i = 0;
	while (i < ins[0])
	{
		ra(stack_a, 1);
		i++;
	}
	i = 0;
	while (i < ft_abs(ins[1]))
	{
		rra(stack_b, 2);
		i++;
	}
}
