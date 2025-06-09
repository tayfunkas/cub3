/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grial <grial@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 19:12:05 by grial             #+#    #+#             */
/*   Updated: 2025/06/09 17:58:44 by grial            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	player_exit(t_game *game, t_player *player, t_map *map)
{
	if (map->data[(int)player->pos_y][(int)player->pos_x] == 'Q')
		game->engine->animation = 0;
}