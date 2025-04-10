/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_fov.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grial <grial@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 18:55:33 by grial             #+#    #+#             */
/*   Updated: 2025/04/10 16:42:57 by grial            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	draw_fov(t_game *game, t_player *player)
{
	int		i;
	int		dir;
	double	ray_angle;

	i = 0;
	while (i < WIN_H)
	{
		ray_angle = player->dir - (game->engine->fov / 2.0) + (i
				* (game->engine->fov / ((float)WIN_H - 1)));
		if (ray_angle < 0)
			ray_angle += 2 * M_PI;
		else if (ray_angle > 2 * M_PI)
			ray_angle -= 2 * M_PI;
		get_ang(game->engine->cam, ray_angle);
		delta_dist(game->player, game->engine->cam);
		i++;
	}
}

void	calculate_side_distances(t_player *player, double ray_angle,
		double *side_dist_x, double *side_dist_y)
{
	if (ray_angle < 0)
		ray_angle += 2 * M_PI;
	else if (ray_angle > 2 * M_PI)
		ray_angle -= 2 * M_PI;
	if (cos(ray_angle) > 0)
		*side_dist_x = (1.0 - (player->pos_x - floor(player->pos_x))) / cos(ray_angle);
	else if (cos(ray_angle) < 0)
		*side_dist_x = (player->pos_x - floor(player->pos_x)) / cos(ray_angle);
	else
		*side_dist_x = INFINITY;
	if (sin(ray_angle) > 0)
		*side_dist_y = (1.0 - (player->pos_y - floor(player->pos_y))) / sin(ray_angle);
	else if (sin(ray_angle) < 0)
		*side_dist_y = (player->pos_y - floor(player->pos_y)) / sin(ray_angle);
	else
		*side_dist_y = INFINITY;
}

void	get_ang(t_cam *cam, double ray_angle)
{
	double	ray_dir_x;
	double	ray_dir_y;

	ray_dir_x = cos(ray_angle);
	ray_dir_y = sin(ray_angle);
}

void	draw_ray_line(t_game *game, t_player *player, int x_width, float ang)
{
	float	ray_line;
	float	angle;
	float	dx;
	float	dy;
	float	new_x;
	float	new_y;

	angle = player->dir + (ang * 180.0 / M_PI);
	ray_line = 0;
	while (1)
	{
		dy = cos(angle * M_PI / 180.0) * ray_line;
		dx = -sin(angle * M_PI / 180.0) * ray_line;
		new_x = player->pos_x + dx;
		new_y = player->pos_y + dy;
		if (draw_check_collision(game, x_width, new_x, new_y, ang))
			break ;
		ray_line += 0.05;
	}
}

float	distance(float x1, float y1, float x2, float y2)
{
	float	dx;
	float	dy;

	dx = x2 - x1;
	dy = y2 - y1;
	return (sqrt((dx * dx) + (dy * dy)));
}

void	my_mlx_pixel_put(t_game *game, int x, int y, int color)
{
	char	*dst;

	if (!game || !game->engine || !game->engine->frame
		|| !game->engine->frame->addr)
	{
		printf("Invalid pointer in my_mlx_pixel_put\n");
		return ;
	}
	if (x >= 0 && x < WIN_W && y >= 0 && y < WIN_H)
	{
		dst = game->engine->frame->addr + (y * game->engine->frame->line_length
				+ x * (game->engine->frame->bpp / 8));
		*(unsigned int *)dst = color;
	}
}

int	get_pixel_color(t_img *texture, int x, int y)
{
	char	*pixel;
	int		color;

	pixel = texture->addr + (y * texture->line_length + x * (texture->bpp / 8));
	color = *(int *)pixel;
	return (color);
}

float	get_height(t_game *game, float x, float y, float ang)
{
	float	dist;
	float	height;

	dist = distance(x, y, game->player->pos_x, game->player->pos_y)
		* cos(ang);
	height = (BLOCK / (dist * BLOCK)) * (WIN_H / 2);
	return (height);
}

int	get_texture_offset(float scale)
{
	int	init_point;

	int mid_point; // change name, is not the mid_point
	mid_point = (BLOCK / scale);
	init_point = (BLOCK / 2) - (mid_point / 2);
	return (init_point);
}

t_img	*get_texture_from_direction(t_game *game, float angle)
{
	angle = fmod(angle, 360.0);
	if (angle < 0)
		angle += 360.0;
	if (angle >= 45 && angle < 135)
		return (game->engine->ea_img);
	else if (angle >= 135 && angle < 225)
		return (game->engine->so_img);
	else if (angle >= 225 && angle < 315)
		return (game->engine->we_img);
	else
		return (game->engine->no_img);
}

void	draw_wall(t_game *game, int x_width, float x, float y, float ang)
{
	float	height;
	int		draw_start;
	int		draw_end;
	t_img	*texture;
	int		color;
	int		screen_y;
	int		tex_x;
	int		tex_y;
	float	step_tex_y;
	float	tex_pos;

	height = get_height(game, x, y, ang);
	draw_start = (WIN_H / 2) - (height / 2);
	if (draw_start < 0)
		draw_start = 0;
	draw_end = draw_start + height;
	if (draw_end > WIN_H)
		draw_end = WIN_H;
	tex_x = (int)(x * 64) % 64;
	step_tex_y = 64.0f / height;
	tex_pos = (draw_start - WIN_H / 2 + height / 2) * step_tex_y;
	screen_y = draw_start;
	while (screen_y < draw_end)
	{
		texture = get_texture_from_direction(game, ang);
		tex_y = (int)tex_pos & (64 - 1);
		tex_pos += step_tex_y;
		color = get_pixel_color(texture, tex_x, tex_y);
		my_mlx_pixel_put(game, x_width, screen_y, color);
		screen_y++;
	}
}

int	draw_check_collision(t_game *game, int x_width, float x, float y, float ang)
{
	int	new_x;
	int	new_y;

	new_x = (int)floorf(x);
	new_y = (int)floorf(y);
	if (new_x < 0 || new_y < 0 || new_x >= game->map->m_height
		|| new_y >= (int)ft_strlen(game->map->data[new_x])
		|| !game->map->data[new_x])
		return (0);
	if (game->map->data[new_x][new_y] == '1')
	{
		draw_wall(game, x_width, x, y, ang);
		return (1);
	}
	return (0);
}
