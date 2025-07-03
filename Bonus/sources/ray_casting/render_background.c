/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_background.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grial <grial@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:17:44 by grial             #+#    #+#             */
/*   Updated: 2025/06/03 14:56:21 by grial            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	render_background(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < WIN_H)
	{
		x = 0;
		while (x < WIN_W)
		{
			if (y < WIN_H / 2)
				my_mlx_pixel_put(game, x, y,
					game->engine->ceiling_color->color);
			if (y >= WIN_H / 2)
				my_mlx_pixel_put(game, x, y, game->engine->floor_color->color);
			x++;
		}
		y++;
	}
}
