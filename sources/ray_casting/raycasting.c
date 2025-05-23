/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grial <grial@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 17:53:10 by grial             #+#    #+#             */
/*   Updated: 2025/05/23 12:29:02 by grial            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	draw_ray(t_game *game, t_ray *ray);
void	draw_wall1(t_game *game, t_ray *ray, int x_width);

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
	init_dir = game->player->dir - (FOV / 2);
	ray->r_step = (double)FOV / (double)WIN_W;
	while (i < FOV)
	{
		fix_ang(ray, init_dir, i);
		check_wall(game, game->map, ray);
		draw_ray(game, ray);
		draw_wall1(game, game->ray, a);
		i += ray->r_step;
		a += 1;
	}
	printf("%f\n", i);
}

void	draw_ray(t_game *game, t_ray *ray)
{
	double	end_x;
	double	end_y;

	ray->dis_f = ray->dis_v;
	if (ray->dis_h < ray->dis_v && ray->dis_h > 0.0)
		ray->dis_f = ray->dis_h;
	end_x = game->player->pos_x + cos(to_rad(ray->r_dir)) * ray->dis_f;
	end_y = game->player->pos_y - sin(to_rad(ray->r_dir)) * ray->dis_f;
	draw_line(game, game->player->pos_x * (double)MIN_S, game->player->pos_y
		* (double)MIN_S, end_x * (double)MIN_S, end_y * (double)MIN_S,
		0xFF0F0F);
}

// float get_height(t_game *game, float x, float y, float ang)
//{
//	float dist;
//	float height;
//
//	dist = game->ray->dis_f;
//	height = (BLOCK / (dist * BLOCK)) * (WIN_H / 2);
//	return (height);
//}

// int get_pixel_color(t_img *texture, int x, int y)
//{
//	char *pixel;
//	int color;
//
//	pixel = texture->addr + (y * texture->line_length + x * (texture->bpp / 8));
//	color = *(int *)pixel;
//	return (color);
//}

void	draw_wall1(t_game *game, t_ray *ray, int x_width)
{
	double	height;
	int		draw_start;
	int		draw_end;
	int		y;

	height = ((BLOCK * WIN_H) / (ray->dis_f * BLOCK));
	if (height > WIN_H)
		height = WIN_H;
	draw_start = (WIN_H / 2) - (height / 2);
	if (draw_start < 0)
		draw_start = 0;
	draw_end = draw_start + height;
	if (draw_end > WIN_H)
		draw_end = WIN_H;
	y = draw_start;
	// Aquí renderizas el muro (ejemplo básico con color sólido)
	while (y < draw_end)
	{
		my_mlx_pixel_put(game, x_width, y, 0xF3552F);
		y++; // blanco
	}
}
