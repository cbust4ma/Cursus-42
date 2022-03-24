/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 20:10:24 by cbustama          #+#    #+#             */
/*   Updated: 2022/03/21 19:35:37 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	_walk_d(t_data *l)
{
	int	a;

	a = l->p.y * N;
	l->p.d[0] = D_0;
	l->p.d[1] = D_1;
	printf("\x1B[32mD[%d]\xE2\xAE\x95 \033[0m\n", l->p.d_++);
	printf("\x1B[32mWalk Total = ");
	printf("[%d]\xF0\x9F\x8F\x83  \033[0m\n \e[1;1H\e[2J", l->p.count++);
	if (l->line[l->p.y][l->p.x - 1] == '0')
		l->addr = mlx_xpm_file_to_image(l->p_, _GROUND, &l->n, &l->n);
	mlx_put_image_to_window(l->p_, l->win, l->addr, (l->p.x - 1) * N, a);
	if (l->line[l->p.y][l->p.x] == 'P' && l->p.d_ % 2 == 0)
	{	
		l->addr = mlx_xpm_file_to_image(l->p_, _GROUND, &l->n, &l->n);
		mlx_put_image_to_window(l->p_, l->win, l->addr, l->p.x * N, l->p.y * N);
		l->addr = mlx_xpm_file_to_image(l->p_, l->p.d[1], &l->n, &l->n);
	}
	else
	{
		l->addr = mlx_xpm_file_to_image(l->p_, _GROUND, &l->n, &l->n);
		mlx_put_image_to_window(l->p_, l->win, l->addr, l->p.x * N, l->p.y * N);
		l->addr = mlx_xpm_file_to_image(l->p_, l->p.d[0], &l->n, &l->n);
	}
	mlx_put_image_to_window(l->p_, l->win, l->addr, l->p.x * N, l->p.y * N);
	end_game(l);
}

void	_walk_s(t_data *l)
{
	int	a;

	a = l->p.x * N;
	printf("\x1B[32mS[%d]\xE2\xAC\x87 \033[0m\n", l->p.s_++);
	printf("\x1B[32mWalk Total = ");
	printf("[%d]\xF0\x9F\x8F\x83  \033[0m\n \e[1;1H\e[2J", l->p.count++);
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
	end_game(l);
}

void	_walk_a(t_data *l)
{
	int	a;

	a = l->p.y * N;
	l->p.a[0] = A_0;
	l->p.a[1] = A_1;
	printf("\e[1;1H\e[2J\x1B[32mA[%d]\xE2\xAC\x85 \033[0m\n", l->p.a_++);
	printf("\x1B[32mWalk Total = ");
	printf("[%d]\xF0\x9F\x8F\x83  \033[0m\n \e[1;1H\e[2J", l->p.count++);
	if (l->line[l->p.y][l->p.x + 1] == '0')
		l->addr = mlx_xpm_file_to_image(l->p_, _GROUND, &l->n, &l->n);
	mlx_put_image_to_window(l->p_, l->win, l->addr, (l->p.x + 1) * N, a);
	if (l->line[l->p.y][l->p.x] == 'P' && l->p.a_ % 2 == 0)
	{
		l->addr = mlx_xpm_file_to_image(l->p_, _GROUND, &l->n, &l->n);
		mlx_put_image_to_window(l->p_, l->win, l->addr, l->p.x * N, l->p.y * N);
		l->addr = mlx_xpm_file_to_image(l->p_, l->p.a[1], &l->n, &l->n);
	}
	else
	{
		l->addr = mlx_xpm_file_to_image(l->p_, _GROUND, &l->n, &l->n);
		mlx_put_image_to_window(l->p_, l->win, l->addr, l->p.x * N, l->p.y * N);
		l->addr = mlx_xpm_file_to_image(l->p_, l->p.a[0], &l->n, &l->n);
	}
	mlx_put_image_to_window(l->p_, l->win, l->addr, l->p.x * N, l->p.y * N);
	end_game(l);
}

void	_walk(t_data *l)
{
	int	a;

	a = l->p.x * N;
	l->p.play[0] = W_0;
	l->p.play[1] = W_1;
	printf("\e[1;1H\e[2J\x1B[32mW[%d]\xE2\xAC\x86 \033[0m\n", l->p.w++);
	printf("\x1B[32mWalk Total = ");
	printf("[%d]\xF0\x9F\x8F\x83  \033[0m\n \e[1;1H\e[2J", l->p.count++);
	if (l->line[l->p.y + 1][l->p.x] == '0')
		l->addr = mlx_xpm_file_to_image(l->p_, _GROUND, &l->n, &l->n);
	mlx_put_image_to_window(l->p_, l->win, l->addr, a, (l->p.y + 1) * N);
	if (l->line[l->p.y][l->p.x] == 'P' && l->p.w % 2 == 0)
	{
		l->addr = mlx_xpm_file_to_image(l->p_, _GROUND, &l->n, &l->n);
		mlx_put_image_to_window(l->p_, l->win, l->addr, l->p.x * N, l->p.y * N);
		l->addr = mlx_xpm_file_to_image(l->p_, l->p.play[0], &l->n, &l->n);
	}
	else
	{
		l->addr = mlx_xpm_file_to_image(l->p_, _GROUND, &l->n, &l->n);
		mlx_put_image_to_window(l->p_, l->win, l->addr, l->p.x * N, l->p.y * N);
		l->addr = mlx_xpm_file_to_image(l->p_, l->p.play[1], &l->n, &l->n);
	}
	mlx_put_image_to_window(l->p_, l->win, l->addr, l->p.x * N, l->p.y * N);
	end_game(l);
}
