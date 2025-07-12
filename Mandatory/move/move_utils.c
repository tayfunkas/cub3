/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grial <grial@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 19:12:05 by grial             #+#    #+#             */
/*   Updated: 2025/06/11 11:07:58 by grial            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	player_exit(t_game *game, t_player *player, t_map *map)
{
	if (map->data[(int)player->pos_y][(int)player->pos_x] == 'Q')
		game->engine->animation = 0;
}

int	corner_wall(t_map *map, t_player *p, float new_y, float new_x)
{
	if (new_y != p->pos_y && new_x != p->pos_x)
	{
		if (new_x > p->pos_x && !check_collision(map, new_x + STEP, p->pos_y))
			return (0);
		if (new_x < p->pos_x && !check_collision(map, new_x - STEP, p->pos_y))
			return (0);
	}
	return (1);
}
