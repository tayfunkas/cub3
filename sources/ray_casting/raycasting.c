/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grial <grial@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 17:53:10 by grial             #+#    #+#             */
/*   Updated: 2025/05/20 18:05:59 by grial            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	raycasting(t_game *game, t_ray *ray)
{
	int	i;
	int	a;
	int	color;
	int	start_x;
	int	start_y;

	double dx = 0.0;
	double dy = 0.0;
	start_x = (int)(game->player->pos_x * BLOCK);
	start_y = (int)(game->player->pos_y * BLOCK);
	i = 0;
	a = game->player->dir - FOV / 2;
	while (i < FOV)
	{
		ray_ang(ray, a, i);
		dx = cos(to_rad(game->player->dir)) * i;
		dy = -sin(to_rad(game->player->dir)) * i;
		color = 0xFF0F0F;
		my_mlx_pixel_put(game, start_x + (int)dx, start_y + (int)dy, color);
        //check_wall(game);
		i += 1;
		printf("%i\n", i);
	}
}

