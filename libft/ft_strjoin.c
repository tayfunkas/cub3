/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasapog <tkasapog@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 19:43:30 by tkasapog          #+#    #+#             */
/*   Updated: 2024/04/26 16:56:55 by tkasapog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*joined_str;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
		i++;
	while (s2[j] != '\0')
		j++;
	joined_str = (char *)malloc((i + j + 1) * sizeof(char));
	if (joined_str == NULL)
		return (NULL);
	i = 0;
	while (*s1)
		joined_str[i++] = *s1++;
	while (*s2)
		joined_str[i++] = *s2++;
	joined_str[i] = '\0';
	return (joined_str);
}
/*
int	main()
{
	char	*s1 = "Hey ";
	char	*s2 = "There";

	char	*final_str = ft_strjoin(s1, s2);
	if (final_str == NULL)
	{
		printf("Error\n");
		return (1);
	}
	printf("%s\n", final_str);
	free(final_str);
	return(0);
}*/
