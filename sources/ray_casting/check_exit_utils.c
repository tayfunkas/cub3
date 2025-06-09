/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_exit_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grial <grial@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 16:36:40 by grial             #+#    #+#             */
/*   Updated: 2025/06/09 18:04:05 by grial            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	is_exit(t_map *map, int int_y, int int_x)
{
	if (int_y >= 0 && int_y < map->m_height && int_x >= 0
		&& int_x < (int)ft_strlen(map->data[int_y])
		&& map->data[int_y][int_x] == 'Q')
		return (1);
	else
		return (0);
}

void	exit_dist_vertical(t_game *game, t_map *map, t_ray *ray)
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
		if (is_wall(map, int_y, int_x) || is_exit(map, int_y, int_x))
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

void	exit_dist_horizontal(t_game *game, t_map *map, t_ray *ray)
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
		if (is_wall(map, int_y, int_x) || is_exit(map, int_y, int_x))
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
