/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grial <grial@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 09:34:02 by tkasapog          #+#    #+#             */
/*   Updated: 2025/02/20 16:09:23 by grial            ###   ########.fr       */
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
	printf("Game struct initialized succesfully!\n");
	parse_arguments(argc, argv, game);
	printf("Arguments parsed succesfully!\n");
	parse_file(game);
	printf("Map file parsed succesfully!\n");
	if (game->player->player_count == 0)
		handle_error(game, "No player on the map!");
	check_images(game);
	printf("Texture files are checked!\n");
	get_player_init_position(game->map, game->player);
	//printf("PLAYER POS: X:%ld Y:%ld\n", game->player->player_x, game->player->player_y);
	validate_map(game);
	printf("Map is valid!\n");
	init_game(game);
	free_game(game);
	printf("All is freed. All good!\n");
	return (0);
}
