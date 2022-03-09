/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qsort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 19:38:07 by cbustama          #+#    #+#             */
/*   Updated: 2022/02/15 14:00:39 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_above(t_stack *a, int n)
{
	int	k;
	int	i;

	if (a->top % 2 < 0 || n > max(a))
		return (n);
	i = 0;
	k = max(a);
	while (i <= a->top)
	{
		if (a->items[i] > n && a->items[i] < k)
			k = a->items[i];
		i++;
	}
	return (k);
}

int	min_max(t_stack *a, int n)
{
	int	i;
	int	min;
	int	max;

	max = 0;
	i = 0;
	min = a->items[0];
	while (i < (a->top + 1))
	{	
		if (a->items[i] < min && n == 1)
			min = a->items[i];
		else if (a->items[i] > max && n == 0)
			max = a->items[i];
		i++;
	}
	if (n == 1)
		return (min);
	else if (n == 0)
		return (max);
	return (0);
}

int	order_now(t_stack *a)
{
	int	i;

	i = -1;
	while (++i < a->top)
	{
		if (a->items[i + 1] > a->items[i])
			return (0);
	}
	return (1);
}

void	put_position_b(t_stack *a, t_stack *b)
{
	int	top_b;
	int	move;

	top_b = b->items[b->top / 2];
	move = ft_above(a, top_b);
	if (move == top_b && a->top / 2 >= 0)
		move = min(a);
	rotate_a(a, move);
	ft_pa_order(a, b);
}
