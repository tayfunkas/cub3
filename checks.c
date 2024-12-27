#include "cub3.h"

void    check_empty_map(t_game *game, int fd)
{
    char    buff;

    if (read(fd, &buff, 1) == 0)
    {
        printf("Error\nEmpty map.\n");
        free(game);
        exit(1);
    }
}

void    check_mapfile_name(t_game *game, char *map)
{
    int     len;
    int     fd;

    len = 0;
    while(map[len])
        len++;
    if (map[len - 4] != '.' || map[len - 3] != 'c' || map[len - 2] != 'u' || map[len - 1] != 'b')
    {
        printf("Error\nOnly .cub extension is accepted for maps.\n");
        free(game);
        exit(1);
    }
    fd = open(map, O_RDWR);
    if (fd < 0)
    {
        printf("Error\nMap is not opened.\n");
        free(game);
        exit(1);
    }
    check_empty_map(game, fd);
    close(fd);
}

void    parse_file(t_game *game, char *filepath)
{
    int fd;
    char    *line;

    fd = open(filepath, O_RDONLY);
    if (fd < 0)
    {
        printf("Error\nFailed to open .cub file.\n");
        free(game);
        exit(1);
    }
    while ((line = get_next_line(fd)) != NULL)
    {
        if(line[0] == '\n' || line[0] == '\0')
        {
            free(line);
            continue;
        }
        classify_line(game, line);
        free(line);
    }
    close(fd);
}

void    classify_line(t_game *game, char *line)
{
    if (ft_strncmp(line, "NO ", 3) == 0)
        parse_texture(game, line + 3, &(game->no_texture));
    else if (ft_strncmp(line, "SO ", 3) == 0)
        parse_texture(game, line + 3, &(game->so_texture));
    else if (ft_strncmp(line, "WE ", 3) == 0)
        parse_texture(game, line + 3, &(game->we_texture));
    else if (ft_strncmp(line, "EA ", 3) == 0)
        parse_texture(game, line + 3, &(game->ea_texture));
    else if (ft_strncmp(line, "F ", 2) == 0)
        parse_color(game, line + 2, &(game->floor_color));
    else if (ft_strncmp(line, "C ", 2) == 0)
        parse_color(game, line + 2, &(game->ceiling_color));
    else if(ft_isdigit(line[0]) || line[0] == ' ')
        parse_map(game, line);
    else
    {
        printf("Error\nInvalid line in .cun file: %s\n", line);
        free(game);
        exit(1);    
    }
}

void    parse_texture(t_game *game, char *line, char **texture_path)
{
    while (*line == ' ')
        line++;
    *texture_path = ft_strdup(line);
    if (!*texture_path)
    {
        printf("Error\nInvalid texture path: %s\n", line);
        free(game);
        exit(1);
    }
}

void    parse_color(t_game *game, char *line, t_color *color)
{
    char **rgb = ft_split(line, ',');
    if (!rgb || ft_arraylen(rgb) != 3)
    {
        printf("Error\nInvalid color format: %s\n", line);
        free(game);
        exit(1);
    }
    color->r = ft_atoi(rgb[0]);
    color->g = ft_atoi(rgb[1]);
    color->b = ft_atoi(rgb[2]);
    if (color-> r < 0 || color-> r > 255 || color->g < 0 || color->g > 255 || color->b < 0 || color->b > 255)
    {
        printf("Error\nColor values must be in range 0-255: %s\n", line);
        free(game);
        exit(1);
    }
    ft_free_split(rgb);
}

void    parse_map(t_game *game, char *line)
{
    static char **temp_map = NULL;

    temp_map = append_line_to_map(temp_map, line, game);
    if (!temp_map)
    {
        printf("Error\nMemory allocation failed for parsing the map.\n");
        free(game);
        exit(1);
    }
    game->map = temp_map;
}

void    check_mapchars(char **map, char *line, t_game *game)
{
    int i;

    i = 0;
    while (line[i])
    {
        if (line[i] != '0' && line[i] != '1' && line[i] != 'N' && line[i] != 'S' && line[i] != 'W' && line[i] != 'E' && line[i] != ' ')
        {
            printf("Error\nInvalid character in the map: %c\n", line[i]);
            free(game);
            exit(1);
        }
        i++;
    }
}

void    check_player(char **map, char *line, t_game *game)
{
    int i;

    i = 0;
    while (line[i])
    {
        if (line[i] == 'N' || line[i] == 'S' || line[i] == 'W' || line[i] == 'E')
        {
            game->player->player_count++;
            if (game->player->player_count > 1)
            {
                printf("Error\nThere should be one starting position for the player\n");
                free(game);
                exit(1);
            }
            game->player->player_dir = line[i];
            game->player->player_x = i;
            game->player->player_y = ft_arraylen(map);
        }
        i++;
    }
}

char    **append_line_to_map(char **map, char *line, t_game *game)
{
    int map_len;
    char **new_map;
    int i;

    i = 0;
    map_len = ft_arraylen(map);
    new_map = malloc(sizeof(char *) * (map_len + 2));
    if (!new_map)
    {
        printf("Error\nMemory allocation failed while expanding the map.\n");
        free(game);
        exit(1);
    }
    check_mapchars(map, line, game);
    check_player(map, line, game);
    while (i < map_len)
        new_map[i] = map[i];
    new_map[map_len] = ft_strdup(line);
    new_map[map_len + 1] = NULL;
    free(map);
    return (new_map);
}

int ft_arraylen(char **array)
{
    int len;

    len = 0;
    while (array && array[len])
        len++;
    return (len);
}