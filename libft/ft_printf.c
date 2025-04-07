/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grial <grial@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 18:07:21 by grial             #+#    #+#             */
/*   Updated: 2024/05/15 12:55:43 by grial            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	conversions(char c, va_list args, int *count)
{
	if (c == 'c')
		ft_printf_char(va_arg(args, int), count);
	else if (c == 's')
		ft_printf_str(va_arg(args, char *), count);
	else if (c == 'p')
		ft_printf_addr(va_arg(args, unsigned long), count);
	else if (c == 'i' || c == 'd')
		ft_printf_numb(va_arg(args, int), count);
	else if (c == 'u')
		ft_printf_uint(va_arg(args, unsigned int), count);
	else if (c == 'x')
		ft_printf_hexa(va_arg(args, unsigned int), count);
	else if (c == 'X')
		ft_printf_hexaupper(va_arg(args, unsigned int), count);
	else if (c == '%')
		ft_printf_char('%', count);
}

int	ft_printf(const char *str, ...)
{
	int		count;
	va_list	args;

	count = 0;
	if (!str)
		return (-1);
	va_start(args, str);
	while (*str != '\0')
	{
		if (*str == '%')
		{
			str++;
			conversions(*str, args, &count);
		}
		else
			ft_printf_char(*str, &count);
		str++;
	}
	va_end(args);
	return (count);
}
