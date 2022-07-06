/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaouni <aaouni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 20:52:35 by aaouni            #+#    #+#             */
/*   Updated: 2022/07/06 00:03:12 by aaouni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_instructions_part2(int *array, int *biggest, int *smallest, int i)
{
	if (array[i] > biggest[1])
	{
		biggest[0] = i;
		biggest[1] = array[i];
	}
	if (array[i] < smallest[1])
	{
		smallest[0] = i;
		smallest[1] = array[i];
	}
}

int	find_instructions(int element, int *array, int size)
{
	int	i;
	int	biggest[2];
	int	smallest[2];

	biggest[0] = 0;
	biggest[1] = array[0];
	smallest[0] = 0;
	smallest[1] = array[0];
	if (element < array[0] && element > array[size - 1])
		return (0);
	i = 0;
	while (i + 1 < size)
	{
		if (isbetween(element, array[i], array[i + 1]))
		{
			return (sp(i + 1, size));
		}
		find_instructions_part2(array, biggest, smallest, i);
		i++;
	}
	if (element > biggest[1])
		return (biggest[0] + 1);
	if (element < smallest[1])
		return (smallest[0] + 1);
	return (0);
}

t_arr	*stack(t_stack **stack_a, t_stack **stack_b)
{
	t_arr	*s;

	s = malloc(sizeof(t_arr));
	if (!s)
		exit(1);
	s->arr_a = ft_list_to_array(*stack_a);
	s->arr_b = ft_list_to_array(*stack_b);
	s->size_a = ft_lstsize(*stack_a);
	s->size_b = ft_lstsize(*stack_b);
	return (s);
}

int	*find_best_element(t_stack **stack_a, t_stack **stack_b)
{
	t_arr	*s;
	int		*ins;
	int		i;

	i = 0;
	s = stack(stack_a, stack_b);
	ins = malloc(2 * sizeof(int));
	ins[0] = find_instructions(s->arr_b[0], s->arr_a, s->size_a);
	ins[1] = 0;
	while (i < s->size_b)
	{
		if ((ft_abs(ins[0]) + ft_abs(ins[1])
				> (ft_abs(find_instructions(s->arr_b[i], s->arr_a, s->size_a))
					+ ft_abs(sp(i, s->size_b)))))
		{
			ins[0] = find_instructions(s->arr_b[i], s->arr_a, s->size_a);
			ins[1] = sp(i, s->size_b);
		}
		i++;
	}
	free(s->arr_a);
	free(s->arr_b);
	free(s);
	return (ins);
}

void	ft_big_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	*ins;

	while (*stack_b)
	{
		ins = find_best_element(stack_a, stack_b);
		ft_push_all(stack_a, stack_b, ins);
		free(ins);
	}
}
