/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasapog <tkasapog@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 14:35:49 by tkasapog          #+#    #+#             */
/*   Updated: 2024/04/26 17:02:47 by tkasapog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h> 
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	len;
	unsigned int	i;
	char			*result;

	if (!s || !f)
		return (NULL);
	i = 0;
	len = 0;
	while (s[len])
		len++;
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	while (i < len)
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[len] = '\0';
	return (result);
}
/*
char	decrement_char(unsigned int index, char c)
{
	(void)index;
	return (c - 1);
}

int	main()
{
	char	*original = "Hey there";
	char	*result = ft_strmapi(original, &decrement_char);
	
	if (result != NULL)
	{
		printf("Original: %s\n", original);
		printf("New: %s\n", result);
		free(result);
	}
	else
	printf("Error");
	return (0);
}*/
