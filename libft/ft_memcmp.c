/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasapog <tkasapog@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 12:32:06 by tkasapog          #+#    #+#             */
/*   Updated: 2024/04/26 16:53:42 by tkasapog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*p1 = s1;
	const unsigned char	*p2 = s2;
	size_t				i;

	i = 0;
	while (i < n)
	{
		if (p1[i] != p2[i])
			return (p1[i] - p2[i]);
		i++;
	}
	return (0);
}
/*
int	main()
{
	const char	*str1 = "Hello";
	const char	*str2 = "World";
	int	result;

	result = ft_memcmp(str1, str2, 3);
	if (result == 0)
		printf("The first 3 characters are equal.\n");
	else if (result < 0)
		printf("The first 3 characters of str1 are less.\n");
	else
		printf("The first 3 characters of str1 are more. \n");
	return(0);
}*/
