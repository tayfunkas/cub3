/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_fov.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grial <grial@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 18:55:33 by grial             #+#    #+#             */
/*   Updated: 2025/02/27 18:43:10 by grial            ###   ########.fr       */
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
		mlx_pixel_put(game->mlx_ptr, game->mlx_window, new_y * MIN_S, new_x
			* MIN_S, 0x005500);
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

void	draw_wall(t_game *game, int x_width, float x, float y, float ang)
{
	float	v_ray;
	int		i;
	int		a;

	a = 0;
	i = 0;
	v_ray = distance(x, y, game->player->player_x, game->player->player_y)
		* cos(ang * M_PI / 180.0);
	v_ray = (MIN_S * WIN_H) / v_ray;
	if (v_ray > WIN_H)
		v_ray = WIN_H;
	i = -v_ray / 2;
	while (a < v_ray)
	{
		mlx_pixel_put(game->mlx_ptr, game->mlx_window, x_width, (WIN_H / 2) + i
			+ a, 0x005500);
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
