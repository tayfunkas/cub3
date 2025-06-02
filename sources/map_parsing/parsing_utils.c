/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasapog <tkasapog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 09:34:40 by tkasapog          #+#    #+#             */
/*   Updated: 2025/06/02 16:25:24 by tkasapog         ###   ########.fr       */
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
