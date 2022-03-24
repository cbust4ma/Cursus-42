/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 16:09:36 by cbustama          #+#    #+#             */
/*   Updated: 2022/02/15 14:37:32 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../libft/libft.h"

int	*fill_stack(int n, char **s, t_stack *a)
{
	int	i;

	i = n;
	while (i > 0)
	{
		a->items[++a->top] = ft_error_atoi(s[i]);
		i--;
	}
	return (a->items);
}

int	*fill_parm(int i, char **str, t_stack *a)
{
	int	n;

	n = i - 1;
	while (n > -1)
	{
		a->items[++a->top] = ft_error_atoi(str[n]);
		n--;
	}
	return (a->items);
}

t_stack	*check_fill(char **args, t_stack *a, int *s)
{
	char	**str;
	int		i;

	i = 0;
	str = ft_split(args[1], 32);
	while (str[i])
		i++;
	s = fill_parm(i, str, a);
	if (!ft_rep(i, s))
		_write();
	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free (str);
	return (a);
}

t_stack	*go_st(int size, char **args)
{
	t_stack	*a;
	int		*s;

	s = NULL;
	if (size <= 0)
		return (0);
	a = newstack(512);
	if (ft_char(size, args))
	{
		if (size == 2)
			check_fill(args, a, s);
		if ((size - 1) > 1)
		{
			s = fill_stack((size - 1), args, a);
			if (!ft_rep((size - 1), s))
				_write();
		}
	}
	else
		_write();
	rever_items(a->items, a->top + 1);
	return (a);
}
