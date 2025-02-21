/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grial <grial@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 19:12:05 by grial             #+#    #+#             */
/*   Updated: 2025/02/21 18:45:23 by grial            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	keys_player(int key, t_game *game)
{
	if (key == ESCAPE)
		free_game(game);
	if (key == FORWARD || key == BACKWARD)
		player_move(game->player, game->map, key);
	if (key == TURN_L || key == TURN_R)
		player_direction(game->player, key);
	return (0);
}

void	player_direction(t_player *player, int key)
{
	if (key == TURN_L)
		player->player_dir = (player->player_dir + 4) % 360;
	else if (key == TURN_R)
		player->player_dir = (player->player_dir - 4 + 360) % 360;
}

void	player_move(t_player *player, t_map *map, int key)
{
	double	angle;
	double	dx;
	double	dy;
	double	new_x;
	double	new_y;

	new_x = 0.0;
	new_y = 0.0;
	angle = player->player_dir * M_PI / 180.0;
	dy = cos(angle) * STEP;
	dx = -sin(angle) * STEP;
	if (key == FORWARD)
	{
		new_x = player->player_x + dx;
		new_y = player->player_y + dy;
	}
	else if (key == BACKWARD)
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
