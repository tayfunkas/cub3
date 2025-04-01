/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasapog <tkasapog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 19:12:05 by grial             #+#    #+#             */
/*   Updated: 2025/04/01 15:36:55 by tkasapog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	handle_movement(t_game *game)
{
	t_player	*player;
	t_map		*map;

	player = game->player;
	map = game->map;
	if (game->keys[FORWARD])
		player_move(player, map, FORWARD);
	if (game->keys[BACKWARD])
		player_move(player, map, BACKWARD);
	if (game->keys[LEFT])
		player_strafe(player, map, LEFT);
	if (game->keys[RIGHT])
		player_strafe(player, map, RIGHT);
	if (game->keys[TURN_L])
		player_direction(player, TURN_L);
	if (game->keys[TURN_R])
		player_direction(player, TURN_R);
	if (game->keys[ESCAPE])
		free_game(game);
}

void	player_direction(t_player *player, int key)
{
	if (key == TURN_R)
		player->player_dir = (player->player_dir + 4) % 360;
	else if (key == TURN_L)
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

void	player_strafe(t_player *player, t_map *map, int key)
{
	double	angle;
	double	dx;
	double	dy;
	double	new_x; 
	double	new_y;

	angle = 0.00;
	if (key == RIGHT)
		angle = (player->player_dir + 90) * M_PI / 180.0;
	else if (key == LEFT)
		angle = (player->player_dir - 90) * M_PI / 180.0;
	dy = cos(angle) * STEP;
	dx = -sin(angle) * STEP;
	new_x = player->player_x + dx;
	new_y = player->player_y + dy;
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
	if (map->data[new_x][new_y] != '1')
		return (1);
	return (0);
}
