/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_fov.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grial <grial@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 18:55:33 by grial             #+#    #+#             */
/*   Updated: 2025/03/03 17:24:59 by grial            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	draw_fov(t_game *game, t_player *player)
{
	float	ray_step;
	float	x;
	int		a;

	ray_step = (float)FOV / (float)WIN_W;
	x = -FOV / 2;
	a = 0;
	while (a < WIN_W)
	{
		draw_ray_line(game, player, a, x);
		x += ray_step;
		a ++;
	}
}

void	draw_ray_line(t_game *game, t_player *player, int x_width, float x)
{
	float	ray_line;
	float	angle;
	float	dx;
	float	dy;
	float	new_x;
	float	new_y;

	angle = (player->player_dir + x) * M_PI / 180.0;
	ray_line = 0;
	while (1)
	{
		dy = cos(angle) * ray_line;
		dx = -sin(angle) * ray_line;
		new_x = player->player_x + dx;
		new_y = player->player_y + dy;
		if (draw_check_collision(game, x_width, new_x, new_y, x))
			break ;
	//	mlx_pixel_put(game->mlx_ptr, game->mlx_window, new_y * MIN_S, new_x
	//		* MIN_S, 0x005500);
		ray_line += STEP;
	}
}

float	distance(float x1, float y1, float x2, float y2)
{
	float	dx;
	float	dy;

	dx = x2 - x1;
	dy = y2 - y1;
	return (sqrt(dx * dx + dy * dy));
}

void	draw_wall_texture(t_game *game, int x_width, float x, float y, float ang, float hit_x, float hit_y)
{
	t_img_add	*texture;
	float		wall_height;
	int			texX;
	int			texY;
	int			color;
	int			screenY;
	int			a;

	// Determinar qué textura usar según la orientación del impacto
	if (hit_x > hit_y)
		texture = game->text->NO;
	else
		texture = game->text->EA;

	// Calcular la distancia corregida con perspectiva
	wall_height = distance(x, y, game->player->player_x, game->player->player_y) * cos(ang * M_PI / 180.0);
	wall_height = (MIN_S * WIN_H) / wall_height;
	if (wall_height > WIN_H)
		wall_height = WIN_H;

	// Determinar la coordenada X de la textura
	texX = (int)(hit_x * texture->width);
	if (texX < 0) texX = 0;
	if (texX >= texture->width) texX = texture->width - 1;

	// Dibujar cada píxel de la pared en la pantalla
	a = 0;
	while (a < wall_height)
	{
		texY = (a * texture->height) / wall_height;
		color = *(int *)(texture->addr + (texY * texture->line_len + texX * (texture->bpp / 8)));
		screenY = (WIN_H / 2) - (wall_height / 2) + a;
		if (screenY >= 0 && screenY < WIN_H)
			mlx_pixel_put(game->mlx_ptr, game->mlx_window, x_width, screenY, color);
		a++;
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
