/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grial <grial@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 09:34:40 by tkasapog          #+#    #+#             */
/*   Updated: 2025/02/19 13:33:33 by grial            ###   ########.fr       */
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
