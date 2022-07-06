/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaouni <aaouni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 22:45:05 by aaouni            #+#    #+#             */
/*   Updated: 2022/07/06 01:26:00 by aaouni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_fill_stack(int argc, char **argv)
{
	int			i;
	t_stack		*a;
	t_stack		*new_elet;

	i = 1;
	a = ft_lstnew(ft_atoi(argv[i]), 0);
	while (++i < argc)
	{
		new_elet = ft_lstnew(ft_atoi(argv[i]), 0);
		ft_lstadd_back(&a, new_elet);
	}
	return (a);
}

void	exit_error(void)
{
	ft_putstr("Error\n");
	exit (1);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc >= 2)
	{
		if (!check_arg(argc, argv))
			exit_error();
		if (!ft_issorted(argc, argv))
			return (0);
		a = ft_fill_stack(argc, argv);
		b = NULL;
		if (argc == 3)
			ft_sorting_2(&a);
		if (argc == 4)
			ft_sorting_3(&a);
		if (argc == 5 || argc == 6)
			ft_sorting_4_5(&a, &b);
		if (argc > 6)
		{
			ft_list(&a, &b);
			ft_big_sort(&a, &b);
			ft_first_stack_min(&a);
		}
	}
	return (0);
}
