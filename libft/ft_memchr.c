/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grial <grial@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:30:16 by grial             #+#    #+#             */
/*   Updated: 2024/04/25 17:30:18 by grial            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	ch;

	i = 0;
	str = (unsigned char *)s;
	ch = (unsigned char)c;
	while (i < n)
	{
		if (str[i] == ch)
			return ((void *)s + i);
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>

int main(void)
{
	char	*str;
	char	to_find;
	char	*myFun;
	char	*memch;
	size_t	l;

	l = 4;
	str = "Hola";
	to_find = 0;

	myFun = ft_memchr(str, to_find, l);
	memch = memchr(str, to_find, l);

	printf("Output ft_memchr: %s\nOutpur memchr:	  %s", myFun, memch);
}*/
