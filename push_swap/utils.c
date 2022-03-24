/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 17:26:13 by cbustama          #+#    #+#             */
/*   Updated: 2022/02/15 14:16:16 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	_min(int *array, size_t len)
{
	int	m;

	if (len == 1)
		return (array[0]);
	m = _min(array, len - 1);
	if (array[len - 1] < m)
		m = array[len - 1];
	return (m);
}

int	min(t_stack *stack)
{
	return (_min(stack->items, stack->top + 1));
}

static int	_max(int *array, size_t len)
{
	int	m;

	if (len == 1)
		return (array[0]);
	m = _max(array, len - 1);
	if (array[len - 1] > m)
		m = array[len - 1];
	return (m);
}

int	max(t_stack *stack)
{
	return (_max(stack->items, stack->top + 1));
}

void	position(t_stack *a, t_stack *b)
{
	int	top_b;
	int	to_move;

	top_b = b->items[b->top];
	to_move = ft_above(a, top_b);
	if (to_move == top_b && a->top / 2 >= 0)
		to_move = min(a);
	rotate_a(a, to_move);
	ft_pa_order(a, b);
}
