/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grial <grial@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 16:36:40 by grial             #+#    #+#             */
/*   Updated: 2025/06/04 18:10:29 by grial            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	is_wall(t_map *map, int int_y, int int_x)
{
	if (int_y >= 0 && int_y < map->m_height && int_x >= 0
		&& int_x < (int)ft_strlen(map->data[int_y])
		&& (map->data[int_y][int_x] == '1' || map->data[int_y][int_x] == 'D'))
		return (1);
	else
		return (0);
}

void	vertical_values(t_game *game, t_ray *ray)
{
	ray->dis_v = 1000000;
	ray->ray_t = tan(to_rad(ray->r_dir));
	if (ray->r_dir < 90.0 || ray->r_dir > 270.0)
	{
		ray->ray_vx = (int)game->player->pos_x + 1;
		ray->ray_vy = (game->player->pos_x - ray->ray_vx) * ray->ray_t
			+ game->player->pos_y;
		ray->del_x = 1;
		ray->del_y = -ray->del_x * ray->ray_t;
	}
	else if (ray->r_dir > 90.0 && ray->r_dir < 270.0)
	{
		ray->ray_vx = (int)game->player->pos_x - 0.0001;
		ray->ray_vy = (game->player->pos_x - ray->ray_vx) * ray->ray_t
			+ game->player->pos_y;
		ray->del_x = -1;
		ray->del_y = -ray->del_x * ray->ray_t;
	}
	else if (ray->r_dir == 90.0 || ray->r_dir == 270.0)
	{
		ray->ray_vx = game->player->pos_x;
		ray->ray_vy = game->player->pos_y;
		ray->del_x = 0.0;
		ray->del_y = 0.0;
	}
}

void	horizontal_values(t_game *game, t_ray *ray)
{
	ray->dis_h = 1000000;
	ray->ray_t = 1.0 / tan(to_rad(ray->r_dir));
	if (ray->r_dir > 0.0 && ray->r_dir < 180.0)
	{
		ray->ray_hy = (int)game->player->pos_y - 0.000001;
		ray->ray_hx = (game->player->pos_y - ray->ray_hy) * ray->ray_t
			+ game->player->pos_x;
		ray->del_y = -1;
		ray->del_x = -ray->del_y * ray->ray_t;
	}
	else if (ray->r_dir > 180.0 && ray->r_dir < 360.0)
	{
		ray->ray_hy = (int)game->player->pos_y + 1;
		ray->ray_hx = (game->player->pos_y - ray->ray_hy) * ray->ray_t
			+ game->player->pos_x;
		ray->del_y = 1;
		ray->del_x = -ray->del_y * ray->ray_t;
	}
	else if (ray->r_dir == 0.0 || ray->r_dir == 180.0)
	{
		ray->ray_hx = game->player->pos_x;
		ray->ray_hy = game->player->pos_y;
		ray->del_x = 0.0;
		ray->del_y = 0.0;
	}
}

void	ray_dist_vertical(t_game *game, t_map *map, t_ray *ray)
{
	double	rx;
	double	ry;
	int		int_x;
	int		int_y;
	int		i;

	rx = ray->ray_vx;
	ry = ray->ray_vy;
	i = 0;
	while (i <= (map->vision * 2))
	{
		int_x = (int)rx;
		int_y = (int)ry;
		if (is_wall(map, int_y, int_x))
		{
			ray->ray_vx = rx;
			ray->ray_vy = ry;
			ray->dis_v = sqrt(pow(rx - game->player->pos_x, 2) + pow(ry
						- game->player->pos_y, 2));
			break ;
		}
		rx += ray->del_x;
		ry += ray->del_y;
		i++;
	}
}

void	ray_dist_horizontal(t_game *game, t_map *map, t_ray *ray)
{
	double	rx;
	double	ry;
	int		int_x;
	int		int_y;
	int		i;

	rx = ray->ray_hx;
	ry = ray->ray_hy;
	i = 0;
	while (i <= (map->vision * 2))
	{
		int_x = (int)rx;
		int_y = (int)ry;
		if (is_wall(map, int_y, int_x))
		{
			ray->ray_hx = rx;
			ray->ray_hy = ry;
			ray->dis_h = sqrt(pow(rx - game->player->pos_x, 2) + pow(ry
						- game->player->pos_y, 2));
			break ;
		}
		rx += ray->del_x;
		ry += ray->del_y;
		i++;
	}
}
