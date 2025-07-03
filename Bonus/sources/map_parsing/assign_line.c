/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grial <grial@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 16:36:29 by tkasapog          #+#    #+#             */
/*   Updated: 2025/06/04 15:51:38 by grial            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static int	assign_texturefiles(t_game *game, char *line)
{
	if (ft_strncmp(line, "NO ", 3) == 0)
	{
		if (game->engine->no_path)
			return (1);
		parse_texture(game, line + 3, &(game->engine->no_path));
	}
	else if (ft_strncmp(line, "SO ", 3) == 0)
	{
		if (game->engine->so_path)
			return (1);
		parse_texture(game, line + 3, &(game->engine->so_path));
	}
	else if (ft_strncmp(line, "WE ", 3) == 0)
	{
		if (game->engine->we_path)
			return (1);
		parse_texture(game, line + 3, &(game->engine->we_path));
	}
	else
		return (0);
	return (1);
}

static int	assign_lines(t_game *game, char *line)
{
	if (assign_texturefiles(game, line))
		return (1);
	else if (ft_strncmp(line, "EA ", 3) == 0)
	{
		if (game->engine->ea_path)
			return (1);
		parse_texture(game, line + 3, &(game->engine->ea_path));
	}
	else if (ft_strncmp(line, "F ", 2) == 0)
		parse_color(game, line + 2, (game->engine->floor_color));
	else if (ft_strncmp(line, "C ", 2) == 0)
		parse_color(game, line + 2, (game->engine->ceiling_color));
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

/*void	classify_line(t_game *game, char *line)
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
			game->error = 1;
		else
			game ->error = 1;
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
}*/

static void	handle_map_or_error(t_game *game, char *line, char *original_line)
{
	if (ft_isdigit(*line) || *line == ' ')
		parse_map(game, original_line);
	else if (*line == '\0')
		game->error = 1;
	else
		game->error = 1;
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
		return (handle_map_or_error(game, line, original_line));
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
		game->error = 1;
}
