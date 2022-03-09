/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isnumber.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 14:24:49 by cbustama          #+#    #+#             */
/*   Updated: 2022/02/15 14:40:56 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "push_swap.h"

int	ft_char(int n, char **str)
{
	int	i;
	int	j;

	i = 1;
	while (i < n)
	{
		j = 0;
		while (str[i][j])
		{
			if ((str[i][j] >= 48 && str[i][j] <= 57) || (str[i][j] == ' ')
				|| (str[i][j] == '-'))
				j++;
			else
				return (0);
		}
		i++;
	}
	return (1);
}

int	ft_rep(int n, int *stack)
{
	int		i;
	int		j;

	i = 0;
	while (i < n)
	{
		j = i + 1;
		while (j < n)
		{
			if (stack[i] == stack[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
