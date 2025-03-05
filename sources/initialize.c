#include "inc/cub3d.h"

t_game	*initialize_game(void)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
	{
		fprintf(stderr, "Memory allocation failed for game structure.\n");
		exit(EXIT_FAILURE);
	}
	game->mlx_ptr = NULL;
	game->mlx_window = NULL;
	game->map_file = NULL;

	game->map = malloc(sizeof(t_map));
	if (!game->map)
	{
		free(game);
		handle_error(NULL, "Memory allocation failed for map structure.");
	}
	game->map->m_height = 0;
	game->map->m_width = 0;
	game->map->data = NULL;
	game->map->line_count = 0;

	game->engine = init_engine();
	if (!game->engine)
	{
		free(game->map);
		free(game);
		handle_error(NULL, "Memory allocation failed for engine.");
	}
	initialize_player(game);
	return (game);
}

t_engine	*init_engine(void)
{
	t_engine	*engine;

	engine = malloc(sizeof(t_engine));
	if (!engine)
		return (NULL);

	engine->NO = NULL;
	engine->EA = NULL;
	engine->SO = NULL;
	engine->WE = NULL;
	engine->floor = (t_color){.r = -1, .g = -1, .b = -1};
	engine->ceiling = (t_color){.r = -1, .g = -1, .b = -1};

	engine->frame = malloc(sizeof(t_img));
	if (!engine->frame)
	{
		free(engine);
		return (NULL);
	}
	engine->frame->img = NULL;
	engine->frame->img_data = NULL;
	return (engine);
}

void	initialize_player(t_game *game)
{
	game->player = malloc(sizeof(t_player));
	if (!game->player)
	{
		free(game->engine->frame);
		free(game->engine);
		free(game->map);
		free(game);
		handle_error(NULL, "Memory allocation failed for player structure.");
	}
	game->player->player_count = 0;
	game->player->player_dir = 0;
	game->player->player_x = 0;
	game->player->player_y = 0;
}

void	get_player_init_position(t_map *map, t_player *player)
{
	int	x;
	int	y;

	if (!map->data)
		handle_error(NULL, "Map data is not initialized.");

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
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}
