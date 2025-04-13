/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasapog <tkasapog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 09:33:31 by tkasapog          #+#    #+#             */
/*   Updated: 2025/04/13 18:02:20 by tkasapog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	assign_check_color(t_game *game, t_color *color, char **rgb)
{
	color->r = ft_atoi(rgb[0]);
	color->g = ft_atoi(rgb[1]);
	color->b = ft_atoi(rgb[2]);
	if (color-> r < 0 || color-> r > 255 || color->g < 0 
		|| color->g > 255 || color->b < 0 || color->b > 255)
	{
		ft_free_split(rgb);
		game->error = 1;
	}
}

void	parse_color(t_game *game, char *line, t_color *color)
{
	char	**rgb;
	char	*trimmed;
	int		i;

	i = 0;
	rgb = ft_split(line, ',');
	if (!rgb || ft_arraylen(rgb) != 3)
	{
		ft_free_split(rgb);
		game->error = 1;
		return ;
	}
	while (i < 3)
	{
		trimmed = ft_strtrim(rgb[i], " \n");
		if (!trimmed || !ft_alldigit(trimmed))
			game->error = 1;
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
