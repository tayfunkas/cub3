/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grial <grial@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 09:36:03 by tkasapog          #+#    #+#             */
/*   Updated: 2025/02/19 17:03:21 by grial            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	parse_file(t_game *game)
{
	int		fd;
	char	*line;

	fd = open(game->map_file, O_RDONLY);
	if (fd < 0)
		handle_error(game, "Failed to open .cub file.");
	line = get_next_line(fd);
	while (line != NULL)
	{
		classify_line(game, line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

static int	assign_lines(t_game *game, char *line)
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
	else if (*line == '\0')
		return (1);
	else
		return (0);
	return (1);
}

void	classify_line(t_game *game, char *line)
{
	static int	parsing_map = 0;
	char		*original_line;

	original_line = line;
	while (*line == ' ' || *line == '\n')
		line++;
	if (parsing_map)
	{
		if (ft_isdigit(*line) || *line == ' ')
			parse_map(game, original_line);
		else if (*line == '\0')
			handle_error(game, "Empty line within the map");
		else
			handle_error(game, "Invalid line after map has started");
		return ;
	}
	if (assign_lines(game, line))
		return ;
	else if (ft_isdigit(*line) || *line == ' ')
	{
		parsing_map = 1;
		parse_map(game, original_line);
	}
	else
		handle_error(game, "Invalid line in .cub file");
}

/*void	classify_line(t_game *game, char *line)
{
	static int	parsing_map = 0;
	char		*original_line;

	original_line = line;
	while (*line == ' ' || *line == '\n')
		line++;
	if (parsing_map)
	{
		if (ft_isdigit(*line) || *line == ' ')
			parse_map(game, original_line);
		else if (*line == '\0')
			handle_error(game, "Empty line within the map");
		else
			handle_error(game, "Invalid line after map has started");
		return ;
	}
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
	else if (*line == '\0')
		return ;
	else if (ft_isdigit(*line) || *line == ' ')
	{
		parsing_map = 1;
		parse_map(game, original_line);
	}
	else
		handle_error(game, "Invalid line in .cub file");
}*/

void	parse_map(t_game *game, char *line)
{
	static char	**temp_map = NULL;
	int			len;
	int			s;
	int			i;

	len = ft_strlen(line);
	s = 0;
	i = 0;
	while (i < len && line[i] != '\n')
	{
		if (line[i] == ' ') 
			s++;
		i++;
	}
	if (len - 1 == s)
		handle_error(game, "Invalid blank line within the map.");
	line = ft_strtrim(line, "\n");
	temp_map = append_line_to_map(temp_map, line, game);
	game->map->line_count++;
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
	map_len = ft_arraylen(map);
	new_map = malloc(sizeof(char *) * (map_len + 2));
	if (!new_map)
		handle_error(game, "Memory allocation failed while expanding the map");
	check_mapchars(line, game);
	printf("hola\n");
	check_player(map, line, game);
	while (i < map_len)
	{
		new_map[i] = map[i];
		i++;
	}
	new_map[map_len] = ft_strdup(line);
	new_map[map_len + 1] = NULL;
	free(map);
	game->map->m_height = map_len + 1;
	line_width = ft_strlen(line);
	if (line_width > game->map->m_width)
		game->map->m_width = line_width;
	return (new_map);
}
