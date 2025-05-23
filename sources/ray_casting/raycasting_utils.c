/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grial <grial@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 17:53:10 by grial             #+#    #+#             */
/*   Updated: 2025/05/23 12:32:18 by grial            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

double	to_rad(double ang)
{
	double	rad;

	rad = ang * (M_PI / 180.0);
	return (rad);
}

void	fix_ang(t_ray *ray, double	player_dir, double i)
{
	ray->r_dir = player_dir + i;
	if (ray->r_dir < 0)
		ray->r_dir += 360.0;
	if (ray->r_dir >= 360.0)
		ray->r_dir = fmod(ray->r_dir, 360.0);
}