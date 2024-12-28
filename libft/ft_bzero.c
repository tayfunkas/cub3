/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasapog <tkasapog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 16:58:02 by tkasapog          #+#    #+#             */
/*   Updated: 2024/04/27 17:08:19 by tkasapog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
}
/*
int	main()
{
	char	buffer[20];
	size_t	i;

	i = 0;
	printf("Before bzero: ");
	while (i < sizeof(buffer))
	{
		printf("%c ", buffer[i]);
		i++;
	}
	ft_bzero(buffer, sizeof(buffer));
	printf("After bzero: ");
	while (i < sizeof(buffer))
	{
		printf("%c ", buffer[i]);
		i++;
	}
	printf("\n");
	return (0);
}*/
