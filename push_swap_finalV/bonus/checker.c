/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaouni <aaouni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 01:16:03 by aaouni            #+#    #+#             */
/*   Updated: 2022/07/05 23:21:30 by aaouni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "getnl.h"

void	exit_error(void)
{
	ft_putstr("Error\n");
	exit (1);
}

void	ft_reapp_instruct(char *line, t_stack **stacka, t_stack **stackb)
{
	if (!ft_strcmp (line, "sa\n"))
		sa(*stacka);
	else if (!ft_strcmp (line, "sb\n"))
		sa(*stackb);
	else if (!ft_strcmp (line, "ss\n"))
		ss(*stacka, *stackb);
	else if (!ft_strcmp (line, "ra\n"))
		ra(stacka);
	else if (!ft_strcmp (line, "rb\n"))
		ra(stackb);
	else if (!ft_strcmp (line, "rr\n"))
		rr(stacka, stackb);
	else if (!ft_strcmp (line, "rra\n"))
		rra(stacka);
	else if (!ft_strcmp (line, "rrb\n"))
		rra(stackb);
	else if (!ft_strcmp (line, "rrr\n"))
		rrr(stacka, stackb);
	else if (!ft_strcmp (line, "pa\n"))
		pa(stacka, stackb, 1);
	else if (!ft_strcmp (line, "pb\n"))
		pa(stacka, stackb, 2);
	else
		exit_error();
}

int	ft_stack_issorted(t_stack *stacka)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (stacka->next)
	{
		if (stacka->content > stacka->next->content)
			return (0);
		stacka = stacka->next;
	}
	return (1);
}

t_stack	*ft_fill_stack1(int argc, char **argv)
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

int	main(int argc, char **argv)
{
	char	*line;
	t_stack	*a;
	t_stack	*b;

	if (argc >= 2)
	{
		if (!check_arg(argc, argv))
			exit_error();
		a = ft_fill_stack1(argc, argv);
		b = NULL;
		line = getnl(0);
		while (line)
		{
			ft_reapp_instruct(line, &a, &b);
			free(line);
			line = getnl(0);
		}
		free(line);
		if (ft_stack_issorted(a))
			ft_putstr("OK\n");
		else
			ft_putstr("KO\n");
	}
	return (0);
}
