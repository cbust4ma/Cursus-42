/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 18:39:24 by cbustama          #+#    #+#             */
/*   Updated: 2022/02/04 13:57:34 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*newstack(int capacity)
{
	t_stack	*pt;

	pt = (t_stack *)malloc(sizeof(t_stack));
	if (!pt)
		return (NULL);
	pt->items = (int *)malloc(sizeof(int) * capacity);
	if (!(pt->items))
		return (NULL);
	pt->maxsize = capacity;
	pt->top = -1;
	return (pt);
}

void	ft_rra_order(t_stack *a, int n)
{
	int	i;
	int	tmp;

	i = -1;
	tmp = a->items[0];
	while (++i < a->top)
		a->items[i] = a->items[i + 1];
	a->items[a->top] = tmp;
	if (n == 0)
		write (1, "rra\n", 4);
}

void	ft_rrb_order(t_stack *a, int n)
{
	int	i;
	int	tmp;

	i = -1;
	tmp = a->items[0];
	while (++i < a->top)
		a->items[i] = a->items[i + 1];
	a->items[a->top] = tmp;
	if (n == 0)
		write (1, "rrb\n", 4);
}
