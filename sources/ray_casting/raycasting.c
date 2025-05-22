/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grial <grial@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 17:53:10 by grial             #+#    #+#             */
/*   Updated: 2025/05/22 11:56:37 by grial            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	draw_ray(t_game *game, t_ray *ray);

void	draw_line(t_game *game, float x0, float y0, float x1, float y1,
		int color)
{
	float	dx;
	float	dy;
	float	steps;
	int		i;

	dx = x1 - x0;
	dy = y1 - y0;
	float x_inc, y_inc;
	steps = fmaxf(fabsf(dx), fabsf(dy));
	if (steps == 0)
		return ;
	x_inc = dx / steps;
	y_inc = dy / steps;
	for (i = 0; i < steps; i++)
	{
		my_mlx_pixel_put(game, (int)x0, (int)y0, color);
		x0 += x_inc;
		y0 += y_inc;
	}
}
void	raycasting(t_game *game, t_ray *ray)
{
	int	i;
	int	init_dir;
	int	color;
	//int	start_x;
	//int	start_y;

	double dx = 0.0;
	double dy = 0.0;
	i = 0;
	//start_x = (int)(game->player->pos_x * BLOCK);
	//start_y = (int)(game->player->pos_y * BLOCK);
	init_dir = game->player->dir - (FOV / 2);
	while (i < FOV)
	{
		ray_ang(ray, init_dir, i);
		dx = cos(to_rad(ray->ray_a));
		dy = -sin(to_rad(ray->ray_a));
		color = 0xFF0F0F;
		//draw_line(game, game->player->pos_x * BLOCK, game->player->pos_y * BLOCK, game->player->pos_x * BLOCK + dx * 100, game->player->pos_y * BLOCK + dy * 100, color);
		//my_mlx_pixel_put(game, start_x + (int)dx, start_y + (int)dy, color);
        check_wall(game, game->map, ray);
		draw_ray(game, ray);
		i += 1;
	}
}

void	draw_ray(t_game *game, t_ray *ray)
{
	double	dist_ray;
	double	end_x;
	double	end_y;

	dist_ray = ray->dist_v;
	if (ray->dist_h < ray->dist_v)
		dist_ray = ray->dist_h;
	end_x = game->player->pos_x + cos(to_rad(ray->ray_a)) * dist_ray;
	end_y = game->player->pos_y - sin(to_rad(ray->ray_a)) * dist_ray;
		draw_line(game,
		game->player->pos_x * BLOCK,
		game->player->pos_y * BLOCK,
		end_x * BLOCK,
		end_y * BLOCK,
		0xFF0F0F);
}

