/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasapog <tkasapog@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:36:53 by tkasapog          #+#    #+#             */
/*   Updated: 2024/04/29 17:10:23 by tkasapog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

static int	ft_free(char **str, int size)
{
	while (size--)
		free(str[size]);
	return (-1);
}

static int	count_words(const char *str, char charset)
{
	int	i;
	int	words;

	words = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i + 1] == charset || str[i + 1] == '\0')
			&& (str[i] == charset || str [i] == '\0') == 0)
			words++;
		i++;
	}
	return (words);
}

static void	w_word(char *dest, const char *from, char charset)
{
	int	i;

	i = 0;
	while (!(from[i] == charset || from [i] == '\0'))
	{
		dest[i] = from[i];
		i++;
	}
	dest[i] = '\0';
}

static int	w_split(char **split, const char *str, char charset)
{
	int	i;
	int	j;
	int	word;

	word = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] == charset || str[i] == '\0') == 1)
			i++;
		else
		{
			j = 0;
			while ((str[i + j] == charset || str[i + j] == '\0') == 0)
				j++;
			split[word] = (char *)malloc(sizeof(char) * (j + 1));
			if (split[word] == NULL)
				return (ft_free(split, word - 1));
			w_word(split[word], str + i, charset);
			i += j;
			word++;
		}
	}
	return (0);
}

char	**ft_split(const char *str, char c)
{
	char	**res;
	int		words;

	words = count_words(str, c);
	res = (char **)malloc(sizeof(char *) * (words + 1));
	if (res == NULL)
		return (NULL);
	res[words] = 0;
	if (w_split(res, str, c) == -1)
		return (NULL);
	return (res);
}
/*
int main() {
    const char *str = "Hello,world,this,is,a,test";
    char **split = ft_split(str, ',');

    if (split == NULL) {
        printf("Error: Memory allocation failed\n");
        return 1;
    }

    printf("Splitting string \"%s\" using ',' delimiter:\n", str);
    for (int i = 0; split[i] != NULL; i++) {
        printf("%s\n", split[i]);
        free(split[i]); 
    }
    free(split); 
    return 0;
}*/
