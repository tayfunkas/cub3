/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grial <grial@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 18:25:22 by grial             #+#    #+#             */
/*   Updated: 2024/05/08 11:35:04 by grial            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*chr_in_start(const char *s1, const char *set)
{
	size_t	i;
	size_t	s;

	i = 0;
	s = 0;
	while (set[s] != '\0')
	{
		if (s1[i] == set[s])
		{
			i++;
			s = 0;
			if (s1[i] == '\0')
				return (NULL);
		}
		else
			s++;
	}
	return ((char *)s1 + i);
}

static char	*chr_in_end(const char *s1, const char *set)
{
	size_t	i;
	size_t	s;

	s = 0;
	i = ft_strlen(s1) - 1;
	while (set[s] != '\0')
	{
		if (s1[i] == set[s])
		{
			i--;
			s = 0;
			if (i == 0)
				return (NULL);
		}
		else
			s++;
	}
	return ((char *)s1 + i);
}

static char	*return_empty(void)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * 1);
	str[0] = 0;
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	char	*start;
	char	*finish;
	size_t	size;

	if (!s1 || !set)
		return (NULL);
	start = chr_in_start(s1, set);
	finish = chr_in_end(s1, set);
	if (start == NULL || finish == NULL)
		return (return_empty());
	size = (size_t)(finish - start + 2);
	str = (char *)malloc(sizeof(char) * (size));
	if (!str)
		return (0);
	ft_strlcpy(str, start, (size));
	return (str);
}
/*
#include <stdio.h>

int main(void)
{
	// char *s1 = "lorem \n ipsum \t dolor \n sit \t amet";
	// char *a = "ab";
	char *c = "";
	printf("Contendio de s: %d\n", c[0]);
	printf("Funcion: %s", ft_strtrim("", "123"));
	return (0);
}*/
