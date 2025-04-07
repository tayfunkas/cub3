/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grial <grial@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 16:49:14 by grial             #+#    #+#             */
/*   Updated: 2024/04/24 18:29:19 by grial            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	x;

	i = 0;
	if (!*little)
		return ((char *)big);
	while (big[i] != '\0' && i < len && little[0] != '\0')
	{
		x = 0;
		while (big[i] != '\0' && big[i] == little[x] && i < len)
		{
			i++;
			x++;
			if (little[x] == '\0')
				return ((char *)big + (i - x));
		}
		i = i - x + 1;
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>

char *strnstr(const char *s, const char *find, size_t slen)
{
	char c, sc;
	size_t len;

	if ((c = *find++) != '\0') {
		len = strlen(find);
		do {
			do {
				if (slen-- < 1 || (sc = *s++) == '\0')
					return (NULL);
			} while (sc != c);
			if (len > slen)
				return (NULL);
		} while (strncmp(s, find, len) != 0);
		s--;
	}
	return ((char *)s);
}

int	main(void)
{
	char	*str = "Holaoolcwwa";
	char	*to_find = "";

	printf("Output ft_strnstr:	%s\n", ft_strnstr(str, to_find, -1));
	printf("Output strnstr:		%s", strnstr(str, to_find, -1));
}*/