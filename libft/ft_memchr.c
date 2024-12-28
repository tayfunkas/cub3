/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasapog <tkasapog@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 11:58:21 by tkasapog          #+#    #+#             */
/*   Updated: 2024/04/26 16:52:47 by tkasapog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*p = s;
	size_t				i;

	i = 0;
	while (i < n)
	{
		if (p[i] == (unsigned char)c)
			return ((void *)(p + i));
		i++;
	}
	return (NULL);
}
/*
int	main()
{
	const char str[] = "Hello, world!";
	int target = 'o';
	size_t n = 14;
	void	*result = ft_memchr(str, target, n);
	if (result != NULL)
		printf("Character at position: %ld\n", 
			(unsigned char *)result - (unsigned char *)str);
	else 
		printf("Character '%c' not found in the string.\n", target);
	return (0);
}*/
