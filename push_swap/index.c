/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 13:04:46 by cbustama          #+#    #+#             */
/*   Updated: 2022/02/15 14:50:09 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	in_sort(int a[], size_t size)
{
	int				i;
	unsigned int	j;
	int				key;

	j = 1;
	while (j < size)
	{
		i = j - 1;
		key = a[j++];
		while (i >= 0 && a[i + 1] < a[i])
		{
			a[i + 1] = a[i];
			a[i--] = key;
		}
	}
}

static int	*sorted_copy(t_stack *a)
{
	int		*copy;
	size_t	size;

	size = a->top + 1;
	copy = malloc(size * sizeof(*copy));
	ft_memcpy(copy, a->items, size * sizeof(*copy));
	in_sort(copy, size);
	return (copy);
}

void	index_s(t_stack **a)
{
	int		*copy;
	int		i;
	size_t	pos;
	int		*items;

	i = 0;
	items = ft_calloc((*a)->top + 1, sizeof(*items));
	copy = sorted_copy(*a);
	while (i <= (*a)->top)
	{
		pos = 0;
		while (copy[pos] != (*a)->items[i])
			pos++;
		items[i++] = pos;
	}
	ft_memcpy((*a)->items, items, ((*a)->top + 1) * sizeof(*items));
	free(copy);
	free(items);
}

int	ft_index(t_stack *a, int n)
{
	int	i;

	i = a->top;
	while (a->items[i / 2] != n && i >= 0)
		i--;
	return (i);
}
