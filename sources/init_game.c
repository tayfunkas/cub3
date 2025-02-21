/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grial <grial@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:51:00 by grial             #+#    #+#             */
/*   Updated: 2025/02/21 19:17:47 by grial            ###   ########.fr       */
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
	game->mlx_window = mlx_new_window(game->mlx_ptr, WIN_H, 
			WIN_W, "so_long");
	load_img(game);
	mlx_loop_hook(game->mlx_ptr, render, game);
	mlx_hook(game->mlx_window, 2, KeyPressMask, keys_player, game);
	mlx_loop(game->mlx_ptr);
}

int render(t_game *game)
{
	int	size = 8;
	int	x = 0;
	int	y = 0;

	usleep(10000);
	mlx_clear_window(game->mlx_ptr, game->mlx_window);
	while (game->map->data[x])
	{
		y = 0;
		while (game->map->data[x][y])
		{
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_window, hook_img(game, game->map->data[x][y]), y * size, x * size);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_window, game->mini->player, game->player->player_y * size, game->player->player_x * size);
	rc_fov(game, game->player, game->map);
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
