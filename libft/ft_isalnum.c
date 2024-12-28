/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasapog <tkasapog@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 12:42:32 by tkasapog          #+#    #+#             */
/*   Updated: 2024/04/18 17:36:04 by tkasapog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_isalnum(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
		|| (c >= '0' && c <= '9'))
		return (1);
	else
		return (0);
}
/*

int	main()
{
	printf("Is 'b' alphanumberic? %d\n", ft_isalnum('b'));
	printf("Is '9' alphanumberic? %d\n", ft_isalnum('9'));
	printf("Is 'b' alphanumberic? %d\n", ft_isalnum(' '));
	printf("Is 'b' alphanumberic? %d\n", ft_isalnum('*'));
	return (0);
}*/
