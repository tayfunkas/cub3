/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grial <grial@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:51:00 by grial             #+#    #+#             */
/*   Updated: 2025/03/03 16:03:47 by grial            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/cub3d.h"

void	load_img(t_game *game);
void	*hook_img(t_game *game, char c);
int		render(t_game *game);

void	init_game(t_game *game)
{
	game->mlx_ptr = mlx_init();
	printf("%i x %i\n", game->map->m_height, game->map->m_width);
	game->mlx_window = mlx_new_window(game->mlx_ptr, WIN_W, 
			WIN_H, "so_long");
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
	game->text->NO->img = mlx_xpm_file_to_image(game->mlx_ptr, 
		"textures/NO.xpm", &game->text->NO->width, &game->text->NO->height);
	if (!game->text->NO->img)
	{
		ft_putstr_fd("Error: Failed to load player texture\n", 2);
		exit(EXIT_FAILURE);
	}
	game->text->EA->img = mlx_xpm_file_to_image(game->mlx_ptr, 
		"textures/EA.xpm", &game->text->EA->width, &game->text->EA->height);
	if (!game->text->EA->img)
	{
		ft_putstr_fd("Error: Failed to load player texture\n", 2);
		exit(EXIT_FAILURE);
	}
	game->text->SO->img = mlx_xpm_file_to_image(game->mlx_ptr, 
		"textures/SO.xpm", &game->text->SO->width, &game->text->SO->height);
	if (!game->text->SO->img)
	{
		ft_putstr_fd("Error: Failed to load player texture\n", 2);
		exit(EXIT_FAILURE);
	}
	game->text->WE->img = mlx_xpm_file_to_image(game->mlx_ptr, 
		"textures/WE.xpm", &game->text->WE->width, &game->text->WE->height);
	if (!game->text->WE->img)
	{
		ft_putstr_fd("Error: Failed to load player texture\n", 2);
		exit(EXIT_FAILURE);
	}
	game->text->NO->addr = mlx_get_data_addr(game->text->NO->img, &game->text->NO->bpp, &game->text->NO->line_len, &game->text->NO->endian);
	game->text->EA->addr = mlx_get_data_addr(game->text->EA->img, &game->text->EA->bpp, &game->text->EA->line_len, &game->text->EA->endian);
	game->text->SO->addr = mlx_get_data_addr(game->text->SO->img, &game->text->SO->bpp, &game->text->SO->line_len, &game->text->SO->endian);
	game->text->WE->addr = mlx_get_data_addr(game->text->WE->img, &game->text->WE->bpp, &game->text->WE->line_len, &game->text->WE->endian);
}
