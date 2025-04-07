/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grial <grial@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 18:06:33 by grial             #+#    #+#             */
/*   Updated: 2024/04/24 18:06:35 by grial            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	unsigned int	i;

	i = ft_strlen(s);
	write(fd, s, i);
	write(fd, "\n", 1);
}
/*
#include <fcntl.h>  
#include <stdlib.h> 

int main(void)
{
	int fd = open("mensaje.txt", O_WRONLY | O_CREAT);

	char *message = "¡Hola, mundo!";
	ft_putendl_fd(message, fd);
	close(fd);
}*/
