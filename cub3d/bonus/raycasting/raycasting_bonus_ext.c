/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_bonus_ext.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 17:46:30 by cbustama          #+#    #+#             */
/*   Updated: 2022/08/14 21:46:41 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	raycast(t_data *data)
{
	t_ray		ray;

	ray.x = 0;
	mlx_clear_window(data->mlx, data->window);
	sky_floor_raycast(data);
	while (ray.x < data->width)
	{
		raycast_init(data, &ray);
		raycast_dir(data, &ray);
		raycast_hit(data, &ray);
		raycast_draw_pos(data, &ray);
		texturing_calculations(data, &ray);
		ray.x++;
	}
	sprite_raycast(data);
	minimap(data);
	mlx_put_image_to_window(data->mlx, data->window, data->mlx_s->img, 0, 0);
}
