/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasapog <tkasapog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 09:33:22 by tkasapog          #+#    #+#             */
/*   Updated: 2025/04/25 17:04:12 by tkasapog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

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

static void	check_map_tile(t_game *game, char **map, int x, int y)
{
	if (map[x][y] != '0')
		return ;
	if (y == 0 || y == game->map->m_width - 1 
		|| map[x][y - 1] == ' ' || map[x][y + 1] == ' ')
		handle_error(game, "Open map");
	if (x == 0 || x == game->map->m_height - 1 
		|| map[x - 1][y] == ' ' || map[x + 1][y] == ' ')
		handle_error(game, "Open map");
}

/*void	validate_map(t_game *game)
{
	char	**map;
	int		x;
	int		y;

	x = 0;
	if (!game || !game->map || !game->map->data)
		handle_error(game, "Map data is not initialized in validate_map");
	map = game->map->data;
	pad_map_to_rectangle(game);
	while (x < game->map->m_height)
	{
		y = 0;
		while (y < game->map->m_width)
		{
			if (map[x][y] == '0')
			{
				if (y == 0 || y == game->map->m_width - 1 
					|| map[x][y - 1] == ' ' || map[x][y + 1] == ' ')
					handle_error(game, "Open map");
				if (x == 0 || x == game->map->m_height - 1 
					|| map[x - 1][y] == ' ' || map[x + 1][y] == ' ')
					handle_error(game, "Open map");
			}
			y++;
		}
		x++;
	}
}*/

void	validate_map(t_game *game)
{
	char	**map;
	int		x;
	int		y;

	if (!game || !game->map || !game->map->data)
		handle_error(game, "Map data is not initialized in validate_map");
	map = game->map->data;
	pad_map_to_rectangle(game);
	x = 0;
	while (x < game->map->m_height)
	{
		y = 0;
		while (y < game->map->m_width)
		{
			check_map_tile(game, map, x, y);
			y++;
		}
		x++;
	}
}

void	pad_map_to_rectangle(t_game *game)
{
	char	**map;
	char	*padded_line;
	int		j;
	int		i;

	map = game->map->data;
	i = 0;
	while (i < game->map->m_height)
	{
		if (ft_strlen(map[i]) < game->map->m_width)
		{
			padded_line = malloc(sizeof(char) * (game->map->m_width + 1));
			ft_strlcpy(padded_line, map[i], ft_strlen(map[i]) + 1);
			j = ft_strlen(map[i]);
			while (j < game->map->m_width)
			{
				padded_line[j] = ' ';
				j++;
			}
			padded_line[game->map->m_width] = '\0';
			free(map[i]);
			map[i] = padded_line;
		}
		i++;
	}
}
