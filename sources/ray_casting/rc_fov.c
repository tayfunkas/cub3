/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_fov.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grial <grial@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 18:55:33 by grial             #+#    #+#             */
/*   Updated: 2025/02/21 19:48:31 by grial            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	rc_fov(t_game *game, t_player *player, t_map *map)
{
	double	i;
	double	angle;
	double	dx;
	double	dy;
	double	new_x;
	double	new_y;

	angle = player->player_dir * M_PI / 180.0;
	i = STEP;
	while (1)
	{
		dy = cos(angle) * i;
		dx = -sin(angle) * i;
		new_x = player->player_x + dx;
		new_y = player->player_y + dy;
		if (!check_collision(map, new_x, new_y))
			break ;
		mlx_pixel_put(game->mlx_ptr, game->mlx_window, new_y * 8, new_x * 8, 0x00FF00);
		i += STEP;
	}
}