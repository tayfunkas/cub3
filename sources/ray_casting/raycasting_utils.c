/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grial <grial@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 17:53:10 by grial             #+#    #+#             */
/*   Updated: 2025/05/22 15:39:26 by grial            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

double	to_rad(double ang)
{
	double	rad;

	rad = ang * (M_PI / 180.0);
	printf("rad %f\n", rad);
	return (rad);
}

void	ray_ang(t_ray *ray, int	player_dir, int i)
{
	ray->ray_a = player_dir + i;
	if (ray->ray_a < 0)
		ray->ray_a += 360;
	if (ray->ray_a >= 360)
		ray->ray_a %= 360;
}