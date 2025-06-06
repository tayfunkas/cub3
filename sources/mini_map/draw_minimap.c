/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grial <grial@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 12:04:16 by grial             #+#    #+#             */
/*   Updated: 2025/06/06 11:38:56 by grial            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	draw_raya(t_game *game, t_ray *ray);
void	draw_ray(t_game *game, t_ray *ray);
void	draw_line(t_game *game, float x0, float y0, float x1, float y1,
		int color);

void	draw_minimap(t_game *game)
{
	draw_map(game);
	draw_raya(game, game->engine->ray);
	draw_miniplayer(game);
}

void	draw_raya(t_game *game, t_ray *ray)
{
	int		init_dir;
	double	i;
	int		a;

	i = 0.0;
	a = 0;
	init_dir = game->player->dir + (FOV / 2);
	ray->r_step = (double)FOV / (double)WIN_W;
	while (a < WIN_W)
	{
		fix_ang(ray, init_dir, -i);
		wall_dist(game, game->map, ray);
		draw_ray(game, ray);
		i += ray->r_step;
		a += 1;
	}
}

void	draw_ray(t_game *game, t_ray *ray)
{
	double end_x;
	double end_y;

	ray->dis_f = ray->dis_v;
	ray->r_side = 0;
	if (ray->dis_h < ray->dis_v && ray->dis_h > 0.0)
	{
		ray->r_side = 1;
		ray->dis_f = ray->dis_h;
	}
	end_x = game->player->pos_x + cos(to_rad(ray->r_dir)) * ray->dis_f;
	end_y = game->player->pos_y - sin(to_rad(ray->r_dir)) * ray->dis_f;
	draw_line(game, game->player->pos_x * (double)MIN_S, game->player->pos_y
		* (double)MIN_S, end_x * (double)MIN_S, end_y * (double)MIN_S,
		0xFF0F0F);
}

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