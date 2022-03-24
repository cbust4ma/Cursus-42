/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 19:02:34 by cbustama          #+#    #+#             */
/*   Updated: 2022/02/08 17:39:25 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa_order(t_stack *a, int n)
{
	int	tmp;

	if (a->top <= 0)
		return ;
	tmp = a->items[a->top];
	a->items[a->top] = a->items[a->top - 1];
	a->items[a->top - 1] = tmp;
	if (n == 0)
		write(1, "sa\n", 3);
}

void	ft_pa_order(t_stack *a, t_stack *b)
{
	if (b->top == -1)
		return ;
	a->items[++a->top] = b->items[b->top--];
	write(1, "pa\n", 3);
}

void	ft_pb_order(t_stack *a, t_stack *b)
{
	if (a->top == -1)
		return ;
	b->items[++b->top] = a->items[a->top--];
	write(1, "pb\n", 3);
}

void	ft_ra_order(t_stack *a, int n)
{
	unsigned int	i;
	int				tmp;

	i = a->top + 1;
	tmp = a->items[a->top];
	while (--i)
		a->items[i] = a->items[i - 1];
	a->items[0] = tmp;
	if (n == 0)
		write (1, "ra\n", 3);
}

void	ft_rb_order(t_stack *a, int n)
{
	unsigned int	i;
	int				tmp;

	i = a->top + 1;
	tmp = a->items[a->top];
	while (--i)
		a->items[i] = a->items[i - 1];
	a->items[0] = tmp;
	if (n == 0)
		write (1, "rb\n", 3);
}
