/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grial <grial@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 17:53:10 by grial             #+#    #+#             */
/*   Updated: 2025/05/29 19:22:10 by grial            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	draw_ray(t_game *game, t_ray *ray);
void	draw_wall(t_game *game, t_ray *ray, int win_x);
void	get_tex(t_game *game, t_ray *ray);

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
	int		dir_i;
	int		win_x;
	double	ang_d;

	dir_i = game->player->dir + (FOV / 2);
	win_x = 0;
	ang_d = 0.0;
	ray->r_step = (double)FOV / (double)WIN_W;
	while (win_x < WIN_W)
	{
		fix_ang(ray, dir_i, -ang_d);
		wall_dist(game, game->map, ray);
		draw_ray(game, ray);
		get_tex(game, ray);
		draw_wall(game, ray, win_x);
		ang_d += ray->r_step;
		win_x += 1;
	}
}

void	draw_ray(t_game *game, t_ray *ray)
{
	double	end_x;
	double	end_y;

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

int	get_texture_offset_x(t_game *game, t_ray *ray)
{
	double	wall_hit;
	int		offset_x;

	if (ray->r_side == 0)
		wall_hit = game->player->pos_y + ray->dis_f * -sin(to_rad(ray->r_dir));
	else
		wall_hit = game->player->pos_x + ray->dis_f * cos(to_rad(ray->r_dir));
	wall_hit -= floor(wall_hit);
	offset_x = (int)(wall_hit * (double)BLOCK);
	return (offset_x);
}

void	draw_wall(t_game *game, t_ray *ray, int win_x)
{
	t_rcast	*rcast;
	int		y;

	rcast = game->engine->frame_drawing;
	fish_eye(game, ray);
	funct(ray, frame_drawing->draw_start, frame_drawing->draw_end, frame_drawing->height);
	printf("hola\n");
	frame_drawing->offset_x = get_texture_offset_x(game, ray);
	frame_drawing->step_texture = (double)BLOCK / frame_drawing->height;
	frame_drawing->tex_pos = (frame_drawing->draw_start - ((WIN_H / 2.0) - (frame_drawing->height
					/ 2.0))) * frame_drawing->step_texture;
	y = frame_drawing->draw_start;
	while (y < frame_drawing->draw_end)
	{
		frame_drawing->offset_y = get_offset_y((int)frame_drawing->tex_pos);
		frame_drawing->color = get_pixel_color(frame_drawing->texture, frame_drawing->offset_x,
				frame_drawing->offset_y);
		my_mlx_pixel_put(game, win_x, y, frame_drawing->color);
		frame_drawing->tex_pos += frame_drawing->step_texture;
		y++;
	}
}

void	get_tex(t_game *game, t_ray *ray)
{
	if (!ray->r_side)
	{
		if (ray->r_dir >= 90 && ray->r_dir <= 270)
			game->engine->current = game->engine->so_img;
		else
			game->engine->current = game->engine->no_img;
	}
	else
	{
		if (ray->r_dir >= 180 && ray->r_dir <= 360)
			game->engine->current = game->engine->we_img;
		else
			game->engine->current = game->engine->ea_img;
	}
}
