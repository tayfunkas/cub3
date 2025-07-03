/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grial <grial@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:42:01 by grial             #+#    #+#             */
/*   Updated: 2024/05/13 13:56:39 by grial            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_itoa_storing(char *str, int size, int n)
{
	while (n > 0)
	{
		size--;
		str[size] = (n % 10) + '0';
		n /= 10;
	}
}

static size_t	ft_itoa_char_count(int n)
{
	int	i;

	i = 1;
	if (n < 0)
	{
		i++;
		n = n * (-1);
	}
	while (n > 9)
	{
		if (n > 9)
			n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	size;

	if (n == -2147483648)
	{
		return (ft_strdup("-2147483648"));
	}
	size = ft_itoa_char_count(n);
	str = malloc(sizeof(char) * (size + 1));
	if (!str)
		return (0);
	if (n < 0)
	{
		str[0] = '-';
		ft_itoa_storing(str, size, -n);
	}
	else if (n == 0)
		ft_strlcpy(str, "0", 2);
	else
		ft_itoa_storing(str, size, n);
	str[size] = '\0';
	return (str);
}
/*
#include <stdio.h>

int	main(void)
{
	int i;
	i = INT_MIN;
	char *str = ft_itoa(i);
	printf("%s", str);
}*/