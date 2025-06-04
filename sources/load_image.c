/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasapog <tkasapog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 17:19:35 by tkasapog          #+#    #+#             */
/*   Updated: 2025/06/04 17:34:18 by tkasapog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/cub3d.h"

static void	exit_with_error(char *msg)
{
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(msg, 2);
	ft_putchar_fd('\n', 2);
	exit(EXIT_FAILURE);
}

static void	load_img_and_check(void *mlx, t_img *img, char *path, t_game *game)
{
	int		width;
	int		height;
	void	*ptr;

	(void)game;
	width = 0;
	height = 0;
	ptr = mlx_xpm_file_to_image(mlx, path, &width, &height);
	if (!ptr)
		exit_with_error(path);
	img->img = ptr;
	img->addr = mlx_get_data_addr(img->img, &img->bpp, 
			&img->line_length, &img->endian);
}

static void	load_engine_textures(t_game *game)
{
	load_img_and_check(game->mlx_ptr, game->engine->no_img,
		"textures/NO.xpm", game);
	load_img_and_check(game->mlx_ptr, game->engine->dr_img,
		"textures/DR.xpm", game);
	load_img_and_check(game->mlx_ptr, game->engine->ea_img,
		"textures/EA.xpm", game);
	load_img_and_check(game->mlx_ptr, game->engine->so_img,
		"textures/SO.xpm", game);
	load_img_and_check(game->mlx_ptr, game->engine->we_img,
		"textures/WE.xpm", game);
}

static void	load_mini_textures(t_game *game)
{
	int	w;
	int	h;

	w = 0;
	h = 0;
	game->mini->mini_wall = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/mini_map/wall.xpm", &w, &h);
	if (!game->mini->mini_wall)
		exit_with_error("mini_wall");
	game->mini->mini_floor = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/mini_map/floor.xpm", &w, &h);
	if (!game->mini->mini_floor)
		exit_with_error("mini_floor");
	game->mini->player = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/mini_map/player.xpm", &w, &h);
	if (!game->mini->player)
		exit_with_error("mini_player");
}

void	load_img(t_game *game)
{
	if (!game->mini)
		exit_with_error("game->mini not initialized");
	load_mini_textures(game);
	load_engine_textures(game);
}
