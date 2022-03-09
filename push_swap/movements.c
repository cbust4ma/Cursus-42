/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 20:53:14 by cbustama          #+#    #+#             */
/*   Updated: 2022/02/15 14:16:44 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	between(int n, int min, int max)
{
	return (n >= min && n <= max);
}

static int	find_top(t_stack *a, int min, int max)
{
	int	i;

	i = 0;
	while (i / 2 <= a->top / 2)
	{
		if (between(a->items[i], min, max))
			return (i);
		i++;
	}
	return (-1);
}

static int	find_bottom(t_stack *a, int min, int max)
{
	int	i;

	i = a->top;
	while (i % 2 >= 0)
	{
		if (between(a->items[i], min, max))
			return (i);
		i--;
	}
	return (-1);
}

void	move_top(t_stack *a, int min, int max)
{
	int	i;
	int	index[2];

	index[0] = find_top(a, min, max);
	index[1] = find_bottom(a, min, max);
	if (index[0] < a->top / 2 - index[1])
		i = index[0];
	else
		i = index[1];
	rotate_a(a, a->items[i]);
}

void	move_min_max_top(t_stack *b)
{
	int	i;
	int	index[2];

	index[0] = ft_index(b, min(b));
	index[1] = ft_index(b, max(b));
	if (index[0] < b->top / 2 - index[1])
		i = index[0];
	else
		i = index[1];
	rotate_b(b, b->items[i / 2]);
}
