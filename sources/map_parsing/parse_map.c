/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasapog <tkasapog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 09:36:03 by tkasapog          #+#    #+#             */
/*   Updated: 2025/04/07 16:19:48 by tkasapog         ###   ########.fr       */
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
	free(line);
	//check_line_config(game, line);
	close(fd);
}

static int	assign_lines(t_game *game, char *line)
{
	if (ft_strncmp(line, "NO ", 3) == 0)
		parse_texture(game, line + 3, &(game->engine->no_texture));
	else if (ft_strncmp(line, "SO ", 3) == 0)
		parse_texture(game, line + 3, &(game->engine->so_texture));
	else if (ft_strncmp(line, "WE ", 3) == 0)
		parse_texture(game, line + 3, &(game->engine->we_texture));
	else if (ft_strncmp(line, "EA ", 3) == 0)
		parse_texture(game, line + 3, &(game->engine->ea_texture));
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

void	check_line_config(t_game *game, char *line)
{
	if (!line)
		return ;
	if (ft_strncmp(line, "NO ", 3) == 0)
		game->config->no++;
	else if (ft_strncmp(line, "SO ", 3) == 0)
		game->config->so++;
	else if (ft_strncmp(line, "WE ", 3) == 0)
		game->config->we++;
	else if (ft_strncmp(line, "EA ", 3) == 0)
		game->config->ea++;
	else if (ft_strncmp(line, "F ", 2) == 0)
		game->config->f++;
	else if (ft_strncmp(line, "C ", 2) == 0)
		game->config->c++;
}

void	check_duplicates_or_missing(t_game *game)
{
	if (game->config->no > 1 || game->config->no == 0)
		handle_error(game, "Duplicate or no NO texture");
	if (game->config->so > 1 || game->config->so == 0)
		handle_error(game, "Duplicate or no SO texture");
	if (game->config->we > 1 || game->config->we == 0)
		handle_error(game, "Duplicate or no WE texture");
	if (game->config->ea > 1 || game->config->ea == 0)
		handle_error(game, "Duplicate or no EA texture");
	if (game->config->f > 1 || game->config->f == 0)
		handle_error(game, "Duplicate or no floor color (F)");
	if (game->config->c > 1 || game->config->c == 0)
		handle_error(game, "Duplicate or no ceiling color (C)");
}

void	classify_line(t_game *game, char *line)
{
	static int	parsing_map = 0;
	static int	checked_config = 0;
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
	check_line_config(game, line);
	if (assign_lines(game, line))
		return ;
	else if (ft_isdigit(*line) || *line == ' ')
	{
		parsing_map = 1;
		if (!checked_config)
		{
			check_duplicates_or_missing(game);
			checked_config = 1;
		}
		parse_map(game, original_line);
	}
	else
		handle_error(game, "Invalid line in .cub file");
}

void	parse_map(t_game *game, char *line)
{
	static char	**temp_map = NULL;
	int			len;
	int			s;
	int			i;
	char		*trimmed;

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
	trimmed = ft_strtrim(line, "\n");
	if (!trimmed)
		handle_error(game, "Memory allocation failed while trimming");
	temp_map = append_line_to_map(temp_map, trimmed, game);
	free(trimmed);
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
	check_player(map, line, game); 
	while (i < map_len)
	{
		new_map[i] = ft_strdup(map[i]);
		free(map[i]);
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

