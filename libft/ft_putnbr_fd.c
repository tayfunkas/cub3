/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasapog <tkasapog@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:40:45 by tkasapog          #+#    #+#             */
/*   Updated: 2024/04/26 17:04:31 by tkasapog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <unistd.h>
//#include <fcntl.h>
//#include <stdio.h>
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
	}
	ft_putchar_fd('0' + n % 10, fd);
}
/*
int main(void)
{
	int fd;	

	fd = open("examplenbr.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1) 
	{
		perror("open");
		return (1);
	}
	ft_putnbr_fd(-21473648, fd);
	if (close(fd) == -1)
	{
		perror("close");
		return (1);
	}
	return(0);
}*/
