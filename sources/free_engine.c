/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_engine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasapog <tkasapog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 18:48:14 by tkasapog          #+#    #+#             */
/*   Updated: 2025/04/25 18:51:14 by tkasapog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/cub3d.h"

static void	free_engine_images1(t_engine *engine, void *mlx_ptr)
{
	if (engine->no_img)
	{
		if (engine->no_img->img)
			mlx_destroy_image(mlx_ptr, engine->no_img->img);
		free(engine->no_img);
		engine->no_img = NULL;
	}
	if (engine->so_img)
	{
		if (engine->so_img->img)
			mlx_destroy_image(mlx_ptr, engine->so_img->img);
		free(engine->so_img);
		engine->so_img = NULL;
	}
	if (engine->we_img)
	{
		if (engine->we_img->img)
			mlx_destroy_image(mlx_ptr, engine->we_img->img);
		free(engine->we_img);
		engine->we_img = NULL;
	}
}

void	free_engine_images(t_engine *engine, void *mlx_ptr)
{
	if (!engine)
		return ;
	free_engine_images1(engine, mlx_ptr);
	if (engine->ea_img)
	{
		if (engine->ea_img->img)
			mlx_destroy_image(mlx_ptr, engine->ea_img->img);
		free(engine->ea_img);
		engine->ea_img = NULL;
	}
	if (engine->frame)
	{
		if (engine->frame->img)
			mlx_destroy_image(mlx_ptr, engine->frame->img);
		free(engine->frame);
		engine->frame = NULL;
	}
}

void	free_engine_texture(t_engine *engine)
{
	if (!engine)
		return ;
	if (engine->no_texture)
		free(engine->no_texture);
	if (engine->so_texture)
		free(engine->so_texture);
	if (engine->we_texture)
		free(engine->we_texture);
	if (engine->ea_texture)
		free(engine->ea_texture);
}

void	handle_error(t_game *game, const char *error_message)
{
	printf("Error\n%s\n", error_message);
	game->error = 1;
	if (game)
		free_game(game);
	exit(1);
}
