#include "cub3.h"

int	key_hook(int key, t_game *game);

void    init_game(t_game *game)
{
    game->mlx_ptr = mlx_init();
	game->mlx_window = mlx_new_window(game->mlx_ptr, game->map->m_height, 
			game->map->m_width, "so_long");
    mlx_key_hook(game->mlx_window, key_hook, game);
}

int	key_hook(int key, t_game *game)
{
	if (key == ESCAPE)
		destroy_game(game);
	else if (key == LEFT || key == UP || key == RIGHT || key == DOWN)
		move_player(key, game);
	return (1);
}