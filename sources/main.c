#include "cub3.h"

void    parse_arguments(int argc, char **argv, t_game *game)
{
    if (argc != 2)
        handle_error(game, "Usage: ./cub3 <map_file.cub>");
    check_mapfile_name(game, argv[1]);
    game->map_file = argv[1];
}

int main(int argc, char **argv)
{
    t_game *game;
    
    game = NULL;
    initialize_game(&game);
    printf("Game struct initialized succesfully!\n");
    parse_arguments(argc, argv, game);
    printf("Arguments parsed succesfully!\n");
    parse_file(game);
    printf("Map file parsed succesfully!\n");
    check_images(game);
    printf("Texture files are checked!\n");
    validate_map(game);
    printf("Map is valid!\n");

    free_game(game);
    printf("All is freed. All good!\n");
    return (0);
}