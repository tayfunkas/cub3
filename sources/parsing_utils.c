/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasapog <tkasapog@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 09:34:40 by tkasapog          #+#    #+#             */
/*   Updated: 2025/01/02 09:34:41 by tkasapog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3.h"

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
