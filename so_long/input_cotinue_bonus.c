/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_cotinue_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 17:44:05 by cbustama          #+#    #+#             */
/*   Updated: 2022/03/22 17:14:40 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "mlx.h"

int	_esc(t_data *line)
{
	int	i;

	i = 0;
	mlx_destroy_window(line->p_, line->win);
	while (i < line->h)
	{
		free(line->line[i]);
		i++;
	}
	free (line->line);
	exit(EXIT_SUCCESS);
}

int	_input(int keycode, t_data *line)
{
	if (keycode == 53)
		_esc(line);
	if (keycode == 13)
		_w(line);
	if (keycode == 0)
		_a(line);
	if (keycode == 1)
		_s(line);
	if (keycode == 2)
		_d(line);
	return (0);
}

void	put_window(t_data *l)
{
	l->addr = mlx_xpm_file_to_image(l->p_, _GROUND, &l->n, &l->n);
	mlx_put_image_to_window(l->p_, l->win, l->addr, 50, 0);
	l->addr = mlx_xpm_file_to_image(l->p_, BACK, &l->n, &l->n);
	mlx_put_image_to_window(l->p_, l->win, l->addr, 50, 0);
	mlx_string_put(l->p_, l->win, 50, 50, 0x000F0FFF, ft_itoa(l->p.count));
}
