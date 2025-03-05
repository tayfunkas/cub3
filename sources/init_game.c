/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grial <grial@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:51:00 by grial             #+#    #+#             */
/*   Updated: 2025/03/05 14:34:52 by grial            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/cub3d.h"

void	load_img(t_game *game);
void	*hook_img(t_game *game, char c);
int		render(t_game *game);

void	init_frame(t_game *game, t_img *frame)
{
	frame->img = mlx_new_image(game->mlx_ptr, WIN_W, WIN_W);
	frame->img_data = mlx_get_data_addr(frame->img, 
		&frame->bpp, &frame->size_line, &frame->endian);
}

void	init_game(t_game *game)
{
	game->mlx_ptr = mlx_init();
	init_frame(game, game->engine->frame);
	game->mlx_window = mlx_new_window(game->mlx_ptr, WIN_W, 
			WIN_H, "Cub3D");
	load_img(game);
	mlx_loop_hook(game->mlx_ptr, render, game);
	mlx_hook(game->mlx_window, 2, KeyPressMask, keys_player, game);
	mlx_loop(game->mlx_ptr);
}

int render(t_game *game)
{
	int	x = 0;
	int	y = 0;

	usleep(10000);
	mlx_clear_window(game->mlx_ptr, game->mlx_window);
	while (game->map->data[x])
	{
		y = 0;
		while (game->map->data[x][y])
		{
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_window, hook_img(game, game->map->data[x][y]), y * MIN_S, x * MIN_S);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_window, game->mini->player, game->player->player_y * MIN_S, game->player->player_x * MIN_S);
	draw_fov(game, game->player);
	return (1);
}

void	*hook_img(t_game *game, char c)
{
	if (c == '1')
		return (game->mini->wall);
	else
		return (game->mini->floor);
	return (NULL);
}

void	load_img(t_game *game)
{
	int	img_width;
	int	img_height;

	game->mini = malloc(sizeof(t_mini));
	if (!game->mini)
	{
		ft_putstr_fd("Error: game->mini not initialized\n", 2);
		exit(EXIT_FAILURE);
	}
	game->mini->wall = mlx_xpm_file_to_image(game->mlx_ptr, 
			"textures/mini_map/wall.xpm", &img_width, &img_height);
	if (!game->mini->wall)
	{
		ft_putstr_fd("Error: Failed to load wall texture\n", 2);
		exit(EXIT_FAILURE);
	}
	game->mini->floor = mlx_xpm_file_to_image(game->mlx_ptr, 
			"textures/mini_map/floor.xpm", &img_width, &img_height);
	if (!game->mini->floor)
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
	game->engine->text[0] = mlx_xpm_file_to_image(game->mlx_ptr, game->engine->NO, &img_width, &img_height);
	if (!game->engine->text[0])
	{
		ft_putstr_fd("Error: Failed to load player texture\n", 2);
		exit(EXIT_FAILURE);
	}
	game->engine->text[1] = mlx_xpm_file_to_image(game->mlx_ptr, game->engine->EA, &img_width, &img_height);
	if (!game->engine->text[1])
	{
		ft_putstr_fd("Error: Failed to load player texture\n", 2);
		exit(EXIT_FAILURE);
	}
	game->engine->text[2] = mlx_xpm_file_to_image(game->mlx_ptr, game->engine->SO, &img_width, &img_height);
	if (!game->engine->text[2])
	{
		ft_putstr_fd("Error: Failed to load player texture\n", 2);
		exit(EXIT_FAILURE);
	}
	game->engine->text[3] = mlx_xpm_file_to_image(game->mlx_ptr, game->engine->WE, &img_width, &img_height);
	if (!game->engine->text[3])
	{
		ft_putstr_fd("Error: Failed to load player texture\n", 2);
		exit(EXIT_FAILURE);
	}
}
