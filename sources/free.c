/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grial <grial@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 09:33:44 by tkasapog          #+#    #+#             */
/*   Updated: 2025/06/02 16:49:08 by grial            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/cub3d.h"

static void	free_all_others(t_game *game)
{
	if (game->engine)
		free(game->engine);
	if (game->mini)
		free_mini(game->mini, game->mlx_ptr);
	if (game->mlx_window)
	{
		mlx_clear_window(game->mlx_ptr, game->mlx_window);
		mlx_destroy_window(game->mlx_ptr, game->mlx_window);
	}
	if (game->mlx_ptr)
	{
		//mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
		game->mlx_ptr = NULL;
	}
	if (game->keys)
		free(game->keys);
	if (game->player)
		free(game->player);
	if (game->config)
		free(game->config);
}

int	free_game(t_game *game)
{
	if (!game)
		return (0);
	free_engine_images(game->engine, game->mlx_ptr);
	free_engine_texture(game->engine);
	free_all_others(game);
	if (game->map)
		free_map(game->map);
	if (game->error == 1)
	{
		free(game);
		exit(1);
	}
	free(game);
	exit(0);
}

void	free_engine_images(t_engine *engine, void *mlx_ptr)
{
	if (!engine)
		return ;
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

void	free_mini(t_mini *mini, void *mlx_ptr)
{
	if (mlx_ptr)
	{
		if (mini->wall)
		{
			mlx_destroy_image(mlx_ptr, mini->wall);
			mini->wall = NULL;
		}
		if (mini->door)
		{
			mlx_destroy_image(mlx_ptr, mini->door);
			mini->door = NULL;
		}
		if (mini->floor)
		{
			mlx_destroy_image(mlx_ptr, mini->floor);
			mini->floor = NULL;
		}
		if (mini->player)
		{
			mlx_destroy_image(mlx_ptr, mini->player);
			mini->player = NULL;
		}
	}
	free(mini);
}

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	if (map->data)
	{
		while (map->data[i])
		{
			free(map->data[i]);
			i++;
		}
		free(map->data);
	}
	free(map);
}
