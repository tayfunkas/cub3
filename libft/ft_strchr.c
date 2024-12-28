/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasapog <tkasapog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 21:20:33 by tkasapog          #+#    #+#             */
/*   Updated: 2024/04/27 18:21:29 by tkasapog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}
/*
int	main()
{
	const char	*str = "Hello, world!";
	char target = 'o';

	char *result = ft_strchr(str, target);
	if (result != 0)
		printf("Found at position: %ld\n", result - str);
	else
		printf("Not found in the string.\n");
	return (0);
}*/
