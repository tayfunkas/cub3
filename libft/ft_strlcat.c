/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasapog <tkasapog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 17:56:38 by tkasapog          #+#    #+#             */
/*   Updated: 2024/04/29 14:59:02 by tkasapog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	t1;
	size_t	t2;

	if (size == 0)
		return (ft_strlen(src));
	i = 0;
	t1 = ft_strlen(dst);
	t2 = ft_strlen(src);
	if (size <= t1)
		return (t2 + size);
	while (t1 + i < size - 1 && src[i] != '\0')
	{
		dst[t1 + i] = src[i];
		i++;
	}
	dst[t1 + i] = '\0';
	return (t1 + t2);
}
/*
int	main()
{
	char dst[20] = "Hello";
	const char *src = " World!";

	printf("Before strlcat:\n");
	printf("dst: %s\n", dst);
	printf("src: %s\n", src);

	size_t result = ft_strlcat(dst, src, sizeof(dst));
	printf("\nAfter strlcat:\n");
	printf("Resulting length: %zu\n", result);
	return(0);
}*/
