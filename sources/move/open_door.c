/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_door.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grial <grial@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 19:12:05 by grial             #+#    #+#             */
/*   Updated: 2025/06/04 10:44:26 by grial            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	open_door(t_player *player, t_map *map)
{
	double	new_x;
	double	new_y;
	int		cell_x;
	int		cell_y;

	new_x = player->pos_x + (cos(player->dir * M_PI / 180.0));
	new_y = player->pos_y + (-sin(player->dir * M_PI / 180.0));
	cell_x = (int)new_x;
	cell_y = (int)new_y;
	if (map->data[cell_y][cell_x] == 'D')
		map->data[cell_y][cell_x] = '0';
}
