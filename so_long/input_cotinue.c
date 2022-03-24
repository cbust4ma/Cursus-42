/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_cotinue.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 19:41:24 by cbustama          #+#    #+#             */
/*   Updated: 2022/03/22 17:22:27 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

int	_esc(t_data *line)
{
	int	i;

	i = 0;
	while (i < line->h)
	{
		free(line->line[i]);
		i++;
	}
	free (line->line);
	mlx_destroy_window(line->p_, line->win);
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
