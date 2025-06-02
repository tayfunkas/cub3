/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasapog <tkasapog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 09:33:37 by tkasapog          #+#    #+#             */
/*   Updated: 2025/06/02 17:47:35 by tkasapog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	check_empty_map(t_game *game, int fd)
{
	char	buff;

	if (read(fd, &buff, 1) == 0)
		handle_error(game, "Empty map.");
}

void	check_mapfile_name(t_game *game, char *map)
{
	int	len;
	int	fd;

	len = 0;
	while (map[len])
		len++;
	if (map[len - 4] != '.' || map[len - 3] != 'c' 
		|| map[len - 2] != 'u' || map[len - 1] != 'b')
		handle_error(game, "Only .cub extension is accepted for maps");
	fd = open(map, O_RDWR);
	if (fd < 0)
		handle_error(game, "Map was not opened.");
	check_empty_map(game, fd);
	close(fd);
}

bool	check_mapchars(char *line, t_game *game)
{
	int		i;
	char	*trimmed;

	(void)game;
	//printf("Checking line: %s\n", line);
	i = 0;
	trimmed = ft_strtrim(line, "\n");
	line = trimmed;
	while (line[i])
	{
		if (line[i] != '0' && line[i] != '1' && line[i] != 'N' 
			&& line[i] != 'S' && line[i] != 'W' 
			&& line[i] != 'E' && line[i] != ' ')
		{
			free(trimmed);
			return (false);
		}
		i++;
	}
	free(trimmed);
	return (true);
}

/*void	check_player_position(t_game *game)
{
	int		x;
	int		y;
	char	**map;

	map = game->map->data;
	x = game->player->player_x;
	y = game->player->player_y;
	if (y == 0 || y == game->map->m_width - 1 
		|| map[x][y - 1] == ' ' || map[x][y + 1] == ' ')
		handle_error(game, "Check player position");
	if (x == 0 || x == game->map->m_height - 1 
		|| map[x - 1][y] == ' ' || map[x + 1][y] == ' ')
		handle_error(game, "Check player position");
	if (!map[y - 1] || (map[y - 1][x] != '0' && map[y - 1][x] != '1'))
		handle_error(game, "Check player position");
	if (!map[y + 1] || (map[y + 1][x] != '0' && map[y + 1][x] != '1'))
		handle_error(game, "Check player position");
	if (x <= 0 || (map[y][x - 1] != '0' && map[y][x - 1] != '1'))
		handle_error(game, "Check player position");
	if (map[y][x + 1] == '\0' || (map[y][x + 1] != '0' && map[y][x + 1] != '1'))
		handle_error(game, "Check player position");
}*/

void	check_player_position(t_game *game)
{
	int		x;
	int		y;
	char	**map;

	map = game->map->data;
	x = game->player->player_x;
	y = game->player->player_y;
	if (y == 0 || y == game->map->m_width - 1 
		|| map[x][y - 1] == ' ' || map[x][y + 1] == ' ')
		handle_error(game, "Check player position");
	if (x == 0 || x == game->map->m_height - 1 
		|| map[x - 1][y] == ' ' || map[x + 1][y] == ' ')
		handle_error(game, "Check player position");
	/*if (!map[y - 1] || (map[y - 1][x] != '0' && map[y - 1][x] != '1'))
		handle_error(game, "Check player position");
	if (!map[y + 1] || (map[y + 1][x] != '0' && map[y + 1][x] != '1'))
		handle_error(game, "Check player position");
	if (x <= 0 || (map[y][x - 1] != '0' && map[y][x - 1] != '1'))
		handle_error(game, "Check player position");
	if (map[y][x + 1] == '\0' || (map[y][x + 1] != '0' && map[y][x + 1] != '1'))
		handle_error(game, "Check player position");*/
}



bool	check_player(char **map, char *line, t_game *game)
{
	static int	player = 0; 
	int			i;

	i = 0;
	while (line[i])
	{
		if (line[i] == 'N' || line[i] == 'S' 
			|| line[i] == 'W' || line[i] == 'E')
		{
			player++;
			if (player > 1)
				return (false);
			game->player->player_dir = line[i];
			game->player->player_x = i;
			game->player->player_y = ft_arraylen(map);
		}
		i++;
	}
	return (true);
}
