/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grial <grial@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 09:33:31 by tkasapog          #+#    #+#             */
/*   Updated: 2025/04/07 17:14:14 by grial            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	rgb_to_hex(int r, int g, int b)
{
	return (r << 16) | (g << 8) | b;
}

static void	assign_check_color(t_game *game, t_color *color, char **rgb)
{
	color->r = ft_atoi(rgb[0]);
	color->g = ft_atoi(rgb[1]);
	color->b = ft_atoi(rgb[2]);
	color->color = rgb_to_hex(color->r, color->g, color->b);
	if (color-> r < 0 || color-> r > 255 || color->g < 0 
		|| color->g > 255 || color->b < 0 || color->b > 255)
		handle_error(game, "Color values must be in range 0-255");
}

void	parse_color(t_game *game, char *line, t_color *color)
{
	char	**rgb;
	char	*trimmed;
	int		i;

	i = 0;
	rgb = ft_split(line, ',');
	if (!rgb || ft_arraylen(rgb) != 3)
		handle_error(game, "Invalid color format");
	while (i < 3)
	{
		trimmed = ft_strtrim(rgb[i], " \n");
		if (!trimmed || !ft_alldigit(trimmed))
		{
			free(trimmed);
			ft_free_split(rgb);
			handle_error(game, "Non-numeric or invalid color value!");
		}
		free(rgb[i]);
		rgb[i] = trimmed;
		i++;
	}
	assign_check_color(game, color, rgb);
	ft_free_split(rgb);
}

int	ft_alldigit(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	ft_free_split(char **array)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}
