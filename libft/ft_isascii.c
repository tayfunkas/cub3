/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasapog <tkasapog@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:44:10 by tkasapog          #+#    #+#             */
/*   Updated: 2024/04/18 14:49:02 by tkasapog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}
/*
int	main()
{
	printf("is 'k' ascii? %d\n", ft_isascii('k'));
	printf("is 'Ç' ascii? %d\n", ft_isascii('Ç'));
	return (0);
}*/
