/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rever.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 14:21:45 by cbustama          #+#    #+#             */
/*   Updated: 2022/02/08 17:25:36 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	strcmp(const char *x, const char *y)
{
	while (*x)
	{
		if (*x != *y)
			break ;
	x++;
	y++;
	}
	return (*(const unsigned char *)x - *(const unsigned char *)y);
}

static void	sw(int *a)
{
	int	tmp;

	tmp = *a;
	*a = tmp;
}

void	rever_items(int *items, size_t size)
{
	static size_t	i;

	i = 0;
	if (i < size)
	{
		sw(&items[size - 1]);
		rever_items(items, size - 1);
		i++;
	}
}

void	start_n(char *c, t_stack *a, t_stack *b, int n)
{
	if (n <= 0)
		return ;
	if (strcmp(c, "pb") == 0)
	{
		ft_pb_order(a, b);
		start_n(c, a, b, n - 1);
	}
	else if (strcmp(c, "rra") == 0)
	{
		ft_rra_order(a, 0);
		start_n(c, a, b, n - 1);
	}
	else if (strcmp(c, "ra") == 0)
	{
		ft_ra_order(a, 0);
		start_n(c, a, b, n - 1);
	}
}

void	start_b(char *c, t_stack *a, t_stack *b, int n)
{
	if (n <= 0)
		return ;
	if (strcmp(c, "rrb") == 0)
	{	
		ft_rrb_order(b, 0);
		start_n(c, a, b, n - 1);
	}
	else if (strcmp(c, "rb") == 0)
	{	
		ft_rb_order(b, 0);
		start_n(c, a, b, n - 1);
	}
}
