/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grial <grial@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:51:00 by grial             #+#    #+#             */
/*   Updated: 2025/06/11 11:19:36 by grial            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/cub3d.h"

/*void	load_img(t_game *game);
void		*hook_img(t_game *game, char c);
int	render(t_game *game);*/

static void	get_vision(t_map *map)
{
	int	vision;

	vision = 0;
	if (map->m_height > map->m_width)
		vision = map->m_height;
	else
		vision = map->m_width;
	map->vision = vision;
}

void	init_game(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		handle_error(game, "Failed to initialize MLX");
	game->engine->frame = malloc(sizeof(t_img));
	game->mlx_window = mlx_new_window(game->mlx_ptr, WIN_W, WIN_H, "cub3D");
	game->engine->frame->img = mlx_new_image(game->mlx_ptr, WIN_W, WIN_H);
	game->engine->frame->addr = mlx_get_data_addr(game->engine->frame->img,
			&game->engine->frame->bpp, &game->engine->frame->line_length,
			&game->engine->frame->endian);
	if (!game->engine->frame->img || !game->engine->frame->addr)
		handle_error(game, "Failed to create or retrieve image data");
	load_img(game);
	get_vision(game->map);
	mlx_hook(game->mlx_window, 17, 0, free_game, game);
	mlx_hook(game->mlx_window, 2, 1L << 0, key_press, game);
	mlx_hook(game->mlx_window, 3, 1L << 1, key_release, game);
	mlx_hook(game->mlx_window, 6, PointerMotionMask, mouse_move, game);
	printf("A\n");
	mlx_loop_hook(game->mlx_ptr, render, game);
	printf("B\n");
	mlx_loop(game->mlx_ptr);
}

void	clear_image(t_game *game, int color)
{
	int	x;
	int	y;

	y = 0;
	while (y < WIN_H)
	{
		x = 0;
		while (x < WIN_W)
		{
			my_mlx_pixel_put(game, x, y, color);
			x++;
		}
		y++;
	}
}

void	*hook_img(t_game *game, char c)
{
	if (c == '1')
		return (game->mini->mini_wall);
	else
		return (game->mini->mini_floor);
	return (NULL);
}
