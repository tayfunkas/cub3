/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrielrial <gabrielrial@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 09:34:02 by tkasapog          #+#    #+#             */
/*   Updated: 2025/06/09 00:35:29 by gabrielrial      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/cub3d.h"

void	parse_arguments(int argc, char **argv, t_game *game)
{
	if (argc != 2)
		handle_error(game, "Usage: ./cub3 <map_file.cub>");
	check_mapfile_name(game, argv[1]);
	game->map_file = argv[1];
}

int	main(int argc, char **argv)
{
	t_game	*game;

	game = NULL;
	initialize_game(&game);
	parse_arguments(argc, argv, game);
	parse_file(game);
	check_images(game);
	validate_map(game);
	get_player_init_position(game->map, game->player);
	if (game->player->player_count == 0)
		game->error = 1;
	if (game->error == 1)
		handle_error(game, "Issue with the map file");
	check_player_position(game);
	init_game(game);
	free_game(game);
	return (0);
}
