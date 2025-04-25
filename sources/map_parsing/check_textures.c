/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasapog <tkasapog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 09:33:31 by tkasapog          #+#    #+#             */
/*   Updated: 2025/04/25 16:41:08 by tkasapog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	has_xpm_extension(const char *filename)
{
	size_t	len;
	int		result;
	char	*trimmed_fn;
	char	*trimmed_fn1;

	trimmed_fn = ft_strtrim(filename, "\n");
	trimmed_fn1 = ft_strtrim(trimmed_fn, " ");
	free(trimmed_fn);
	if (!trimmed_fn1)
		return (0);
	len = ft_strlen(trimmed_fn1);
	if (len < 4)
		return (0);
	if (trimmed_fn1[len - 1] != 'm' || trimmed_fn1[len - 2] != 'p' 
		|| trimmed_fn1[len - 3] != 'x' || trimmed_fn1[len - 4] != '.')
		result = 0;
	else
		result = 1; 
	free(trimmed_fn1);
	return (result);
}

void	parse_texture(t_game *game, char *line, char **texture_path)
{
	char	*trimmed_line;
	char	*temp;

	while (*line == ' ')
		line++;
	temp = ft_strtrim(line, "\n");
	trimmed_line = ft_strtrim(temp, " ");
	free(temp);
	*texture_path = trimmed_line;
	if (!*texture_path)
	{
		free(trimmed_line);
		game->error = 1;
	}
}

void	check_texture(const char *path, const char *message, t_game *game)
{
	int	fd;

	if (!has_xpm_extension(path))
		handle_error(game, "Texture file must have .xpm extension.");
	fd = open(path, O_RDONLY);
	if (fd == -1)
		handle_error(game, message);
	close(fd);
}

void	check_images(t_game *game)
{
	if (!game->engine)
		handle_error(game, "Engine not initialized before checking textures.");
	if (!game->engine->no_texture || !game->engine->so_texture || 
		!game->engine->we_texture || !game->engine->ea_texture)
		handle_error(game, "Missing texture file.");
	check_texture(game->engine->no_texture, 
		"North texture is invalid or inaccesible.", game);
	check_texture(game->engine->so_texture, 
		"South texture is invalid or inaccesible.", game);
	check_texture(game->engine->we_texture, 
		"West texture is invalid or inaccesible.", game);
	check_texture(game->engine->ea_texture, 
		"East texture is invalid or inaccesible.", game);
}

void	check_duplicates_or_missing(t_game *game)
{
	if (game->config->no > 1 || game->config->no == 0)
		game->error = 1;
	if (game->config->so > 1 || game->config->so == 0)
		game->error = 1;
	if (game->config->we > 1 || game->config->we == 0)
		game->error = 1;
	if (game->config->ea > 1 || game->config->ea == 0)
		game->error = 1;
	if (game->config->f > 1 || game->config->f == 0)
		game->error = 1;
	if (game->config->c > 1 || game->config->c == 0)
		game->error = 1;
}
