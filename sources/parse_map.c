/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasapog <tkasapog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 09:36:03 by tkasapog          #+#    #+#             */
/*   Updated: 2025/01/02 12:59:57 by tkasapog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3.h"

void	parse_file(t_game *game)
{
	int		fd;
	char	*line;

	fd = open(game->map_file, O_RDONLY);
	if (fd < 0)
		handle_error(game, "Failed to open .cub file.");
	while ((line = get_next_line(fd)) != NULL)
	{
		if (line[0] == '\n' || line[0] == '\0')
		{
			free(line);
			continue ;
		}
		classify_line(game, line);
		free(line);
	}
	close(fd);
}

void	classify_line(t_game *game, char *line)
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
	else if (ft_isdigit(line[0]) || line[0] == ' ')
		parse_map(game, line);
	else
		handle_error(game, "Invalid line in .cub file");
}

void	parse_map(t_game *game, char *line)
{
	static char	**temp_map;

	temp_map = NULL;
	line = ft_strtrim(line, "\n");
	temp_map = append_line_to_map(temp_map, line, game);
	if (!temp_map)
		handle_error(game, "Memory allocation failed for parsing the map.");
	game->map->data = temp_map;
}

char	**append_line_to_map(char **map, char *line, t_game *game)
{
	int		map_len;
	char	**new_map;
	int		i;
	int		line_width;

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
