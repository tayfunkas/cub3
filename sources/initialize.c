/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasapog <tkasapog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 09:33:51 by tkasapog          #+#    #+#             */
/*   Updated: 2025/04/01 20:16:43 by tkasapog         ###   ########.fr       */
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
	(*game)->map_file = NULL;
	(*game)->floor_color = (t_color){.r = -1, .g = -1, .b = -1};
	(*game)->ceiling_color = (t_color){.r = -1, .g = -1, .b = -1};
	(*game)->keys = ft_calloc(MAX_KEYCODE, sizeof(int));
	if (!(*game)->keys)
		handle_error(*game, "Memory allocation failed for keys array.");
	(*game)->map = malloc(sizeof(t_map));
	if (!(*game)->map)
		handle_error(*game, "Memory allocation failed for map structure.");
	(*game)->map->m_height = 0;
	(*game)->map->m_width = 0;
	(*game)->map->data = NULL;
	(*game)->map->line_count = 0;
	initialize_player(*game);
	initialize_engine(*game);
	initialize_mini(*game);
}

void	initialize_engine(t_game *game)
{
	game->engine = malloc(sizeof(t_engine));
	if (!game->engine)
		return ;
	game->engine->ang_step = 0;
	game->engine->frame = malloc(sizeof(t_img)); 
	game->engine->frame->img = NULL;
	game->engine->no_texture = NULL;
	game->engine->so_texture = NULL;
	game->engine->we_texture = NULL;
	game->engine->ea_texture = NULL;
	game->engine->no_img = malloc(sizeof(t_img));
	if (!game->engine->no_img)
		return ;
	game->engine->no_img->img = NULL;
	game->engine->so_img = malloc(sizeof(t_img));
	if (!game->engine->so_img)
		return ;
	game->engine->so_img->img = NULL;
	game->engine->we_img = malloc(sizeof(t_img));
	if (!game->engine->we_img)
		return ;
	game->engine->we_img->img = NULL;
	game->engine->ea_img = malloc(sizeof(t_img));
	if (!game->engine->ea_img)
		return ;
	game->engine->ea_img->img = NULL;
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

	if (!map || !map->data)
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
	printf("Initial position of the player acquired\n");
}

void	initialize_mini(t_game *game)
{
	game->mini = ft_calloc(1, sizeof(t_mini));
	if (!game->mini)
		handle_error(game, "Failed to allocate mini");
	game->mini->wall = NULL;
	game->mini->door = NULL;
	game->mini->floor = NULL;
	game->mini->player = NULL;
	printf("Allocated mini struct: %p\n", game->mini);
}

int	is_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}
