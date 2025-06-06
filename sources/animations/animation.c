/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grial <grial@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 09:33:51 by tkasapog          #+#    #+#             */
/*   Updated: 2025/06/06 14:32:48 by grial            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	check_close(t_player *player, t_map *map, t_rend *rcast)
{
	double	i;

	i = 1;
	player->new_dist = sqrt(pow(map->pos_x - player->pos_x, 2) + pow(map->pos_y
		- player->pos_y, 2));
	if (player->new_dist < player->prev_dist - 1)
	{
		player->prev_dist = player->new_dist +1;
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
