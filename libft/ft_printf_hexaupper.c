/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexaupper.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grial <grial@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 18:12:09 by grial             #+#    #+#             */
/*   Updated: 2024/05/15 12:08:18 by grial            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	ft_charupcase(char c)
{
	if (c >= 'a' && c <= 'z')
		c = c - 'a' + 'A';
	return (c);
}

void	ft_printf_hexaupper(unsigned long i, int *count)
{
	unsigned long	tmp;

	if (i > 15)
	{
		tmp = i / 16;
		ft_printf_hexaupper(tmp, count);
		ft_printf_hexaupper((i % 16), count);
	}
	else
		ft_printf_char(ft_charupcase(ft_hexadecimal(i)), count);
}
