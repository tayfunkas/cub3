/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grial <grial@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:51:00 by grial             #+#    #+#             */
/*   Updated: 2025/03/28 19:24:35 by grial            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/cub3d.h"

void	load_img(t_game *game);
void	*hook_img(t_game *game, char c);
int		render(t_game *game);

void	init_game(t_game *game)
{
	game->mlx_ptr = mlx_init();
	game->mlx_window = mlx_new_window(game->mlx_ptr, WIN_W, 
		WIN_H, "cub3D");
	game->img_buffer = mlx_new_image(game->mlx_ptr, WIN_W, WIN_H);
	game->addr = mlx_get_data_addr(game->img_buffer, &game->bpp, &game->line_length, &game->endian);
	load_img(game);
	mlx_loop_hook(game->mlx_ptr, render, game);
	mlx_hook(game->mlx_window, 2, KeyPressMask, keys_player, game);
	mlx_hook(game->mlx_window, 6, PointerMotionMask, mouse_move, game);
	mlx_loop(game->mlx_ptr);
}

void	clear_image(t_game *game, int color)
{
	int	x, y;

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

int	render(t_game *game)
{
	//int	x = 0;
	//int	y = 0;

	usleep(10000);
	clear_image(game, 0x000000);
	mlx_clear_window(game->mlx_ptr, game->mlx_window);
	//while (game->map->data[x])
	//{
	//	y = 0;
	//	while (game->map->data[x][y])
	//	{
	//		mlx_put_image_to_window(game->mlx_ptr, game->mlx_window, hook_img(game, game->map->data[x][y]), y * MIN_S, x * MIN_S);
	//		y++;
	//	}
	//	x++;
	//}
//	mlx_put_image_to_window(game->mlx_ptr, game->mlx_window, game->mini->player, game->player->player_y * MIN_S, game->player->player_x * MIN_S);
	draw_fov(game, game->player);
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_window, game->img_buffer, 0, 0);
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
}

int	mouse_move(int x, int y, t_game *game)
{
	static int	last_x = -1;
	int	delta_x;

	(void)y;
	if (last_x == -1)
	{
		last_x = x;
		return (0);
	}
	delta_x = x - last_x;
	if(delta_x != 0)
	{
		game->player->player_dir -= delta_x * 0.5;
		if (game->player->player_dir < 0)
			game->player->player_dir += 360;
		if (game->player->player_dir >= 360)
			game->player->player_dir -= 360;
		last_x = x;
	}
	return (0);
}
