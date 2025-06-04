/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grial <grial@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:51:00 by grial             #+#    #+#             */
/*   Updated: 2025/06/04 15:57:16 by grial            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/cub3d.h"

void	load_img(t_game *game);
void	*hook_img(t_game *game, char c);
int		render(t_game *game);

void	init_game(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		handle_error(game, "Failed to initialize MLX");
	game->mlx_window = mlx_new_window(game->mlx_ptr, WIN_W, WIN_H, "cub3D");
	game->engine->frame->img = mlx_new_image(game->mlx_ptr, WIN_W, WIN_H);
	game->engine->frame->addr = mlx_get_data_addr(game->engine->frame->img,
			&game->engine->frame->bpp, &game->engine->frame->line_length,
			&game->engine->frame->endian);
	if (!game->engine->frame->img || !game->engine->frame->addr)
		handle_error(game, "Failed to create or retrieve image data");
	load_img(game);
	mlx_hook(game->mlx_window, 17, 0, free_game, game);
	mlx_hook(game->mlx_window, 2, 1L << 0, key_press, game);
	mlx_hook(game->mlx_window, 3, 1L << 1, key_release, game);
	mlx_hook(game->mlx_window, 6, PointerMotionMask, mouse_move, game);
	mlx_loop_hook(game->mlx_ptr, render, game);
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

void	load_img(t_game *game)
{
	int	img_width;
	int	img_height;

	// game->mini = malloc(sizeof(t_mini));
	//		###     MINIMAP     ###
	if (!game->mini)
	{
		ft_putstr_fd("Error: game->mini not initialized\n", 2);
		exit(EXIT_FAILURE);
	}
	game->mini->mini_wall = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/mini_map/wall.xpm", &img_width, &img_height);
	if (!game->mini->mini_wall)
	{
		ft_putstr_fd("Error: Failed to load wall texture\n", 2);
		exit(EXIT_FAILURE);
	}
	game->mini->mini_floor = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/mini_map/floor.xpm", &img_width, &img_height);
	if (!game->mini->mini_floor)
	{
		ft_putstr_fd("Error: Failed to load floor texture\n", 2);
		exit(EXIT_FAILURE);
	}
	game->mini->player = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/mini_map/player.xpm", &img_width, &img_height);
	if (!game->mini->player)
	{
		ft_putstr_fd("Error: Failed to load player texture\n", 2);
		exit(EXIT_FAILURE);
	}
	//		###     TEXTURE     ###
	printf("load_img we should use char *path and not -texture/NO");
	game->engine->no_img->img = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/NO.xpm", &img_width, &img_height);
	if (!game->engine->no_img->img)
	{
		ft_putstr_fd("Error: Failed to load no texture\n", 2);
		exit(EXIT_FAILURE);
	}
	game->engine->no_img->addr = mlx_get_data_addr(game->engine->no_img->img,
			&game->engine->no_img->bpp, &game->engine->no_img->line_length,
			&game->engine->no_img->endian);
	game->engine->dr_img->img = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/DR.xpm", &img_width, &img_height);
	if (!game->engine->dr_img->img)
	{
		ft_putstr_fd("Error: Failed to load door texture\n", 2);
		exit(EXIT_FAILURE);
	}
	game->engine->dr_img->addr = mlx_get_data_addr(game->engine->dr_img->img,
			&game->engine->dr_img->bpp, &game->engine->dr_img->line_length,
			&game->engine->dr_img->endian);
	game->engine->ea_img->img = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/EA.xpm", &img_width, &img_height);
	if (!game->engine->ea_img)
	{
		ft_putstr_fd("Error: Failed to load ea texture\n", 2);
		exit(EXIT_FAILURE);
	}
	game->engine->ea_img->addr = mlx_get_data_addr(game->engine->ea_img->img,
			&game->engine->ea_img->bpp, &game->engine->ea_img->line_length,
			&game->engine->ea_img->endian);
	game->engine->so_img->img = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/SO.xpm", &img_width, &img_height);
	if (!game->engine->so_img)
	{
		ft_putstr_fd("Error: Failed to load so texture\n", 2);
		exit(EXIT_FAILURE);
	}
	game->engine->so_img->addr = mlx_get_data_addr(game->engine->so_img->img,
			&game->engine->so_img->bpp, &game->engine->so_img->line_length,
			&game->engine->so_img->endian);
	game->engine->we_img->img = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/WE.xpm", &img_width, &img_height);
	if (!game->engine->we_img)
	{
		ft_putstr_fd("Error: Failed to load we texture\n", 2);
		exit(EXIT_FAILURE);
	}
	game->engine->we_img->addr = mlx_get_data_addr(game->engine->we_img->img,
			&game->engine->we_img->bpp, &game->engine->we_img->line_length,
			&game->engine->we_img->endian);
}
