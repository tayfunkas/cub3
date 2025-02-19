/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direcction_player.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grial <grial@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 19:12:05 by grial             #+#    #+#             */
/*   Updated: 2025/02/19 16:45:54 by grial            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

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
	if (key == UP || key == DOWN)
		game->player->player_dir++;
	if (key == DOWN)
		game->player->player_dir--;
	if (game->player->player_dir < 0)
		game->player->player_dir = 359;
	if (game->player->player_dir > 359)
		game->player->player_dir = 0;
}
//
//void	move_foward(t_game *game)
//{
//	
//}
//
//void	trace(t_game *game)
//{
//	
//}
//