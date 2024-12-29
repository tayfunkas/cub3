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
    t_game game;

    initialize_game(&game);
    parse_arguments(argc, argv, &game);
    parse_file(&game);
    check_images(&game);
    validate_map(&game);

    printf("Map and textures are loaded succesfully!");
    free_game(&game);
}