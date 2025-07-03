/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grial <grial@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 18:21:49 by grial             #+#    #+#             */
/*   Updated: 2024/04/25 18:21:56 by grial            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	chr;

	chr = (char)c;
	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == chr)
			return ((char *)(s + i));
		i--;
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>

int main(void)
{
	char s[] = "tripouille";

	printf("Output memmove:	%s\nOutput ft_strrchr:	%s\n")
	printf("Output memmove:	%s\nOutput ft_strrchr:	%s\n");
	printf("Output memmove:	%s\nOutput ft_strrchr:	%s\n");
	printf("Output memmove:	%s\nOutput ft_strrchr:	%s\n");
}*/