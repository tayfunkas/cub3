/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_fov.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grial <grial@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 18:55:33 by grial             #+#    #+#             */
/*   Updated: 2025/04/04 18:50:44 by grial            ###   ########.fr       */
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

void	draw_wall(t_game *game, int x_width, float x, float y, float ang)
{
	float	dist;
	float	height;
	int		start;
	int		end;
	int		y_pos;
	int		tex_x;
	int		tex_ys;
	int		tex_start;
	t_img	*texture;
	int		color;
	float	scale;

	texture = game->engine->no_img;
	// Calcular la distancia desde el jugador hasta la pared y proyectar la altura
	dist = distance(x, y, game->player->player_x, game->player->player_y)
		* cos(ang);
	height = (BLOCK / (dist * BLOCK)) * (WIN_H / 2);

	// Ajustar la textura cuando la pared es más grande que la ventana
	tex_start = 0;
	if (height > WIN_H)
	{
		scale = height / (float)WIN_H;
		tex_start = ((height - WIN_H) / 2) * (64 / height); // Ajuste en la textura
		height = WIN_H;
	}

	// Calcular los puntos de inicio y final en la ventana
	start = (WIN_H / 2) - (height / 2);
	end = (WIN_H / 2) + (height / 2);

	// Si la pared empieza fuera de la pantalla, ajustar el inicio de la textura
	if (start < 0)
	{
		tex_start += (-start) * (64 / height);
		start = 0;
	}
	if (end > WIN_H)
		end = WIN_H;

	// Iniciar la posición vertical en la pantalla
	y_pos = start;
	// Calcular la posición de la textura horizontalmente
	tex_x = (int)(x * 64) % 64;

	// Dibujar la textura de la pared
	while (y_pos < end)
	{
		// Obtener el color del píxel de la textura
		color = get_pixel_color(texture, tex_x, floorf(tex_ys * scale));
		// Dibujar el píxel en pantalla
		my_mlx_pixel_put(game, x_width, y_pos, color);
		y_pos++;
	} 
}


int	draw_check_collision(t_game *game, int x_width, float x, float y, float ang)
{
	int	new_x;
	int	new_y;

	new_x = (int)floorf(x);
	new_y = (int)floorf(y);
	if (game->map->data[new_x][new_y] == '1')
	{
		draw_wall(game, x_width, x, y, ang);
		return (1);
	}
	return (0);
}
