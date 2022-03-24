/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   continue_map_error_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:12:28 by cbustama          #+#    #+#             */
/*   Updated: 2022/03/22 20:41:23 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	continue_error_two(t_data *l)
{
	if (l->out == 0)
		_write(7);
}

void	continue_error_three(t_data *l)
{
	int	count;

	l->j = 0;
	count = 0;
	while (l->line[l->j])
	{
		l->i = 0;
		while (l->line[l->j][l->i] != '\0')
		{
			if (l->line[l->j][l->i] == 'E')
				count++;
			l->i++;
		}
	l->j++;
	}
	if (count == 0)
		_write(8);
}

void	_error_two(t_data *l)
{
	continue_error_two(l);
	continue_error_three(l);
	continue_error(l);
}
