/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grial <grial@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 18:29:56 by tkasapog          #+#    #+#             */
/*   Updated: 2025/06/02 17:17:04 by grial            ###   ########.fr       */
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
		game->player->dir -= delta_x * 0.5;
		if (game->player->dir < 0)
			game->player->dir += 360;
		if (game->player->dir >= 360)
			game->player->dir -= 360;
		last_x = x;
	}
	return (0);
}
