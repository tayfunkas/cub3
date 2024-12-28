/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasapog <tkasapog@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:18:55 by tkasapog          #+#    #+#             */
/*   Updated: 2024/04/29 15:23:55 by tkasapog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] && (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = sign * -1;
		if (str[i + 1] == '+' || str [i + 1] == '-')
			return (0);
		i++;
	}
	while (str[i] <= '9' && str[i] >= '0')
	{
		if ((result == 214748364) && (str[i] == '8') && (sign % 2 == 1))
			return (-2147483648);
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}
/*
int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		printf("Usage: %s <string>\n", argv[0]);
		return 1; 
	}
	char *str = argv[1];
	int num = ft_atoi(str);
	printf("The converted integer is: %d\n", num);
}*/
