/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_player.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grial <grial@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 09:33:51 by tkasapog          #+#    #+#             */
/*   Updated: 2025/06/04 14:53:13 by grial            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	initialize_player(t_game *game)
{
	(game)->player = malloc(sizeof(t_player));
	if (!game->player)
		handle_error(game, "Memory allocation failed for player structure.");
	(game)->player->player_count = 0;
	(game)->player->dir = 0;
	(game)->player->pos_x = 0;
	(game)->player->pos_y = 0;
}

void	get_player_init_position(t_map *map, t_player *player)
{
	int	x;
	int	y;

	x = 0;
	if (!map || !map->data)
	{
		printf("Map does not exist\n");
		return ;
	}
	while (map->data[x])
	{
		y = 0;
		while (map->data[x][y])
		{
			if (is_player(map->data[x][y]))
			{
				player->pos_x = y + 0.5;
				player->pos_y = x + 0.5;
				player->player_count++;
				player->dir = player_dir(map->data[x][y]);
			}
			y++;
		}
		x++;
	}
}

int	is_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

int	player_dir(char c)
{
	if (c == 'E')
		return (0);
	if (c == 'N')
		return (90);
	if (c == 'W')
		return (180);
	if (c == 'S')
		return (270);
	return (0);
}
