/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grial <grial@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:51:00 by grial             #+#    #+#             */
/*   Updated: 2025/01/07 16:10:58 by grial            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3.h"

void	init_game(t_game *game)
{
    game->mlx_ptr = mlx_init();
	printf("%i x %i\n", game->map->m_height, game->map->m_width);
	game->mlx_window = mlx_new_window(game->mlx_ptr, WIN_H, 
			WIN_W, "so_long");
    mlx_key_hook(game->mlx_window, key_hook, game);
	mlx_hook(game->mlx_window, DestroyNotify, ButtonPressMask, 
		free_game, game);
	mlx_loop(game->mlx_ptr);

}

int	key_hook(int key, t_game *game)
{
	if (key == ESCAPE)
		free_game(game);
	//else if (key == LEFT || key == UP || key == RIGHT || key == DOWN)
	//	move_player(key, game);
	return (1);
}