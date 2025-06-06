/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasapog <tkasapog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 09:33:22 by tkasapog          #+#    #+#             */
/*   Updated: 2025/06/06 15:15:44 by tkasapog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

/*int	validate_borders(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < map->m_width)
	{
		if ((map->data[0][x] != '1' && map->data[0][x] != ' ') 
				|| map->data[0][x] == 'D' || map->data[0][x] == 'Q')
			return (0);
		if ((map->data[map->m_height - 1][x] != '1' 
			&& map->data[map->m_height -1][x] != ' ') 
			|| map->data[0][x] == 'D' || map->data[0][x] == 'Q')
			return (0);
		x++;
	}
	while (y < map->m_height)
	{
		if ((map->data[y][0] != '1' && map->data[y][0] != ' ') 
		|| map->data[0][x] == 'D' || map->data[0][x] == 'Q')
			return (0);
		if ((map->data[y][map->m_width - 1] != '1' 
			&& map->data[y][map->m_width -1] != ' ') 
			|| map->data[0][x] == 'D' || map->data[0][x] == 'Q')
			return (0);
		y++;
	}
	return (1);
}*/

int	is_invalid_border_tile(char c)
{
	if (c == '1' || c == ' ')
		return (0);
	if (c == 'D' || c == 'Q')
		return (1);
	return (1);
}

int	validate_borders(t_map *map)
{
	int	x;
	int	y;
	int	last_row;
	int	last_col;

	last_row = map->m_height - 1;
	last_col = map->m_width - 1;
	x = 0;
	while (x < map->m_width)
	{
		if (is_invalid_border_tile(map->data[0][x]) 
			|| is_invalid_border_tile(map->data[last_row][x]))
			return (0);
		x++;
	}
	y = 0;
	while (y < map->m_height)
	{
		if (is_invalid_border_tile(map->data[y][0]) 
			|| is_invalid_border_tile(map->data[y][last_col]))
			return (0);
		y++;
	}
	return (1);
}

void	check_map_tile(t_game *game, char **map, int x, int y)
{
	bool	horizontal;
	bool	vertical;

	if (map[x][y] != '0' && map[x][y] != 'D' && map[x][y] != 'Q')
		return ;
	if (y == 0 || y == game->map->m_width - 1 
		|| map[x][y - 1] == ' ' || map[x][y + 1] == ' ')
		handle_error(game, "Open map");
	if (x == 0 || x == game->map->m_height - 1 
		|| map[x - 1][y] == ' ' || map[x + 1][y] == ' ')
		handle_error(game, "Open map");
	if (map[x][y] == 'D')
	{
		horizontal = (map[x][y - 1] == '1' && map[x][y + 1] == '1');
		vertical = (map[x - 1][y] == '1' && map[x + 1][y] == '1');
		if (!(horizontal || vertical))
			handle_error(game, "Door must be between walls");
	}
}

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
	get_exit(game->map);
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
		if (ft_strlen(map[i]) < (size_t)game->map->m_width)
		{
			padded_line = malloc(sizeof(char) * (game->map->m_width + 1));
			j = ft_strlen(map[i]);
			ft_strlcpy(padded_line, map[i], j + 1);
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
