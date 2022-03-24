/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 20:10:24 by cbustama          #+#    #+#             */
/*   Updated: 2022/03/22 17:55:53 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	_walk_d(t_data *l)
{
	int	a;

	a = l->p.y * N;
	l->p.d_++;
	l->p.count++;
	put_window(l);
	if (l->line[l->p.y][l->p.x - 1] == '0')
		l->addr = mlx_xpm_file_to_image(l->p_, _GROUND, &l->n, &l->n);
	mlx_put_image_to_window(l->p_, l->win, l->addr, (l->p.x - 1) * N, a);
	if (l->line[l->p.y][l->p.x] == 'P' && l->p.d_ % 2 == 0)
	{	
		l->addr = mlx_xpm_file_to_image(l->p_, _GROUND, &l->n, &l->n);
		mlx_put_image_to_window(l->p_, l->win, l->addr, l->p.x * N, l->p.y * N);
		l->addr = mlx_xpm_file_to_image(l->p_, D_1, &l->n, &l->n);
	}
	else
	{
		l->addr = mlx_xpm_file_to_image(l->p_, _GROUND, &l->n, &l->n);
		mlx_put_image_to_window(l->p_, l->win, l->addr, l->p.x * N, l->p.y * N);
		l->addr = mlx_xpm_file_to_image(l->p_, D_0, &l->n, &l->n);
	}
	mlx_put_image_to_window(l->p_, l->win, l->addr, l->p.x * N, l->p.y * N);
	end_game(l);
}

void	_walk_s(t_data *l)
{
	int	a;

	a = l->p.x * N;
	l->p.s_++;
	l->p.count++;
	put_window(l);
	if (l->line[l->p.y - 1][l->p.x] == '0')
		l->addr = mlx_xpm_file_to_image(l->p_, _GROUND, &l->n, &l->n);
	mlx_put_image_to_window(l->p_, l->win, l->addr, a, (l->p.y - 1) * N);
	if (l->line[l->p.y][l->p.x] == 'P' && l->p.s_ % 2 == 0)
	{	
		l->addr = mlx_xpm_file_to_image(l->p_, _GROUND, &l->n, &l->n);
		mlx_put_image_to_window(l->p_, l->win, l->addr, l->p.x * N, l->p.y * N);
		l->addr = mlx_xpm_file_to_image(l->p_, PJ_1, &l->n, &l->n);
	}
	else
	{
		l->addr = mlx_xpm_file_to_image(l->p_, _GROUND, &l->n, &l->n);
		mlx_put_image_to_window(l->p_, l->win, l->addr, l->p.x * N, l->p.y * N);
		l->addr = mlx_xpm_file_to_image(l->p_, PJ_, &l->n, &l->n);
	}
	mlx_put_image_to_window(l->p_, l->win, l->addr, l->p.x * N, l->p.y * N);
}

void	_walk_a(t_data *l)
{
	int	a;

	a = l->p.y * N;
	l->p.a_++;
	l->p.count++;
	put_window(l);
	if (l->line[l->p.y][l->p.x + 1] == '0')
		l->addr = mlx_xpm_file_to_image(l->p_, _GROUND, &l->n, &l->n);
	mlx_put_image_to_window(l->p_, l->win, l->addr, (l->p.x + 1) * N, a);
	if (l->line[l->p.y][l->p.x] == 'P' && l->p.a_ % 2 == 0)
	{
		l->addr = mlx_xpm_file_to_image(l->p_, _GROUND, &l->n, &l->n);
		mlx_put_image_to_window(l->p_, l->win, l->addr, l->p.x * N, l->p.y * N);
		l->addr = mlx_xpm_file_to_image(l->p_, A_1, &l->n, &l->n);
	}
	else
	{
		l->addr = mlx_xpm_file_to_image(l->p_, _GROUND, &l->n, &l->n);
		mlx_put_image_to_window(l->p_, l->win, l->addr, l->p.x * N, l->p.y * N);
		l->addr = mlx_xpm_file_to_image(l->p_, A_0, &l->n, &l->n);
	}
	mlx_put_image_to_window(l->p_, l->win, l->addr, l->p.x * N, l->p.y * N);
	end_game(l);
}

void	_walk(t_data *l)
{
	int	a;

	a = l->p.x * N;
	l->p.w++;
	l->p.count++;
	put_window(l);
	if (l->line[l->p.y + 1][l->p.x] == '0')
		l->addr = mlx_xpm_file_to_image(l->p_, _GROUND, &l->n, &l->n);
	mlx_put_image_to_window(l->p_, l->win, l->addr, a, (l->p.y + 1) * N);
	if (l->line[l->p.y][l->p.x] == 'P' && l->p.w % 2 == 0)
	{
		l->addr = mlx_xpm_file_to_image(l->p_, _GROUND, &l->n, &l->n);
		mlx_put_image_to_window(l->p_, l->win, l->addr, l->p.x * N, l->p.y * N);
		l->addr = mlx_xpm_file_to_image(l->p_, W_0, &l->n, &l->n);
	}
	else
	{
		l->addr = mlx_xpm_file_to_image(l->p_, _GROUND, &l->n, &l->n);
		mlx_put_image_to_window(l->p_, l->win, l->addr, l->p.x * N, l->p.y * N);
		l->addr = mlx_xpm_file_to_image(l->p_, W_1, &l->n, &l->n);
	}
	mlx_put_image_to_window(l->p_, l->win, l->addr, l->p.x * N, l->p.y * N);
	end_game(l);
}
