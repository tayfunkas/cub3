/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grial <grial@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 18:18:23 by grial             #+#    #+#             */
/*   Updated: 2024/05/08 11:34:26 by grial            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	c1;
	unsigned char	c2;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		c1 = (unsigned char)s1[i];
		c2 = (unsigned char)s2[i];
		if (c1 == c2)
			i++;
		else
			return (c1 - c2);
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>

int main(void)
{
	printf("%i\n", ft_strncmp("1234", "1235", -1));
	printf("%i\n", ft_strncmp("1234", "1235", -1));
	printf("%i\n", ft_strncmp("Tripouille", "TriPouille", 42));
	printf("%i\n", ft_strncmp("Tripouille", "TripouillE", 42));
	printf("%i\n", ft_strncmp("Tripouille", "TripouilleX", 42));
	printf("%i\n", ft_strncmp("Tripouille", "Tripouill", 42));
	printf("%d\n", ft_strncmp("test\200", "test\0", 6));
	printf("%d\n", strncmp("test\200", "test\0", 6));
	return 0;
}*/
