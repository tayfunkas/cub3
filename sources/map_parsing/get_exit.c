/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grial <grial@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 09:33:31 by tkasapog          #+#    #+#             */
/*   Updated: 2025/06/11 11:07:19 by grial            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	get_exit(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (!map || !map->data)
	{
		printf("Map does not exist\n");
		return ;
	}
	while (map->data[y])
	{
		x = 0;
		while (map->data[y][x])
		{
			if (map->data[y][x] == 'Q')
			{
				map->pos_x = x;
				map->pos_y = y;
				map->exit++;
			}
			x++;
		}
		y++;
	}
}
