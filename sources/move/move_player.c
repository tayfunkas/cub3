/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grial <grial@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 19:12:05 by grial             #+#    #+#             */
/*   Updated: 2025/02/21 16:03:43 by grial            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	keys_player(int key, t_game *game)
{
	if (key == ESCAPE)
		free_game(game);
	if (key == UP || key == DOWN)
		player_move(game->player, game->map, key);
	if (key == LEFT || key == RIGHT)
		player_direction(game->player, key);
	return (0);
}

void	player_direction(t_player *player, int key)
{
	if (key == LEFT)
		player->player_dir = (player->player_dir + 4) % 360;  // Gira a la izquierda (1 grado)
	else if (key == RIGHT)
		player->player_dir = (player->player_dir - 4 + 360) % 360;  // Gira a la derecha (1 grado)
}

void	player_move(t_player *player, t_map *map, int key)
{
	double	angle;
	double	dx;
	double	dy;
	double	new_x;
	double	new_y;

	angle = player->player_dir * M_PI / 180.0;
	dy = cos(angle) * STEP;
	dx = -sin(angle) * STEP;
	if (key == UP)
	{
		new_x = player->player_x + dx;
		new_y = player->player_y + dy;
	}
	else if (key == DOWN)
	{
		new_x = player->player_x - dx;
		new_y = player->player_y - dy;
	}
	if (check_collision(map, new_x, new_y))
	{
		player->player_x = new_x;
		player->player_y = new_y;
	}
}

int	check_collision(t_map *map, float x, float y)
{
	int	new_x;
	int	new_y;

	new_x = (int) floorf(x);
	new_y = (int) floorf(y);
	if (map->data[new_x][new_y] == '0')
		return (1);
	return (0);
}
