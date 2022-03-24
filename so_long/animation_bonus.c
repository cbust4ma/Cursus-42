/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 19:34:54 by cbustama          #+#    #+#             */
/*   Updated: 2022/03/22 17:52:05 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_enemy	_enemy(t_data line)
{
	t_enemy	enemy;

	enemy.s[0] = mlx_xpm_file_to_image(line.p_, E_1, &line.n, &line.n);
	enemy.s[1] = mlx_xpm_file_to_image(line.p_, E_2, &line.n, &line.n);
	enemy.s[2] = mlx_xpm_file_to_image(line.p_, E_3, &line.n, &line.n);
	enemy.s[3] = mlx_xpm_file_to_image(line.p_, E_4, &line.n, &line.n);
	enemy.s[4] = mlx_xpm_file_to_image(line.p_, E_5, &line.n, &line.n);
	enemy.s[5] = mlx_xpm_file_to_image(line.p_, E_6, &line.n, &line.n);
	enemy.s[6] = mlx_xpm_file_to_image(line.p_, E_7, &line.n, &line.n);
	enemy.s[7] = mlx_xpm_file_to_image(line.p_, E_8, &line.n, &line.n);
	enemy.count = 0;
	return (enemy);
}

int	_sprites(t_data *l)
{
	if (l->loop < 50)
		l->loop++;
	else
	{
		l->enemy.count++;
		enemy_put(l);
		l->loop = 0;
	}
	return (0);
}

void	_movement(t_data *l)
{
	l->loop = 0;
	mlx_loop_hook(l->p_, _sprites, l);
}
