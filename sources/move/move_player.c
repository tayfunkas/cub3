/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrielrial <gabrielrial@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 19:12:05 by grial             #+#    #+#             */
/*   Updated: 2025/05/13 16:17:17 by gabrielrial      ###   ########.fr       */
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
		player->dir -= 0.05;
	else if (key == TURN_L)
		player->dir += 0.05;
	if (player->dir < 0)
		player->dir += 2 * M_PI;
	else if (player->dir >= 2 * M_PI)
		player->dir -= 2 * M_PI;
	printf("D: %f\n", player->dir);
}

void	player_move(t_player *player, t_map *map, int key)
{
	double	dx;
	double	dy;
	double	new_x;
	double	new_y;

	new_x = 0.0;
	new_y = 0.0;
	dy = cos(player->dir) * STEP;
	dx = -sin(player->dir) * STEP;
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

	angle = 0.0;
	// Calcular el ángulo de movimiento lateral en función de la dirección del jugador
	if (key == RIGHT)
		angle = player->dir + M_PI_2; // 90° en radianes para moverse a la derecha
	else if (key == LEFT)
		angle = player->dir - M_PI_2; // -90° en radianes para moverse a la izquierda

	// Calcular los desplazamientos en X y Y
	dy = cos(angle) * STEP;
	dx = -sin(angle) * STEP; // El signo negativo es necesario para ajustarse a la dirección correcta

	// Calcular la nueva posición
	new_x = player->pos_x + dx;
	new_y = player->pos_y + dy;

	// Verificar colisiones antes de actualizar la posición
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
	if (new_x < 0 || new_y < 0 ||
		new_x >= map->m_height ||
		new_y >= (int)ft_strlen(map->data[new_x]) || 
		!map->data[new_x])
		return (0); 
	if (map->data[new_x][new_y] != '1')
		return (1);
	return (0);
}
