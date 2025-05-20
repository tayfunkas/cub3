/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grial <grial@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 17:53:10 by grial             #+#    #+#             */
/*   Updated: 2025/05/20 17:59:43 by grial            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

double	to_rad(double ang)
{
	double	rad;

	rad = ang * (M_PI / 180.0);
	return (rad);
}

void	ray_ang(t_ray *ray, int p_ang, int i)
{
	ray->ray_a = p_ang + i;
	if (ray->ray_a < 0)
		ray->ray_a += 360;
	if (ray->ray_a >= 360)
		ray->ray_a %= 360;
}