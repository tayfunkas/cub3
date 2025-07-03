/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grial <grial@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 11:32:36 by grial             #+#    #+#             */
/*   Updated: 2024/09/01 18:57:47 by grial            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_free(char **strs, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (NULL);
}

static int	count_word(const char *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
	}
	return (count);
}

static char	*alloc_word(const char *start, int len)
{
	char	*word;
	int		i;

	word = malloc(len + 1);
	if (!word)
		return (NULL);
	i = 0;
	if (word)
	{
		while (i < len)
		{
			word[i] = start[i];
			i++;
		}
		word[len] = '\0';
	}
	return (word);
}

char	*ft_strartword(const char *s, char c)
{
	while (*s == c)
		s++;
	return ((char *)s);
}

char	**ft_split(char const *s, char c)
{
	char		**str;
	int			i;
	const char	*start;

	str = malloc((count_word(s, c) + 1) * sizeof(char *));
	if (!str || !s)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		start = s;
		while (*s && *s != c)
			s++;
		if (s > start)
		{
			str[i] = alloc_word(start, s - start);
			if (!(str[i]))
				return (ft_free(str, i));
			i++;
		}
	}
	str[i] = NULL;
	return (str);
}
