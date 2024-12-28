/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasapog <tkasapog@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 16:56:44 by tkasapog          #+#    #+#             */
/*   Updated: 2024/04/26 17:03:29 by tkasapog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <unistd.h>
//#include <fcntl.h>
//#include <stdio.h> 
#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
}
/*
int	main()
{
	int	fd;
	char	str[] = "Hello world!";

	fd = open("examplestr.text", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		perror("open");
		return (1);
	}
	ft_putstr_fd(str, fd);
	if (close(fd) == -1)
	{
		perror("close");
		return (1);
	}
	return (0);
}*/
