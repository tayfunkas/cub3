/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grial <grial@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 19:12:05 by grial             #+#    #+#             */
/*   Updated: 2025/06/02 16:06:39 by grial            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	open_door(t_player *player, t_map *map);

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
	if (game->keys[SPACE])
		open_door(player, map);
}

void	open_door(t_player *player, t_map *map)
{
	double	angle;
	double	dx;
	double	dy;
	double	new_x;
	double	new_y;
	int		cell_x;
	int		cell_y;

	angle = player->dir * M_PI / 180.0;
	dx = cos(angle);
	dy = -sin(angle);

	new_x = player->pos_x + dx;
	new_y = player->pos_y + dy;

	cell_x = (int)new_x;
	cell_y = (int)new_y;

	if (map->data[cell_y][cell_x] == 'D')
		map->data[cell_y][cell_x] = '0'; // Abrimos la puerta
}

void	player_direction(t_player *player, int key)
{
	if (key == TURN_R)
		player->dir -= 1;
	else if (key == TURN_L)
		player->dir += 1;
	if (player->dir < 0)
		player->dir = 359;
	else if (player->dir > 359)
		player->dir = 0;
}

void	player_move(t_player *player, t_map *map, int key)
{
	double	angle;
	double	dx;
	double	dy;
	double	new_x;
	double	new_y;

	new_x = 0;
	new_y = 0;
	
	
	angle = player->dir * M_PI / 180.0;
	dx = cos(angle) * STEP;
	dy = -sin(angle) * STEP;

	if (key == FORWARD)
	{
		new_x = player->pos_x + dx;
		new_y = player->pos_y + dy;
	}
	else if (key == BACKWARD)
	{
		new_x = player->pos_x - dx;
		new_y = player->pos_y - dy;
	}
	if (check_collision(map, new_x, new_y))
	{
		player->pos_x = new_x;
		player->pos_y = new_y;
	}
}

void	player_strafe(t_player *player, t_map *map, int key)
{
	double	angle;
	double	dx;
	double	dy;
	double	new_x;
	double	new_y;

	angle = 0;
	if (key == RIGHT)
		angle = (player->dir + 90.0) * M_PI / 180.0;
	else if (key == LEFT)
		angle = (player->dir - 90.0) * M_PI / 180.0;

	dx = -cos(angle) * STEP;
	dy = sin(angle) * STEP;

	new_x = player->pos_x + dx;
	new_y = player->pos_y + dy;
	if (check_collision(map, new_x, new_y))
	{
		player->pos_x = new_x;
		player->pos_y = new_y;
	}
}

int	check_collision(t_map *map, float x, float y)
{
	int	new_x;
	int	new_y;

	new_x = (int) floorf(x);
	new_y = (int) floorf(y);
	if (map->data[new_y][new_x] != '1' && map->data[new_y][new_x] != 'D')
		return (1);
	return (0);
}