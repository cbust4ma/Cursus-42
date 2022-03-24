/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 17:51:42 by cbustama          #+#    #+#             */
/*   Updated: 2022/02/08 18:08:12 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	_write(void)
{
	write(1, "Error\n", 6);
	exit (0);
}

void	free_stack(t_stack *a)
{
	free (a->items);
	free (a);
}

void	ft_sort(t_stack *a)
{
	t_stack	*b;

	if (order_now(a) || a->top <= 0)
		return ;
	b = newstack(a->maxsize);
	if (a->top < 5)
		order_small(a, b);
	else
		sort_magic(a, b);
	free_stack(b);
}

int	main(int argc, char *argv[])
{
	t_stack	*a;

	a = go_st(argc, &argv[0]);
	index_s(&a);
	ft_sort(a);
	free_stack(a);
	return (0);
}
