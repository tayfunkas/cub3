/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grial <grial@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 09:33:44 by tkasapog          #+#    #+#             */
/*   Updated: 2025/03/31 15:48:26 by grial            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/cub3d.h"

int	free_game(t_game *game)
{
	if (!game)
		return (0);
	if (game->mlx_window)
	{
		mlx_clear_window(game->mlx_ptr, game->mlx_window);
		mlx_destroy_window(game->mlx_ptr, game->mlx_window);
	}
	if (game->mlx_ptr)
	{
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
		game->mlx_ptr = NULL;
	}
	free(game->engine->no_texture);
	free(game->engine->so_texture);
	free(game->engine->we_texture);
	free(game->engine->ea_texture);
	if (game->map)
		free(game->map);
	if (game->player)
		free(game->player);
	free(game);
	exit(0);
	return (0);
}

void	handle_error(t_game *game, const char *error_message)
{
	printf("Error\n%s\n", error_message);
	free_game(game);
	exit(1);
}
