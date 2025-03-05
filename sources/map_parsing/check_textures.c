/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grial <grial@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 09:33:31 by tkasapog          #+#    #+#             */
/*   Updated: 2025/03/05 15:12:31 by grial            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	has_xpm_extension(const char *filename)
{
	size_t	len;
	char	*trimmed_fn;

	trimmed_fn = ft_strtrim(filename, "\n");
	trimmed_fn = ft_strtrim(trimmed_fn, " ");
	len = ft_strlen(trimmed_fn);
	if (len < 4)
		return (0);
	if (trimmed_fn[len - 1] != 'm' || trimmed_fn[len - 2] != 'p' 
		|| trimmed_fn[len - 3] != 'x' || trimmed_fn[len - 4] != '.')
		return (0);
	else
		return (1); 
}

void	parse_texture(t_game *game, char *line, char *texture_path)
{
	char	*trimmed_line;
	
	printf("%c\n", *line);
	while (*line == ' ')
		line++;
	printf("hola\n");
	trimmed_line = ft_strtrim(line, "\n");
	trimmed_line = ft_strtrim(trimmed_line, " ");
	texture_path = trimmed_line;
	if (!*texture_path)
		handle_error(game, "Invalid texture line");
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
	if (!game->engine->NO || !game->engine->EA || !game->engine->SO  
		|| !game->engine->WE )
		handle_error(game, "Missing texture file.");
	check_texture(game->engine->NO, 
		"North texture is invalid or inaccesible.", game);
	check_texture(game->engine->EA, 
		"East texture is invalid or inaccesible.", game);
	check_texture(game->engine->SO, 
		"South texture is invalid or inaccesible.", game);
	check_texture(game->engine->WE, 
		"West texture is invalid or inaccesible.", game);
	(void)game;
	return ;
}
