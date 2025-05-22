/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasapog <tkasapog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 18:29:56 by tkasapog          #+#    #+#             */
/*   Updated: 2025/04/28 18:31:25 by tkasapog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	key_press(int key, t_game *game)
{
	if (key >= 0 && key < MAX_KEYCODE)
		game->keys[key] = 1;
	if (key == ESCAPE)
		free_game(game);
	return (0);
}

int	key_release(int key, t_game *game)
{
	if (key >= 0 && key < MAX_KEYCODE)
		game->keys[key] = 0;
	return (0);
}

void	player_direction(t_player *player, int key)
{
	if (key == TURN_R)
		player->player_dir = (player->player_dir + 4) % 360;
	else if (key == TURN_L)
		player->player_dir = (player->player_dir - 4 + 360) % 360;
}

int	mouse_move(int x, int y, t_game *game)
{
	static int	last_x = -1;
	int			delta_x;

	(void)y;
	if (last_x == -1)
	{
		last_x = x;
		return (0);
	}
	delta_x = x - last_x;
	if (delta_x != 0)
	{
		game->player->player_dir -= delta_x * 0.5;
		if (game->player->player_dir < 0)
			game->player->player_dir += 360;
		if (game->player->player_dir >= 360)
			game->player->player_dir -= 360;
		last_x = x;
	}
	return (0);
}
