/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grial <grial@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 17:53:10 by grial             #+#    #+#             */
/*   Updated: 2025/05/26 12:55:57 by grial            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	draw_ray(t_game *game, t_ray *ray);
void	draw_wall1(t_game *game, t_ray *ray, int x_width);
void	texture_wall(t_game *game, t_ray *ray);

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
		check_wall(game, game->map, ray);
		draw_ray(game, ray);
		texture_wall(game, ray);
		draw_wall1(game, game->ray, a);
		i += ray->r_step;
		a += 1;
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

//double get_height(t_game *game, float x, float y, float ang)
//{
//	float dist;
//	float height;
//
//	dist = game->ray->dis_f;
//	height = (BLOCK / (dist * BLOCK)) * (WIN_H / 2);
//	return (height);
//}

 int get_pixel_color(t_img *texture, int x, int y)
{
	char *pixel;
	int color;

	pixel = texture->addr + (y * texture->line_length + x * (texture->bpp / 8));
	color = *(int *)pixel;
	return (color);
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


void	draw_wall1(t_game *game, t_ray *ray, int x_width)
{
	double	height;
	int		draw_start;
	int		draw_end;
	int		y;
	int		offset_x;
	int		offset_y;
	t_img	*texture = game->engine->current;
	int		color;
	double	fish;

	// change function *void* fix_ang to *double* fix_ang
	//to replace
	fish = (double)game->player->dir - ray->r_dir;
		if (fish < 0)
		fish += 360.0;
	if (fish >= 360.0)
		fish = fmod(fish, 360.0);
	// untill here
	fish = to_rad(fish);
	ray->dis_f = ray->dis_f * cos(fish);

	height = ((BLOCK * WIN_H) / (ray->dis_f * BLOCK));
	
	if (height > WIN_H)
		height = WIN_H;

	draw_start = (WIN_H / 2) - (height / 2);
	if (draw_start < 0)
		draw_start = 0;

	draw_end = draw_start + height;
	if (draw_end > WIN_H)
		draw_end = WIN_H;

	offset_x = get_texture_offset_x(game, ray);

	y = draw_start;
	while (y < draw_end)
	{
		double tex_pos = (double)(y - draw_start) / (double)(draw_end - draw_start);
		offset_y = (int)(tex_pos * BLOCK);
		color = get_pixel_color(texture, offset_x, offset_y);
		my_mlx_pixel_put(game, x_width, y, color);
		y++;
	}
}

//void	draw_wall(t_game *game, int x_width, float x, float y, float ang)
//{
//	int		draw_start;
//	int		draw_end;
//	double	height;
//	t_img	*texture;
//	int		color;
//
//	int		screen_y;
//	int		tex_x;
//	int		tex_y;
//	float	step_tex_y;
//	float	tex_pos;
//
//	height = get_height(game, x, y, ang);
//	draw_start = (WIN_H / 2) - (height / 2);
//	if (draw_start < 0)
//		draw_start = 0;
//	draw_end = draw_start + height;
//	if (draw_end > WIN_H)
//		draw_end = WIN_H;
//	texture = game->engine->no_img;
//	tex_x = (int)(x * 64) % 64;
//	step_tex_y = 64.0f / height;
//	tex_pos = (draw_start - WIN_H / 2 + height / 2) * step_tex_y;
//	screen_y = draw_start;
//	while (screen_y < draw_end)
//	{
//		tex_y = (int)tex_pos & (64 - 1);
//		tex_pos += step_tex_y;
//		color = get_pixel_color(texture, tex_x, tex_y);
//		my_mlx_pixel_put(game, x_width, screen_y, color);
//		screen_y++;
//	}
//}


void	texture_wall(t_game *game, t_ray *ray)
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

