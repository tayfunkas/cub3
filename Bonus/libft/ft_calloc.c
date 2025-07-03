/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grial <grial@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 17:58:44 by grial             #+#    #+#             */
/*   Updated: 2024/05/06 11:59:06 by grial            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	i;
	void	*mem;
	size_t	index;

	index = 0;
	if (size > 0 && (nmemb > (4294967295 / size)))
		return (0);
	if (size == 0 && nmemb == 0)
	{
		mem = (char *)malloc(sizeof(char *) * index);
		return (mem);
	}
	i = (size * nmemb);
	mem = malloc(i);
	if (mem == NULL)
		return (NULL);
	while (i > 0)
	{
		((char *)mem)[index] = 0;
		i--;
		index++;
	}
	return (mem);
}
/*
#include <string.h>
#include <stdio.h>

int main(void)
{
    char*    x;
    char*    y;

    x = ft_calloc(5, 2147483648);
    y = calloc(5, 65535);
}*/
