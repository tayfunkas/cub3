/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasapog <tkasapog@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 15:27:26 by tkasapog          #+#    #+#             */
/*   Updated: 2024/04/26 17:04:57 by tkasapog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (s == NULL || f == NULL)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}
/*
void	convert_to_lower(unsigned int index, char *c)
{
	(void)index;
	if (*c >= 'A' && *c <= 'Z')
		*c = *c - ('A' - 'a');
}

int	main()
{
	char str[] = "HEY thErE!";
	printf("Original string: %s\n", str);
	ft_striteri(str, &convert_to_lower);
	printf("Final string: %s\n", str);
	return (0);
}*/
