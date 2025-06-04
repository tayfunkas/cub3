/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grial <grial@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 09:33:44 by tkasapog          #+#    #+#             */
/*   Updated: 2025/06/04 15:57:52 by grial            ###   ########.fr       */
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


void	free_mini(t_mini *mini, void *mlx_ptr)
{
	if (mlx_ptr)
	{
		if (mini->mini_wall)
		{
			mlx_destroy_image(mlx_ptr, mini->mini_wall);
			mini->mini_wall = NULL;
		}
		if (mini->mini_door)
		{
			mlx_destroy_image(mlx_ptr, mini->mini_door);
			mini->mini_door = NULL;
		}
		if (mini->mini_floor)
		{
			mlx_destroy_image(mlx_ptr, mini->mini_floor);
			mini->mini_floor = NULL;
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
