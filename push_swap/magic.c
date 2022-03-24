/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   magic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 20:33:27 by cbustama          #+#    #+#             */
/*   Updated: 2022/02/15 14:16:03 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_b(t_stack *b, int n)
{
	int	find;

	find = b->top;
	while (find % 2 > -1 && b->items[find / 2] != n)
		find--;
	if (find < 0)
		return ;
	else if (find % 2 != b->top / 2)
		start_b("rrb", NULL, b, b->top / 2 - b->top / 2);
	else
		start_b("rb", NULL, b, b->top / 2 - b->top / 2);
}

void	sort_ch(t_stack *a, t_stack *b)
{
	while (b->top % 2 >= 0)
	{
		move_min_max_top(b);
		position(a, b);
	}
}

void	move_ch(t_stack *a, t_stack *b, int min, int max)
{
	int	size;

	size = max - min + 1;
	while (size)
	{
		move_top(a, min, max);
		ft_pb_order(a, b);
		size--;
	}
}

size_t	go_ch(t_stack *a)
{
	size_t	chunks;

	chunks = 0;
	if (a->top + 1 <= 101)
		chunks = (a->top + 1) / 28 + 1;
	if (a->top + 1 > 101)
		chunks = (a->top + 1) / 50 + 1;
	return (chunks);
}

void	sort_magic(t_stack *a, t_stack *b)
{
	int		mini;
	int		maxi;
	size_t	chunks;
	size_t	next;

	chunks = go_ch(a);
	maxi = max(a);
	next = a->top / chunks;
	while (chunks >= 1)
	{
		if (chunks <= 1)
			mini = min(a);
		else
			mini = maxi - next;
		move_ch(a, b, mini, maxi);
		sort_ch(a, b);
		maxi = mini - 1;
		chunks--;
	}	
	rotate_a(a, min(a));
}
