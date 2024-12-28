/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasapog <tkasapog@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 11:17:34 by tkasapog          #+#    #+#             */
/*   Updated: 2024/04/27 14:26:07 by tkasapog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		s_length;

	s_length = 0;
	if (s == NULL)
		return (NULL);
	while (s[s_length] != '\0')
	{
		s_length++;
	}
	while (s_length >= 0)
	{
		if (s[s_length] == (char)c)
		{
			return ((char *)&s[s_length]);
		}
		s_length--;
	}
	return (NULL);
}
/*
int	main()
{
	const char	*str = "Hello, world!";
	char	target = 'o';

	char	*result = ft_strrchr(str, target);
	if (result != 0)
		printf("Found at the position: %ld\n", result - str);
	else
		printf("Not found in the string.\n");
	return (0);
}*/
