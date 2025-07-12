/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grial <grial@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 17:53:10 by grial             #+#    #+#             */
/*   Updated: 2025/07/12 20:24:06 by grial            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	raycasting(t_game *game, t_ray *ray, t_rend *rcast)
{
	int		dir_i;
	int		win_x;
	double	ang_d;

	dir_i = game->player->dir + (FOV / 2);
	win_x = 0;
	ang_d = 0.0;
	while (win_x < WIN_W)
	{
		fix_ang(ray, dir_i, -ang_d);
		wall_dist(game, game->map, ray);
		get_tex(game, ray);
		render_wall_column(game, ray, rcast, win_x);
		ang_d += ray->r_step;
		win_x += 1;
	}
}
