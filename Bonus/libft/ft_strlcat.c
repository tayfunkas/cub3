/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grial <grial@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 12:42:51 by grial             #+#    #+#             */
/*   Updated: 2024/05/07 23:02:49 by grial            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	x;
	size_t	dlen;
	size_t	srclen;

	x = 0;
	i = 0;
	dlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (size <= dlen)
		return (size + srclen);
	while (dst[i] && i < size - 1)
		i++;
	while (src[x] && i < size - 1)
	{
		dst[i] = src[x];
		i++;
		x++;
	}
	dst[i] = '\0';
	return (dlen + srclen);
}
/*
size_t strlcat(dst, src, siz)
char *dst;
const char *src;
size_t siz;
{
	char *d = dst;
	const char *s = src;
	size_t n = siz;
	size_t dlen;

	while (n-- != 0 && *d != '\0')
		d++;
	dlen = d - dst;
	n = siz - dlen;

	if (n == 0)
		return (dlen + strlen(s));
	while (*s != '\0')
	{
		if (n != 1)
		{
			*d++ = *s;
			n--;
		}
		s++;
	}
	*d = '\0';

	return (dlen + (s - src));
}

#include <stdio.h>
#include <string.h>

int main(void)
{
	char *src = "Go";
	char ft_dst[11] = "Hi, ?";
	char dst[11] = "Hi, ?";
	size_t size = 1;

	size_t ft_dst_len = ft_strlcat(ft_dst, src, size);
	size_t dst_len = strlcat(dst, src, size);

	printf("Output ft_strlcat:	%zu String:	%s\n", ft_dst_len, ft_dst);
	printf("Output strlcat:		%zu String:	%s\n", dst_len, dst);
}*/