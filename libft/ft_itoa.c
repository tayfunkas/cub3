/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasapog <tkasapog@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 11:58:40 by tkasapog          #+#    #+#             */
/*   Updated: 2024/04/26 17:01:31 by tkasapog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h> 
#include "libft.h"

static int	get_length(int n)
{
	int	length;

	length = 0;
	if (n == 0)
		return (1);
	if (n == -2147483648)
		return (12);
	if (n < 0)
	{
		length++;
		n = -n;
	}
	while (n != 0)
	{
		length++;
		n = (n / 10);
	}
	return (length);
}

static void	convert_to_string(int n, char *str, int length)
{
	int	sign;
	int	index;

	sign = 1;
	index = length - 1;
	if (n < 0)
	{
		sign = -1;
		n = -n;
	}
	while (index >= 0)
	{
		str[index] = '0' + (n % 10);
		n /= 10;
		index--;
	}
	if (sign == -1)
		str[0] = '-';
}

char	*ft_itoa(int n)
{
	int		length;
	char	*str;

	if (n == -2147483648)
	{
		str = (char *)malloc(12 * sizeof(char));
		if (str == NULL)
			return (NULL);
		ft_strlcpy (str, "-2147483648", 12);
		return (str);
	}
	length = get_length(n);
	str = (char *)malloc((length + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	convert_to_string(n, str, length);
	str[length] = '\0';
	return (str);
}
/*
int main(void)
{
	printf("%s\n", ft_itoa(33));
	printf("%s\n", ft_itoa(-33));
	printf("%s\n", ft_itoa(12345));
	printf("%s\n", ft_itoa(-12345));
	printf("%s\n", ft_itoa(98765));
	printf("%s\n", ft_itoa(-98765));
	printf("%s\n", ft_itoa(45));
	printf("%s\n", ft_itoa(-45));
	printf("%s\n", ft_itoa(-2147483648));
	printf("%s\n", ft_itoa(2147483647));
	printf("%s\n", ft_itoa(0));
	return (0);
}*/
