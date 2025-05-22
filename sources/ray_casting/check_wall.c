/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grial <grial@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 16:36:40 by grial             #+#    #+#             */
/*   Updated: 2025/05/22 18:14:28 by grial            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	ray_dist_h(t_game *game, t_map *map, t_ray *ray)
{
	int	int_x;
	int	int_y;
	int	i;

	i = 0;
	while (i <= 80)
	{
		int_x = (int)(ray->ray_x);
		int_y = (int)(ray->ray_y);
		if (int_y >= 0 && int_y < map->m_height && int_x >= 0
			&& int_x < (int)ft_strlen(map->data[int_y])
			&& map->data[int_y][int_x] == '1')
		{
			ray->dist_h = cos(to_rad(ray->ray_a)) * (ray->ray_x
					- game->player->pos_x) - sin(to_rad(ray->ray_a))
				* (ray->ray_y - game->player->pos_y);
			break ;
		}
		else
		{
			ray->ray_x += ray->delta_x;
			ray->ray_y += ray->delta_y;
			i++;
		}
	}
}

void	check_wall(t_game *game, t_map *map, t_ray *ray)
{
	vertical_values(game, ray);
	ray_dist(game, map, ray);
	horizontal_values(game, ray);
	ray_dist_h(game, map, ray);
}

void	vertical_values(t_game *game, t_ray *ray)
{
	ray->dist_v = 1000000;
	ray->ray_t = tan(to_rad(ray->ray_a));
	if (ray->ray_a < 90.0 || ray->ray_a > 270.0)
	{
		ray->ray_x = (int)game->player->pos_x + 1;
		ray->ray_y = (game->player->pos_x - ray->ray_x) * ray->ray_t
			+ game->player->pos_y;
		ray->delta_x = 1;
		ray->delta_y = -ray->delta_x * ray->ray_t;
	}
	else if (ray->ray_a > 90.0 && ray->ray_a < 270.0)
	{
		ray->ray_x = (int)game->player->pos_x - 0.0001;
		ray->ray_y = (game->player->pos_x - ray->ray_x) * ray->ray_t
			+ game->player->pos_y;
		ray->delta_x = -1;
		ray->delta_y = -ray->delta_x * ray->ray_t;
	}
	else if (ray->ray_a == 90.0 || ray->ray_a == 270.0)
	{
		ray->ray_x = game->player->pos_x;
		ray->ray_y = game->player->pos_y;
		ray->delta_x = 0.0;
		ray->delta_y = 0.0;
	}
}

void	horizontal_values(t_game *game, t_ray *ray)
{
	ray->dist_h = 1000000;
	ray->ray_t = 1.0 / tan(to_rad(ray->ray_a));
	if (ray->ray_a > 0.0 && ray->ray_a < 180.0) // Looking up
	{
		ray->ray_y = (int)game->player->pos_y - 0.0001;
		ray->ray_x = (game->player->pos_y - ray->ray_y) * ray->ray_t
			+ game->player->pos_x;
		ray->delta_y = -1;
		ray->delta_x = -ray->delta_y * ray->ray_t;
	}
	else if (ray->ray_a > 180.0 && ray->ray_a < 360.0) // Mirando hacia abajo
	{
		ray->ray_y = (int)game->player->pos_y + 1;
		ray->ray_x = (game->player->pos_y - ray->ray_y) * ray->ray_t
			+ game->player->pos_x;
		ray->delta_y = 1;
		ray->delta_x = -ray->delta_y * ray->ray_t;
	}
	else if (ray->ray_a == 0.0 || ray->ray_a == 180.0)
	{
		ray->ray_x = game->player->pos_x;
		ray->ray_y = game->player->pos_y;
		ray->delta_x = 0.0;
		ray->delta_y = 0.0;
	}
}

void	ray_dist(t_game *game, t_map *map, t_ray *ray)
{
	int	int_x;
	int	int_y;
	int	i;

	i = 0;
	while (i <= 80)
	{
		// fijar 80 a la longitud del mapa.
		int_x = (int)(ray->ray_x);
		int_y = (int)(ray->ray_y);
		if (int_y >= 0 && int_y < map->m_height && int_x >= 0
			&& int_x < (int)ft_strlen(map->data[int_y])
			&& map->data[int_y][int_x] == '1' && map->data[int_y])
		{
			ray->dist_v = (cos(to_rad(ray->ray_a)) * (ray->ray_x
						- game->player->pos_x)) - (sin(to_rad(ray->ray_a))
					* (ray->ray_y - game->player->pos_y));
			break ;
		}
		else
		{
			ray->ray_x += ray->delta_x;
			ray->ray_y += ray->delta_y;
			i++;
		}
	}
}
