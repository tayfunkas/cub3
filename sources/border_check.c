#include "cub3.h"

void    normalize_map(t_game *game, t_map *map)
{
    int i;
    int row_length;
    char    *padded_row;

    i = 0;
    while (i < map->m_height)
    {
        row_length = ft_strlen(map->data[i]);
        if (row_length == 0)
            handle_error(game, "Empty row within the map");
        if (row_length < map->m_width)
        {
            padded_row = malloc(map->m_width + 1);
            if (!padded_row)
                handle_error(game, "Memory allocation failed during map normalization.");
            ft_memcpy(padded_row, map->data[i], row_length);
            ft_memset(padded_row + row_length, ' ', map->m_width - row_length);
            padded_row[map->m_width] = '\0';
            free(map->data[i]);
            map->data[i] = padded_row;    
        }
        i++;
    }
}

int flood_fill(t_map *map, int x, int y)
{
    if (x < 0 || y < 0 || x >= map->m_width || y >= map->m_height)
        return (0);
    if (map->data[y][x] == '1' || map->data[y][x] == 'x')
        return (1);
    if (map->data[y][x] == ' ')
        return (0);
    map->data[y][x] = 'x';
    return (flood_fill(map, x + 1, y) && flood_fill(map, x - 1, y) 
    && flood_fill(map, x, y + 1) && flood_fill(map, x, y - 1));
}

int validate_borders(t_map *map)
{
    int x;
    int y;

    x = 0;
    y = 0;
    while (x < map->m_width)
    {
        if (map->data[0][x] != '1' && map->data[0][x] != ' ')
            return (0);
        if (map->data[map->m_height - 1][x] != '1' && map->data[map->m_height -1][x] != ' ')
            return (0);
        x++;
    }
    while (y < map->m_height)
    {
        if (map->data[y][0] != '1' && map->data[y][0] != ' ')
            return (0);
        if (map->data[y][map->m_width - 1] != '1' && map->data[y][map->m_width -1] != ' ')
            return (0);
        y++;
    }
    return (1);
}

int    validate_map(t_game *game)
{
    t_map *map;
    int x;
    int y;

    y = 0;
    map = game->map;
    normalize_map(game, map);
    if (!validate_borders(map))
        handle_error(game, "Map is not enclosed by walls.");
    while (y < map->m_height)
    {
        x = 0;
        while (x < map->m_width)
        {
            if (map->data[y][x] == '0')
            {
                if (!flood_fill(map, x, y))
                    handle_error(game, "Map is not enclosed by walls.");
                return (1);
            }
            x++;
        }
        y++;
    }
   return (1);
}