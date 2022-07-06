/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaouni <aaouni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 18:35:57 by aaouni            #+#    #+#             */
/*   Updated: 2022/07/06 00:36:37 by aaouni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_stack
{
	int				content;
	int				index;
	struct s_stack	*next;
}					t_stack;

typedef struct s_arr
{
	int	*arr_a;
	int	*arr_b;
	int	size_a;
	int	size_b;
}					t_arr;

typedef struct s_len
{
	int		len;
}					t_len;

typedef struct s_compt
{
	int	i;
	int	j;	
}					t_compt;

t_stack	*ft_lstnew(int content, int index);
t_stack	*ft_lstlast(t_stack *lst);
void	ft_lstadd_front(t_stack **alst, t_stack *new);
void	ft_lstadd_back(t_stack **alst, t_stack *new);
int		ft_lstsize(t_stack *lst);
int		ft_atoi(const char *str);
void	ft_putchar(char c);
void	ft_putstr(char *s);
int		ft_isdigit(int c);
t_stack	*ft_fill_stack(int argc, char **argv);
int		check_digit(int argc, char **argv);
int		check_limits(char *str, char signe);
int		is_integer(char *str);
int		check_arg(int argc, char **argv);
int		ft_strlen(const char *s);
int		ft_strcmp(const char *s1, const char *s2);
void	ft_putstr(char *s);
int		check_digit(int argc, char **argv);
int		check_limits(char *str, char signe);
int		is_integer(char *str);
int		check_arg(int argc, char **argv);
int		ft_issorted(int argc, char **argv);
void	ft_sorting_3(t_stack **stacka);
int		*ft_list_to_array(t_stack *a);
void	ft_sorting_array(int **str, int len);
void	ft_indexing(t_stack **a, int *arr);
void	ft_sorting_4_5(t_stack **stacka, t_stack **stackb);
int		ft_check_min(t_stack *stacka);
void	ft_sorting_2(t_stack **stacka);
void	ft_bigsort(t_stack **stacka, t_stack **stackb);
int		ft_check_min_arr(int *arr, int len);
void	ft_first_stack_min(t_stack **stacka);
void	ft_push_all(t_stack **stack_a, t_stack **stack_b, int *ins);
void	ft_big_sort(t_stack **stack_a, t_stack **stack_b);
int		isbetween(int number, int a, int b);
int		ft_abs(int a);
int		sp(int index, int len);
int		*ft_lis(t_stack *stack_a);
void	ft_list(t_stack **stacka, t_stack **stackb);

void	ft_push_a(t_stack **stack_a, t_stack **stack_b, int *ins);
void	ft_push_a_1(t_stack **stack_a, t_stack **stack_b, int *ins);
void	ft_push_a_2(t_stack **stack_a, t_stack **stack_b, int *ins);
void	ft_push_a_3(t_stack **stack_a, t_stack **stack_b, int *ins);
void	ft_push_a_4(t_stack **stack_a, t_stack **stack_b, int *ins);
void	ft_push_a_5(t_stack **stack_a, t_stack **stack_b, int *ins);

int		find_max_lis(t_stack **stack_a);
int		*ft_index(int index, t_stack **stack_a, t_len *len);

void	sa(t_stack *stacka, int index);
void	ss(t_stack *stacka, t_stack *stackb);
void	pa(t_stack **stacka, t_stack **stackb, int index);
void	ra(t_stack **stacka, int index);
void	rr(t_stack **stacka, t_stack **stackb);
void	rra(t_stack **stacka, int index);
void	rrr(t_stack **stacka, t_stack **stackb);

#endif