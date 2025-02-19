/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grial <grial@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 09:33:37 by tkasapog          #+#    #+#             */
/*   Updated: 2025/02/19 17:19:42 by grial            ###   ########.fr       */
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

void	check_mapchars(char *line, t_game *game)
{
	int	i;

	printf("Checking line: %s\n", line);
	i = 0;
	ft_strtrim(line, "\n");
	while (line[i])
	{
		if (line[i] != '0' && line[i] != '1' && line[i] != 'N' 
			&& line[i] != 'S' && line[i] != 'W' 
			&& line[i] != 'E' && line[i] != ' ')
			handle_error(game, "Invalid character in the map");
		i++;
	}
}

void	check_player(char **map, char *line, t_game *game)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == 'N' || line[i] == 'S' 
			|| line[i] == 'W' || line[i] == 'E')
		{
			game->player->player_count++;
			if (game->player->player_count > 1)
				handle_error(game, 
					"There should be one starting position for the player");
			game->player->player_dir = line[i];
			game->player->player_x = i;
			game->player->player_y = ft_arraylen(map);
		}
		i++;
	}
}
