/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mysort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:03:35 by cbustama          #+#    #+#             */
/*   Updated: 2022/02/15 14:43:07 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	order_tri(t_stack *a)
{
	int	*arr;

	arr = a->items;
	if (arr[0] > arr[1] && arr[1] < arr[2] && arr[2] < arr[0])
		ft_sa_order(a, 0);
	else if (arr[0] < arr[1] && arr[1] < arr[2] && arr[2] > arr[0])
	{
		ft_sa_order(a, 0);
		ft_rra_order(a, 0);
	}
	else if (arr[0] > arr[1] && arr[1] < arr[2] && arr[2] > arr[0])
		ft_ra_order(a, 0);
	else if (arr[0] < arr[1] && arr[1] > arr[2] && arr[2] < arr[0])
	{
		ft_sa_order(a, 0);
		ft_ra_order(a, 0);
	}
	else if (arr[0] < arr[1] && arr[1] > arr[2] && arr[2] > arr[0])
		ft_rra_order(a, 0);
}

void	rotate_a(t_stack *a, int n)
{
	int	find;

	find = a->top;
	while (find >= 0 && a->items[find] != n)
		find--;
	if (find < 0)
		return ;
	else if (find < a->top / 2)
		start_n("rra", a, NULL, find + 1);
	else
		start_n("ra", a, NULL, a->top - find);
}

void	top_position(t_stack *a, t_stack *b)
{
	int	top_b;
	int	move;

	top_b = b->items[b->top];
	move = ft_above(a, top_b);
	if (move == top_b)
		move = min(a);
	rotate_a(a, move);
	ft_pa_order(a, b);
}

static void	sort_tri_advance(t_stack *a, t_stack *b)
{
	start_n("pb", a, b, a->top - 2);
	order_tri(a);
	while (b->top >= 0)
		top_position(a, b);
	rotate_a(a, 0);
}

void	order_small(t_stack *a, t_stack *b)
{	
	if (a->top == 1)
		ft_sa_order(a, 0);
	else if (a->top == 2)
		order_tri(a);
	else
		sort_tri_advance(a, b);
}
