/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasapog <tkasapog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 18:57:12 by tkasapog          #+#    #+#             */
/*   Updated: 2024/04/27 17:24:09 by tkasapog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;

	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	substr = malloc(sizeof(char) * (len + 1));
	if (substr == NULL)
		return (NULL);
	ft_strlcpy(substr, s + start, len + 1);
	return (substr);
}
/*
int	main()
{
	char	*o_s = "Hello, World!";
	unsigned int	s_i = 7;
	size_t	substring_length = 5;

	char	*substring = ft_substr(o_s, s_i, substring_length);
	if (substring == 0)
	{
		printf("Error\n");
		return (1);
	}
	printf("Original: %s\n", o_s);
	printf("Substring: %s\n", substring);

	free(substring);
	return(0);
}*/
