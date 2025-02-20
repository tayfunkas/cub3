/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grial <grial@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 09:33:51 by tkasapog          #+#    #+#             */
/*   Updated: 2025/02/20 15:57:02 by grial            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/cub3d.h"

void	initialize_game(t_game **game)
{
	*game = malloc(sizeof(t_game));
	if (!*game)
		handle_error(*game, "Memory allocation failied for game structure.");
	(*game)->mlx_ptr = NULL;
	(*game)->mlx_window = NULL;
	(*game)->no_texture = NULL;
	(*game)->so_texture = NULL;
	(*game)->we_texture = NULL;
	(*game)->ea_texture = NULL;
	(*game)->map_file = NULL;
	(*game)->floor_color = (t_color){.r = -1, .g = -1, .b = -1};
	(*game)->ceiling_color = (t_color){.r = -1, .g = -1, .b = -1};
	(*game)->map = malloc(sizeof(t_map));
	if (!(*game)->map)
		handle_error(*game, "Memory allocation failed for map structure.");
	(*game)->map->m_height = 0;
	(*game)->map->m_width = 0;
	(*game)->map->data = NULL;
	(*game)->map->line_count = 0;
	initialize_player(*game);
}

void	initialize_player(t_game *game)
{
	(game)->player = malloc(sizeof(t_player));
	if (!game->player)
		handle_error(game, "Memory allocation failed for player structure.");
	(game)->player->player_count = 0;
	(game)->player->player_dir = 0;
	(game)->player->player_x = 0;
	(game)->player->player_y = 0;
}

void	get_player_init_position(t_map *map, t_player *player)
{
	int	x;
	int	y;

	if (!map->data)
		printf("Does not exist\n");
	x = 0;
	while (map->data[x])
	{
		y = 0;
		while (map->data[x][y])
		{
			if (is_player(map->data[x][y]))
			{
				player->player_x = x;
				player->player_y = y;
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
