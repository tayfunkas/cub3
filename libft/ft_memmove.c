/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grial <grial@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 15:45:33 by grial             #+#    #+#             */
/*   Updated: 2024/04/25 15:46:01 by grial            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (!dst && !src)
		return (NULL);
	if ((char *)dst > (char *)src)
	{
		i = len;
		while (i > 0)
		{
			((char *)dst)[i - 1] = ((const char *)src)[i - 1];
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < len)
		{
			((char *)dst)[i] = ((const char *)src)[i];
			i++;
		}
	}
	return (dst);
}
/*
#include <string.h>
#include <stdio.h>

int main(void)
{
	char a[10] = "123456789";
	char b[10] = "123456789";

	char c[5] = "1234";
	char d[5] = "abcd";

	char e[5] = "1234";
	char f[5] = "abcd";

	memmove(&b[2], b, 4);
	ft_memmove(&a[2], a, 4);
	memmove(c, d, 4);
	ft_memmove(e, f, 4);

	printf("Output memmove:		%s\nOutput ft_memmove:	%s\n", b, a);
	printf("Output memmove:		%s\nOutput ft_memmove:	%s\n", c, e);
}*/
