/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_fov.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grial <grial@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 18:55:33 by grial             #+#    #+#             */
/*   Updated: 2025/04/07 15:33:31 by grial            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	draw_fov(t_game *game, t_player *player)
{
	float	dist_plane;
	float	x_plane;
	int		a;

	dist_plane = (WIN_W / 2) / tan((FOV / 2) * M_PI / 180.0);
	a = 0;
	while (a < WIN_W)
	{
		x_plane = (2 * a / (float)WIN_W - 1) * (WIN_W / 2);
		draw_ray_line(game, player, a, atan(x_plane / dist_plane));
		a++;
	}
}

void	draw_ray_line(t_game *game, t_player *player, int x_width, float ang)
{
	float	ray_line;
	float	angle;
	float	dx;
	float	dy;
	float	new_x;
	float	new_y;

	angle = player->player_dir + (ang * 180.0 / M_PI);
	ray_line = 0;
	while (1)
	{
		dy = cos(angle * M_PI / 180.0) * ray_line;
		dx = -sin(angle * M_PI / 180.0) * ray_line;
		new_x = player->player_x + dx;
		new_y = player->player_y + dy;
		if (draw_check_collision(game, x_width, new_x, new_y, ang))
			break ;
		ray_line += 0.01;
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

	if (!game || !game->engine || !game->engine->frame || !game->engine->frame->addr)
	{
		printf("Invalid pointer in my_mlx_pixel_put\n");
		return;
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

	dist = distance(x, y, game->player->player_x, game->player->player_y)
	* cos(ang);
	height = (BLOCK / (dist * BLOCK)) * (WIN_H / 2);
	return (height);
}

int get_texture_offset(float scale)
{
	int	mid_point;	// change name, is not the mid_point
	int	init_point;

	mid_point = (BLOCK / scale);
	init_point = (BLOCK / 2) - (mid_point / 2);
	return (init_point);
}

void	draw_wall(t_game *game, int x_width, float x, float y, float ang)
{
	float	height;
	int		tx_start;
	int		tx_end;
	int		steps;
	float	scale;
	t_img	*texture;
	int		color;
	
	int		y_pos = 0;
	int		tex_x;
	int		tex_ys;

	steps = (float)BLOCK / WIN_H;
	height = get_height(game, x, y, ang);
	if (height > WIN_H)
		scale = height / (float)WIN_H;
	else 
		scale = 1;
	tx_start = get_texture_offset(scale); // when scale is 2, this is 16
	tx_end = tx_start + (BLOCK / 2);
	if (scale <= 1)
	{
		tx_start = 0;
		tx_end = BLOCK;
	}
	tex_x = ((int)x % BLOCK); // o según la dirección
	texture = game->engine->no_img;
	while (tx_start < tx_end)
	{
		tex_ys = ((steps * y_pos) / scale) + tx_start;
		color = get_pixel_color(texture, tex_x, y);
		// Dibujar el píxel en pantalla
		my_mlx_pixel_put(game, x_width, y_pos, color);
		y_pos++;
		tx_start++;
	} 
}


int	draw_check_collision(t_game *game, int x_width, float x, float y, float ang)
{
	int	new_x;
	int	new_y;

	new_x = (int)floorf(x);
	new_y = (int)floorf(y);
	if (new_x < 0 || new_y < 0 ||
		new_x >= game->map->m_height ||
		new_y >= (int)ft_strlen(game->map->data[new_x]) || 
		!game->map->data[new_x])
		return (0);
	if (game->map->data[new_x][new_y] == '1')
	{
		draw_wall(game, x_width, x, y, ang);
		return (1);
	}
	return (0);
}
