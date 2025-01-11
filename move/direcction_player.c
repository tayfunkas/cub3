/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direcction_player.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grial <grial@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 19:12:05 by grial             #+#    #+#             */
/*   Updated: 2025/01/10 19:20:20 by grial            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources/cub3.h"

void	direcction_player(int key, t_game *game)
{
	if (key == LEFT)
		game->player->player_dir++;
	if (key == RIGHT)
		game->player->player_dir--;
	if (game->player->player_dir < 0)
		game->player->player_dir = 359;
	if (game->player->player_dir > 359)
		game->player->player_dir = 0;
	printf("%i\n", game->player->player_dir);
}

void	move_player(int key, t_game *game)
{
	if (key == UP)
		game->player->player_dir++;
	if (key == LEFT)
		game->player->player_dir--;
	if (game->player->player_dir < 0)
		game->player->player_dir = 359;
	if (game->player->player_dir > 359)
		game->player->player_dir = 0;
}