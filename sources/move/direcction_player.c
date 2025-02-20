/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direcction_player.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grial <grial@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 19:12:05 by grial             #+#    #+#             */
/*   Updated: 2025/02/20 19:02:06 by grial            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	math(t_player *player, int key);
int		get_quarter(t_player *player);

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
		math(game->player, key);
}

int	get_quarter(t_player *player)
{
	if (player->player_dir > 0 && player->player_dir < 90)
		return (0);
	if (player->player_dir > 90 && player->player_dir < 180)
		return (90);
	if (player->player_dir > 180 && player->player_dir < 270)
		return (180);
	if (player->player_dir > 270 && player->player_dir < 360)
		return (270);
	return (0);
}

void	math(t_player *player, int key)
{
	double	ang;
	double	x;
	double	y;
	int		quarter;

	quarter = get_quarter(player);
	ang = (player->player_dir - quarter) * M_PI / 180.0;
	x = cos(ang) * STEP;
	y = sin(ang) * STEP;
	if (key == UP)
	{
		if (quarter == 0 || quarter == 270)
			player->player_x += x;
		else
			player->player_x -= x;
		if (quarter == 0 || quarter == 90)
			player->player_y += y;
		else
			player->player_y -= y;
	}
	if (key == DOWN)
	{
		if (quarter == 0 || quarter == 270)
			player->player_x += x;
		else
			player->player_x -= x;
		if (quarter == 0 || quarter == 90)
			player->player_y += y;
		else
			player->player_y -= y;
	}

}
