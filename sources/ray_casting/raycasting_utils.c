/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrielrial <gabrielrial@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 17:53:10 by grial             #+#    #+#             */
/*   Updated: 2025/06/03 19:53:13 by gabrielrial      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

double	to_rad(double ang)
{
	double	rad;

	rad = ang * (M_PI / 180.0);
	return (rad);
}

void	fix_ang(t_ray *ray, double player_dir, double i)
{
	ray->r_dir = player_dir + i;
	if (ray->r_dir < 0)
		ray->r_dir += 360.0;
	if (ray->r_dir >= 360.0)
		ray->r_dir = fmod(ray->r_dir, 360.0);
}

void	fix_fisheye(t_game *game, t_ray *ray)
{
	double	ang;

	ang = (double)game->player->dir - ray->r_dir;
	if (ang < 0)
		ang += 360.0;
	if (ang >= 360.0)
		ang = fmod(ang, 360.0);
	ang = to_rad(ang);
	ray->dis_f = ray->dis_f * cos(ang);
}

void	set_wall_draw_limits(t_ray *ray, t_rend *rcast)
{
	rcast->height = ((BLOCK * WIN_H) / (ray->dis_f * BLOCK));
	rcast->draw_start = (int)((WIN_H / 2.0) - (rcast->height / 2.0));
	if (rcast->draw_start < 0)
		rcast->draw_start = 0;
	rcast->draw_end = (int)((WIN_H / 2.0) + (rcast->height / 2.0));
	if (rcast->draw_end > WIN_H)
		rcast->draw_end = WIN_H;
}

int	get_offset_y(int tex_y)
{
	if (tex_y < 0)
		return (0);
	if (tex_y >= BLOCK)
		return (BLOCK - 1);
	return (tex_y);
}
