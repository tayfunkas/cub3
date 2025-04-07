/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grial <grial@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 18:14:29 by grial             #+#    #+#             */
/*   Updated: 2024/04/24 18:14:43 by grial            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	siz_cpy;

	siz_cpy = size;
	i = 0;
	while (size-- != 0 && src[i] != '\0')
	{
		dst[i] = src[i];
		if (size == 0)
			break ;
		i++;
	}
	if (size == 0 || src[i] == '\0')
	{
		if (siz_cpy != 0)
			dst[i] = '\0';
	}
	while (src[i] != '\0')
		i++;
	return (i);
}
/*
#include <stdio.h>
#include <string.h>

int main(void)
{
	char *src;
	char dst[20];
	int i;

	src = "Hola como estas";
	i = ft_strlcpy(dst, src, 18);
	printf("Output: %i\nString: %s\n", i, dst);
	i = strlcpy(dst, src, 18);
	printf("Output: %i\nString: %s", i, dst);
}*/