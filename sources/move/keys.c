#include "../inc/cub3d.h"

int	key_press(int key, t_game *game)
{
	if (key >= 0 && key < MAX_KEYCODE)
		game->keys[key] = 1;
	if (key == ESCAPE)
		free_game(game);
	return (0);
}

int	key_release(int key, t_game *game)
{
	if (key >= 0 && key < MAX_KEYCODE)
		game->keys[key] = 0;
	return (0);
}
