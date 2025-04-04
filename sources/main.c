/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasapog <tkasapog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 09:34:02 by tkasapog          #+#    #+#             */
/*   Updated: 2025/04/01 15:28:23 by tkasapog         ###   ########.fr       */
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
	check_images(game);
	printf("Texture files are checked!\n");
	get_player_init_position(game->map, game->player);
	printf("Player count after getting position = %d\n", game->player->player_count);
	if (game->player->player_count == 0)
		handle_error(game, "No player on the map!");
	validate_map(game);
	printf("Map is valid!\n");
	init_game(game);
	free_game(game);
	printf("All is freed. All good!\n");
	return (0);
}
