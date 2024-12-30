#include "cub3.h"

int has_xpm_extension(const char *filename)
{
    size_t  len;
    
    len = ft_strlen(filename);
    printf("file name %slength = %zu\n", filename, len);
    printf("%c\n", filename[len - 2]);
    if (len < 4)
        return (0);
    if (filename[len - 1] != 'm' || filename[len - 2] != 'p' || filename[len - 3] != 'x' || filename[len - 4] != '.')
        return (0);
    else
        return (1); 
}

void    check_texture(const char *path, const char *message, t_game *game)
{
    int fd;
    
    if (!has_xpm_extension(path))
        handle_error(game, "Texture file must have .xpm extension.");
    fd = open(path, O_RDONLY);
    if (fd == -1)
        handle_error(game, message);
    close(fd);
}

void    check_images(t_game *game)
{
    check_texture(game->no_texture, "North texture is invalid or inaccesible.", game);
    check_texture(game->so_texture, "South texture is invalid or inaccesible.", game);
    check_texture(game->we_texture, "West texture is invalid or inaccesible.", game);
    check_texture(game->ea_texture, "East texture is invalid or inaccesible.", game);
}
