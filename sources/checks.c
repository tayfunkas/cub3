#include "cub3.h"

void    check_empty_map(t_game *game, int fd)
{
    char    buff;

    if (read(fd, &buff, 1) == 0)
        handle_error(game, "Empty map.");
}

void    check_mapfile_name(t_game *game, char *map)
{
    int     len;
    int     fd;

    len = 0;
    while(map[len])
        len++;
    if (map[len - 4] != '.' || map[len - 3] != 'c' || map[len - 2] != 'u' || map[len - 1] != 'b')
        handle_error(game, "Only .cub extension is accepted for maps");
    fd = open(map, O_RDWR);
    if (fd < 0)
        handle_error(game, "Map was not opened.");
    check_empty_map(game, fd);
    close(fd);
}

void    parse_file(t_game *game)
{
    int fd;
    char    *line;

    fd = open(game->map_file, O_RDONLY);
    if (fd < 0)
        handle_error(game, "Failed to open .cub file.");
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
        handle_error(game, "Invalid line in .cub file");   
}

void    parse_texture(t_game *game, char *line, char **texture_path)
{
    while (*line == ' ')
        line++;
    *texture_path = ft_strdup(line);
    if (!*texture_path)
        handle_error(game, "Invalid texture line");
}

void    parse_color(t_game *game, char *line, t_color *color)
{
    char **rgb = ft_split(line, ',');
    if (!rgb || ft_arraylen(rgb) != 3)
        handle_error(game, "Invalid color format");
    color->r = ft_atoi(rgb[0]);
    color->g = ft_atoi(rgb[1]);
    color->b = ft_atoi(rgb[2]);
    if (color-> r < 0 || color-> r > 255 || color->g < 0 || color->g > 255 || color->b < 0 || color->b > 255)
        handle_error(game, "Color values must be in range 0-255");
    //ft_free_split(rgb);
}

void    parse_map(t_game *game, char *line)
{
    static char **temp_map;
    
    temp_map = NULL;
    temp_map = append_line_to_map(temp_map, line, game);
    if (!temp_map)
        handle_error(game, "Memory allocation failed for parsing the map.");
    game->map->data = temp_map;
}

void    check_mapchars(char *line, t_game *game)
{
    int i;

    i = 0;
    while (line[i])
    {
        if (line[i] != '0' && line[i] != '1' && line[i] != 'N' && line[i] != 'S' && line[i] != 'W' && line[i] != 'E' && line[i] != ' ')
            handle_error(game, "Invalid character in the map");
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
                handle_error(game, "There should be one starting position for the player");
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
    int line_width;

    i = 0;
    line_width = 0;
    map_len = ft_arraylen(map);
    new_map = malloc(sizeof(char *) * (map_len + 2));
    if (!new_map)
        handle_error(game, "Memory allocation failed while expanding the map");
    check_mapchars(line, game);
    check_player(map, line, game);
    while (i < map_len)
        new_map[i] = map[i];
    new_map[map_len] = ft_strdup(line);
    new_map[map_len + 1] = NULL;
    free(map);
    game->map->m_height = map_len + 1;
    line_width = ft_strlen(line);
    if (line_width > game->map->m_width)
        game->map->m_width = line_width;
    return (new_map);
}