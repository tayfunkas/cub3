/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grial <grial@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 17:53:10 by grial             #+#    #+#             */
/*   Updated: 2025/06/02 10:54:35 by grial            ###   ########.fr       */
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

void	fish_eye(t_game *game, t_ray *ray)
{
	double	fish;

	fish = (double)game->player->dir - ray->r_dir;
	if (fish < 0)
		fish += 360.0;
	if (fish >= 360.0)
		fish = fmod(fish, 360.0);
	fish = to_rad(fish);
	ray->dis_f = ray->dis_f * cos(fish);
}

void	funct(t_ray *ray, t_rcast *rcast)
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
	return (0);
}
