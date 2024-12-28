/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasapog <tkasapog@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:29:56 by tkasapog          #+#    #+#             */
/*   Updated: 2024/04/26 16:55:54 by tkasapog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	int		i;
	int		j;	
	char	*new_str;

	if (src == 0)
		return (0);
	i = 0;
	while (src[i] != '\0')
	{
		i++;
	}
	new_str = (char *)malloc((i + 1) * sizeof(char));
	if (new_str == NULL)
		return (NULL);
	j = 0;
	while (src[j] != '\0')
	{
		new_str[j] = src[j];
		j++;
	}
	new_str[j] = '\0';
	return (new_str);
}
