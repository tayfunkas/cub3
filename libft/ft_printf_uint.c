/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_uint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grial <grial@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 17:31:52 by grial             #+#    #+#             */
/*   Updated: 2024/05/14 15:17:59 by grial            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printf_uint(unsigned int n, int *count)
{
	char	c;

	if (n < 0)
		n = n * (-1);
	if (n > 9)
		ft_printf_uint((n / 10), count);
	c = n % 10 + '0';
	ft_printf_char(c, count);
}
