/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasapog <tkasapog@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 12:32:48 by tkasapog          #+#    #+#             */
/*   Updated: 2024/04/18 17:25:26 by tkasapog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_isalpha(int c)
{
	return ((c >= 97 && c <= 122) || (c >= 65 && c <= 90));
}
/*

int	main()
{
	printf("Is 'b' alphabetic? %d\n", ft_isalpha('b'));
	printf("Is '9' alphabetic? %d\n", ft_isalpha('9'));
	return (0);
}*/
