/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_addr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grial <grial@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 15:48:05 by grial             #+#    #+#             */
/*   Updated: 2024/05/15 13:18:02 by grial            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_address(unsigned long i, int *count)
{
	unsigned long	tmp;

	if (i > 15)
	{
		tmp = i / 16;
		ft_address(tmp, count);
		ft_address((i % 16), count);
	}
	else
		ft_printf_char(ft_hexadecimal(i), count);
}

void	ft_printf_addr(unsigned long i, int *count)
{
	if (!i)
	{
		ft_printf_str("(nil)", count);
		return ;
	}
	ft_printf_str("0x", count);
	ft_address(i, count);
}
