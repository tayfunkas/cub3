/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_fov.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasapog <tkasapog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 18:55:33 by grial             #+#    #+#             */
/*   Updated: 2025/04/01 15:47:51 by tkasapog         ###   ########.fr       */
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
		a++;
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
		//mlx_pixel_put(game->mlx_ptr, game->mlx_window, new_y * MIN_S, new_x
		//	* MIN_S, 0x005500);
		ray_line += 0.01 ;
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
		dst = game->engine->frame->addr + (y * game->engine->frame->line_length + x * (game->engine->frame->bpp / 8));
		*(unsigned int*)dst = color;
	}
}

int get_pixel_color(t_img *texture, int x, int y)
{
    char    *pixel;
    int     color;

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
	int		tex_y;
	t_img	*texture = game->engine->no_img; // Siempre usamos la textura del muro norte

	// Corregir distancia con FOV
	dist = distance(x, y, game->player->player_x, game->player->player_y)
		* cos(ang * M_PI / 180.0);
	height = (BLOCK / (dist * BLOCK)) * (WIN_H / 2);
	if (height > (float)WIN_H)
		height = WIN_H;
	start = (WIN_H / 2) - (height / 2);
	end = (WIN_H / 2) + (height / 2);
	y_pos = start;

	// Calcular la coordenada X en la textura
	tex_x = (int)(x * 64) % 64;

	while (y_pos < end)
	{
		// Calcular la coordenada Y en la textura
		tex_y = ((y_pos - start) * 64) / height;

		// Obtener el color del píxel de la textura
		int color = get_pixel_color(texture, tex_x, tex_y);

		// Dibujar el píxel en la imagen principal
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


