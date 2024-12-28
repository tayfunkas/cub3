/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasapog <tkasapog@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:04:35 by tkasapog          #+#    #+#             */
/*   Updated: 2024/04/26 16:40:18 by tkasapog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
/*
int	main()
{
	char	buffer[20];
	size_t	i;

	i = 0;
	printf("Before memset: ");
	while (i < sizeof(buffer))
	{
		printf("%c ", buffer[i]);
		i++;
	}
	printf("\n");
	ft_memset(buffer, 'A', sizeof(buffer));
	printf("After memset: ");
	i = 0;
	while (i < sizeof(buffer))
	{
		printf("%c ", buffer[i]);
		i++;
	}
	printf("\n");
	return(0);
}*/
