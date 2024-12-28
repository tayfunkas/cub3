/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasapog <tkasapog@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 18:30:08 by tkasapog          #+#    #+#             */
/*   Updated: 2024/04/29 17:58:01 by tkasapog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*allocate_and_zero_memory(size_t total_size)
{
	void	*ptr;

	ptr = malloc(total_size);
	if (ptr != NULL)
		ft_memset(ptr, 0, total_size);
	return (ptr);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t			total_size;

	if (nmemb == 0 || size == 0)
		return (allocate_and_zero_memory(1));
	if (nmemb > SIZE_MAX / size)
		return (NULL);
	total_size = nmemb * size;
	return (allocate_and_zero_memory(total_size));
}
/*
int	main()
{
	int	*arr = (int *)ft_calloc(5, sizeof(int));
	free(arr);
	return(0);
}*/
