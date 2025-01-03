/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   border_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasapog <tkasapog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 09:33:22 by tkasapog          #+#    #+#             */
/*   Updated: 2025/01/03 18:57:33 by tkasapog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3.h"

void	normalize_map(t_game *game, t_map *map)
{
	int		i;
	int		row_length;
	char	*padded_row;

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
				handle_error(game, 
					"Memory allocation failed during map normalization.");
			ft_memcpy(padded_row, map->data[i], row_length);
			ft_memset(padded_row + row_length, ' ', map->m_width - row_length);
			padded_row[map->m_width] = '\0';
			free(map->data[i]);
			map->data[i] = padded_row;
		}
		i++;
	}
}

int	flood_fill(t_map *map, int x, int y)
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

int	validate_borders(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < map->m_width)
	{
		if (map->data[0][x] != '1' && map->data[0][x] != ' ')
			return (0);
		if (map->data[map->m_height - 1][x] != '1' 
			&& map->data[map->m_height -1][x] != ' ')
			return (0);
		x++;
	}
	while (y < map->m_height)
	{
		if (map->data[y][0] != '1' && map->data[y][0] != ' ')
			return (0);
		if (map->data[y][map->m_width - 1] != '1' 
			&& map->data[y][map->m_width -1] != ' ')
			return (0);
		y++;
	}
	return (1);
}

int	validate_map(t_game *game)
{
	int		x;
	int		y;
	t_map	*map;

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
				if (!flood_fill(map, game->player->player_x, game->player->player_y))
					handle_error(game, "Map is not enclosed by walls.");
				return (1);
			}
			x++;
		}
		y++;
	}
	return (1);
}

void	validate_line(t_game *game, char **map, int x, int height)
{
	int		y;
	int		line_length = ft_strlen(map[x]);

	for (y = 0; y < line_length; y++)
	{
		if (map[x][y] == '0')
		{
			// Check left
			if (y == 0 || map[x][y - 1] == ' ')
				handle_error(game, "Open map: space to the left of 0.");
			// Check right
			if (y == line_length - 1 || map[x][y + 1] == ' ')
				handle_error(game, "Open map: space to the right of 0.");
			// Check above
			if (x > 0) // Ensure there is a row above
			{
				int prev_row_len = ft_strlen(map[x - 1]);
				if (y >= prev_row_len || map[x - 1][y] == ' ')
					handle_error(game, "Open map: space above 0.");
			}
			// Check below
			if (x < height - 1) // Ensure there is a row below
			{
				int next_row_len = ft_strlen(map[x + 1]);
				if (y >= next_row_len || map[x + 1][y] == ' ')
					handle_error(game, "Open map: space below 0.");
			}
		}
	}
}

void	validate_map_lines(t_game *game)
{
	char	**map = game->map->data;
	int		height = game->map->m_height;
	int		x;

	for (x = 0; x < height; x++)
	{
		validate_line(game, map, x, height);
	}
}

