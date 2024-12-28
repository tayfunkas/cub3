/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasapog <tkasapog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:47:32 by tkasapog          #+#    #+#             */
/*   Updated: 2024/04/27 18:03:26 by tkasapog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	little_len;

	i = 0;
	j = 0;
	little_len = ft_strlen(little);
	if (*little == '\0')
		return ((char *)big);
	if (len == 0 || len < little_len)
		return (NULL);
	while (i < len && big[i] != '\0')
	{
		j = 0;
		while (little[j] != '\0' && i + j < len && big[i + j] == little[j])
			j++;
		if (little[j] == '\0')
			return ((char *)(big + i));
		i++;
	}
	return (NULL);
}
/*
int	main()
{
	const char *big = "Hello worl! I am testing my code.";
	const char *little = "test";
	size_t len = 30;

	char	*result = ft_strnstr(big, little, len);
	if (result != 0)
		printf("'%s' found at position %ld.\n", little, result - big);
	else
		printf("'%s' not found.\n", little);
	return (0);
}*/