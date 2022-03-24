/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 18:54:28 by cbustama          #+#    #+#             */
/*   Updated: 2022/03/22 18:38:19 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	enemy_put(t_data *l)
{
	int	c;

	c = 0;
	l->j = 0;
	while (l->line[l->j])
	{
		l->i = 0;
		while (l->line[l->j][l->i])
		{
			if (l->line[l->j][l->i] == 'K')
			{
				_ground(*l);
				c++;
			}
			if (l->line[l->j][l->i] == 'K')
				put_enemy(l);
			l->i++;
		}
		l->j++;
	}
	if (c == 0)
		_write(9);
}

void	put_enemy(t_data *l)
{
	l->enemy.x = l->i;
	l->enemy.y = l->j;
	if (l->enemy.count == 8)
	{
		l->enemy.count = 0;
	}
	mlx_put_image_to_window(l->p_, l->win, l->enemy.s[l->enemy.count], \
	l->i * N, l->j * N);
}
