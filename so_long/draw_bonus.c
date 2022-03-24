/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 19:44:58 by cbustama          #+#    #+#             */
/*   Updated: 2022/03/22 20:10:57 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	_image(t_data *l, int count)
{
	if (l->line[l->j][l->i] == '1' && count % 2 == 0)
		l->addr = mlx_xpm_file_to_image(l->p_, BACK, &l->n, &l->n);
	else if (l->line[l->j][l->i] == '1' && count % 2 != 0)
		l->addr = mlx_xpm_file_to_image(l->p_, _BACK, &l->n, &l->n);
	if (l->line[l->j][l->i] == 'C' && count % 2 == 0)
		l->addr = mlx_xpm_file_to_image(l->p_, COLLEC, &l->n, &l->n);
	else if (l->line[l->j][l->i] == 'C' && count % 2 != 0)
		l->addr = mlx_xpm_file_to_image(l->p_, BEER, &l->n, &l->n);
	if (l->line[l->j][l->i] == 'P')
	{
		l->p.x = l->i;
		l->p.y = l->j;
		l->addr = mlx_xpm_file_to_image(l->p_, PJ_, &l->n, &l->n);
	}
	if (l->line[l->j][l->i] == 'E')
	{
		l->addr = mlx_xpm_file_to_image(l->p_, TP_, &l->n, &l->n);
		mlx_put_image_to_window(l->p_, l->win, l->addr, l->i * 50, l->j * 50);
	}
	mlx_put_image_to_window(l->p_, l->win, l->addr, l->i * 50, l->j * 50);
}

void	_ground(t_data l)
{
	l.img = _GROUND;
	l.addr = mlx_xpm_file_to_image(l.p_, l.img, &l.n, &l.n);
	mlx_put_image_to_window(l.p_, l.win, l.addr, l.i * 50, l.j * 50);
}

void	img_put(t_data *l)
{
	int	count;

	l->j = 0;
	count = 1;
	mlx_clear_window(l->p_, l->win);
	while (l->line[l->j])
	{
		l->i = 0;
		while (l->line[l->j][l->i] != '\n')
		{	
			_ground(*l);
			if (l->line[l->j][l->i] == '1')
				_image(l, count++);
			else if (l->line[l->j][l->i] == 'C')
				_image(l, l->out++);
			else if (l->line[l->j][l->i] == 'P')
				_image(l, 0);
			else if (l->line[l->j][l->i] == 'E')
				_image(l, count++);
			l->i++;
		}
		l->j++;
	}
	enemy_put(l);
}
