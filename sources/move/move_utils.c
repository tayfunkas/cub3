/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grial <grial@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 19:12:05 by grial             #+#    #+#             */
/*   Updated: 2025/06/09 17:55:21 by grial            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	check_close(t_player *player, t_map *map, t_rend *rcast)
{
	double	i;

	i = 1;
	player->new_dist = sqrt(pow(map->pos_x - player->pos_x, 2) + pow(map->pos_y
				- player->pos_y, 2));
	if (player->new_dist < player->prev_dist - 3)
	{
		player->prev_dist = player->new_dist;
		rcast->fps += (int)(65793 * i);
		i += 0.2;
	}
	if (i < 0)
		i = 1;
	if (rcast->fps > 16777215)
		rcast->fps = 0;
	if (rcast->fps < -16777214)
		rcast->fps = 0;
}

void	player_exit(t_game *game, t_player *player, t_map *map)
{
	if (map->data[(int)player->pos_y][(int)player->pos_x] == 'Q')
		game->engine->animation = 0;
}