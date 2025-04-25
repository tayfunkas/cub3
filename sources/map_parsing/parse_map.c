/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasapog <tkasapog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 09:36:03 by tkasapog          #+#    #+#             */
/*   Updated: 2025/04/25 17:00:40 by tkasapog         ###   ########.fr       */
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
	close(fd);
}

static void	check_blank_line(t_game *game, char *line, int len)
{
	int	i;
	int	space_count;

	i = 0;
	space_count = 0;
	while (i < len && line[i] != '\n')
	{
		if (line[i] == ' ')
			space_count++;
		i++;
	}
	if (len - 1 == space_count)
		handle_error(game, "Invalid blank line within the map.");
}

void	parse_map(t_game *game, char *line)
{
	static char	**temp_map = NULL;
	int			len;
	char		*trimmed;

	len = ft_strlen(line);
	check_blank_line(game, line, len);
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

static char	**create_expanded_map(char **map, char *line, 
	t_game *game, int *map_len)
{
	char	**new_map;

	*map_len = ft_arraylen(map);
	new_map = malloc(sizeof(char *) * (*map_len + 2));
	if (!new_map)
		handle_error(game, "Memory allocation failed while expanding the map");
	if (!check_mapchars(line, game) || !check_player(map, line, game))
		game->error = 1;
	return (new_map);
}

char	**append_line_to_map(char **map, char *line, t_game *game)
{
	char	**new_map;
	int		map_len;
	int		i;
	int		line_width;

	i = 0;
	new_map = create_expanded_map(map, line, game, &map_len);
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

/*char	**append_line_to_map(char **map, char *line, t_game *game)
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
	if (!check_mapchars(line, game) || !check_player(map, line, game))
		game->error = 1;
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
}*/
