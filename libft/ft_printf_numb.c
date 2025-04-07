/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_numb.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grial <grial@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 16:43:15 by grial             #+#    #+#             */
/*   Updated: 2024/05/14 12:26:57 by grial            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printf_numb(int n, int *count)
{
	char	c;

	if (n == -2147483648)
	{
		ft_printf_str("-2147483648", count);
		return ;
	}
	if (n < 0)
	{
		ft_printf_char('-', count);
		n = n * (-1);
	}
	if (n > 9)
		ft_printf_numb((n / 10), count);
	c = n % 10 + '0';
	ft_printf_char(c, count);
}
