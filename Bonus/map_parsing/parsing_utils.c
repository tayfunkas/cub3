/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasapog <tkasapog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 09:34:40 by tkasapog          #+#    #+#             */
/*   Updated: 2025/06/04 17:03:55 by tkasapog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	ft_arraylen(char **array)
{
	int	len;

	len = 0;
	while (array && array[len])
		len++;
	return (len);
}

char	*ft_strtrim_spaces(char *line)
{
	while (*line == ' ')
		line++;
	return (line);
}

int	ft_is_all_spaces(char *line)
{
	while (*line)
	{
		if (*line != ' ' || *line != '\t' || *line != '\n')
			return (0);
		line++;
	}
	return (1);
}

bool	is_valid_tile(char c)
{
	return (c == '0' || c == '1');
}

void	count_commas(t_game *game, const char *line)
{
	int	count;

	count = 0;
	while (*line)
	{
		if (*line == ',')
			count++;
		line++;
	}
	if (count != 2)
		game->error = 1;
}
