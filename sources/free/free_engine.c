/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_engine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grial <grial@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 18:48:14 by tkasapog          #+#    #+#             */
/*   Updated: 2025/06/04 15:07:40 by grial            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/cub3d.h"

void	free_engine(t_game *game)
{
	t_engine *ptr;

	if (!game->engine)
		return ;
	ptr = game->engine;

	if (ptr->ray)
		free(ptr->ray);
	ptr->ray = NULL;
	if (ptr->rcast)
		free(ptr->rcast);
	ptr->rcast = NULL;
	free_engine_images(ptr);
	
	
	
}

static void	free_engine_images1(t_engine *engine, void *mlx_ptr)
{

}

void	free_engine_images(t_engine *engine, void *mlx_ptr)
{
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
	if (engine->no_path)
		free(engine->no_path);
	if (engine->so_path)
		free(engine->so_path);
	if (engine->we_path)
		free(engine->we_path);
	if (engine->ea_path)
		free(engine->ea_path);
}

void	handle_error(t_game *game, const char *error_message)
{
	printf("Error\n%s\n", error_message);
	game->error = 1;
	if (game)
		free_game(game);
	exit(1);
}
