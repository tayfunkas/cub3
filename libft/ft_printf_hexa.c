/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grial <grial@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 15:52:14 by grial             #+#    #+#             */
/*   Updated: 2024/05/15 12:08:19 by grial            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printf_hexa(unsigned long i, int *count)
{
	unsigned long	tmp;

	if (i > 15)
	{
		tmp = i / 16;
		ft_printf_hexa(tmp, count);
		ft_printf_hexa((i % 16), count);
	}
	else
		ft_printf_char(ft_hexadecimal(i), count);
}
