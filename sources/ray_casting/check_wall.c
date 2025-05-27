/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grial <grial@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 16:36:40 by grial             #+#    #+#             */
/*   Updated: 2025/05/27 17:48:14 by grial            ###   ########.fr       */
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
			ray->dis_h = cos(to_rad(ray->r_dir)) * (ray->ray_x
					- game->player->pos_x) - sin(to_rad(ray->r_dir))
				* (ray->ray_y - game->player->pos_y);
			break ;
		}
		else
		{
			ray->ray_x += ray->del_x;
			ray->ray_y += ray->del_y;
			i++;
		}
	}
}

void	wall_dist(t_game *game, t_map *map, t_ray *ray)
{
	vertical_values(game, ray);
	ray_dist(game, map, ray, &ray->dis_v);
	horizontal_values(game, ray);
	ray_dist(game, map, ray, &ray->dis_h);
}

void	vertical_values(t_game *game, t_ray *ray)
{
	ray->dis_v = 1000000;
	ray->ray_t = tan(to_rad(ray->r_dir));
	if (ray->r_dir < 90.0 || ray->r_dir > 270.0)
	{
		ray->ray_x = (int)game->player->pos_x + 1;
		ray->ray_y = (game->player->pos_x - ray->ray_x) * ray->ray_t
			+ game->player->pos_y;
		ray->del_x = 1;
		ray->del_y = -ray->del_x * ray->ray_t;
	}
	else if (ray->r_dir > 90.0 && ray->r_dir < 270.0)
	{
		ray->ray_x = (int)game->player->pos_x - 0.0001;
		ray->ray_y = (game->player->pos_x - ray->ray_x) * ray->ray_t
			+ game->player->pos_y;
		ray->del_x = -1;
		ray->del_y = -ray->del_x * ray->ray_t;
	}
	else if (ray->r_dir == 90.0 || ray->r_dir == 270.0)
	{
		ray->ray_x = game->player->pos_x;
		ray->ray_y = game->player->pos_y;
		ray->del_x = 0.0;
		ray->del_y = 0.0;
	}
}

void	horizontal_values(t_game *game, t_ray *ray)
{
	ray->dis_h = 1000000;
	ray->ray_t = 1.0 / tan(to_rad(ray->r_dir));
	if (ray->r_dir > 0.0 && ray->r_dir < 180.0) // Looking up
	{
		ray->ray_y = (int)game->player->pos_y - 0.0001;
		ray->ray_x = (game->player->pos_y - ray->ray_y) * ray->ray_t
			+ game->player->pos_x;
		ray->del_y = -1;
		ray->del_x = -ray->del_y * ray->ray_t;
	}
	else if (ray->r_dir > 180.0 && ray->r_dir < 360.0) // Mirando hacia abajo
	{
		ray->ray_y = (int)game->player->pos_y + 1;
		ray->ray_x = (game->player->pos_y - ray->ray_y) * ray->ray_t
			+ game->player->pos_x;
		ray->del_y = 1;
		ray->del_x = -ray->del_y * ray->ray_t;
	}
	else if (ray->r_dir == 0.0 || ray->r_dir == 180.0)
	{
		ray->ray_x = game->player->pos_x;
		ray->ray_y = game->player->pos_y;
		ray->del_x = 0.0;
		ray->del_y = 0.0;
	}
}

void	ray_dist(t_game *game, t_map *map, t_ray *ray, double *dist)
{
	int	int_x;
	int	int_y;
	int	i;

	i = 0;
	printf("fijar 80 a la longitud del mapa.\n");
	while (i <= 80)
	{
		int_x = (int)(ray->ray_x);
		int_y = (int)(ray->ray_y);
		if (int_y >= 0 && int_y < map->m_height && int_x >= 0
			&& int_x < (int)ft_strlen(map->data[int_y])
			&& map->data[int_y][int_x] == '1' && map->data[int_y])
		{
			*dist = (cos(to_rad(ray->r_dir)) * (ray->ray_x
						- game->player->pos_x)) - (sin(to_rad(ray->r_dir))
					* (ray->ray_y - game->player->pos_y));
			break ;
		}
		else
		{
			ray->ray_x += ray->del_x;
			ray->ray_y += ray->del_y;
			i++;
		}
	}
}
