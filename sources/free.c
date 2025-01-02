/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasapog <tkasapog@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 09:33:44 by tkasapog          #+#    #+#             */
/*   Updated: 2025/01/02 09:33:46 by tkasapog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3.h"

void	free_game(t_game *game)
{
	if (!game)
		return ;
	free(game->no_texture);
	free(game->so_texture);
	free(game->we_texture);
	free(game->ea_texture);
	if (game->map)
		free(game->map);
	if (game->player)
		free(game->player);
	free(game);
}

void	handle_error(t_game *game, const char *error_message)
{
	printf("Error\n%s\n", error_message);
	free_game(game);
	exit(1);
}
