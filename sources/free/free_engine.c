/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_engine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grial <grial@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 18:48:14 by tkasapog          #+#    #+#             */
/*   Updated: 2025/06/04 17:12:05 by grial            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	free_engine(t_engine *engine, void *mlx_ptr)
{
	if (engine->ray)
		free(engine->ray);
	engine->ray = NULL;
	if (engine->rcast)
		free(engine->rcast);
	engine->rcast = NULL;
	free_img(mlx_ptr, &engine->frame);
	free_img(mlx_ptr, &engine->no_img);
	free_img(mlx_ptr, &engine->so_img);
	free_img(mlx_ptr, &engine->we_img);
	free_img(mlx_ptr, &engine->ea_img);
	free_img(mlx_ptr, &engine->dr_img);
	free_color(&engine->floor_color);
	free_color(&engine->ceiling_color);
	free(engine->no_path);
	free(engine->so_path);
	free(engine->we_path);
	free(engine->ea_path);
	free(engine->dr_path);
	engine->no_path = NULL;
	engine->so_path = NULL;
	engine->we_path = NULL;
	engine->ea_path = NULL;
	engine->dr_path = NULL;
}

void	free_img(void *mlx_ptr, t_img **img)
{
	if (*img)
	{
		if ((*img)->img)
			mlx_destroy_image(mlx_ptr, (*img)->img);
		free(*img);
		*img = NULL;
	}
}

void	free_texture_path(t_engine *engine)
{
	if (engine->no_path)
		free(engine->no_path);
	if (engine->so_path)
		free(engine->so_path);
	if (engine->we_path)
		free(engine->we_path);
	if (engine->ea_path)
		free(engine->ea_path);
}

void	free_color(t_color **color)
{
	if (*color)
	{
		free(*color);
		*color = NULL;
	}
}

