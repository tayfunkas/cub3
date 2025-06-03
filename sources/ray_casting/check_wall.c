/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grial <grial@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 16:36:40 by grial             #+#    #+#             */
/*   Updated: 2025/06/03 14:56:07 by grial            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	wall_dist(t_game *game, t_map *map, t_ray *ray)
{
	vertical_values(game, ray);
	ray_dist_vertical(game, map, ray);
	horizontal_values(game, ray);
	ray_dist_horizontal(game, map, ray);
	dist_to_wall(ray);
}

void	dist_to_wall(t_ray *ray)
{
	if (ray->dis_h < ray->dis_v && ray->dis_h > 0.0)
	{
		ray->r_side = 1;
		ray->dis_f = ray->dis_h;
		ray->hit_x = ray->ray_hx;
		ray->hit_y = ray->ray_hy;
	}
	else
	{
		ray->r_side = 0;
		ray->dis_f = ray->dis_v;
		ray->hit_x = ray->ray_vx;
		ray->hit_y = ray->ray_vy;
	}
}
