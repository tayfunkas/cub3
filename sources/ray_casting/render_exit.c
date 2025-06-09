/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grial <grial@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 17:53:10 by grial             #+#    #+#             */
/*   Updated: 2025/06/09 17:46:03 by grial            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	render_exit(t_game *game, t_ray *ray, t_rend *rcast)
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
		exit_dist(game, game->map, ray);
		if (is_exit(game->map, ray->hit_y, ray->hit_x))
		{
			printf("Exit.\n");
			render_exit_column(game, ray, rcast, win_x);
		}
		ang_d += ray->r_step;
		win_x += 1;
	}
}

void	render_exit_column(t_game *game, t_ray *ray, t_rend *rcast, int win_x)
{
	double	pos_y;
	int		tex_y;
	int		y;

	rcast->offset_x = get_texture_offset_x(game, ray);
	fix_fisheye(game, ray);
	set_wall_draw_limits(ray, rcast);
	rcast->step_texture = (double)BLOCK / rcast->height;
	pos_y = (rcast->draw_start - ((WIN_H / 2.0) - (rcast->height / 2.0)))
		* rcast->step_texture;
	y = rcast->draw_start;
	while (y < rcast->draw_end)
	{
		tex_y = ((int)pos_y) & (64 - 1);
		rcast->color = get_pixel_color(game->engine->ex_img, rcast->offset_x,
				tex_y);
		if (rcast->color == 0x000000)
			my_mlx_pixel_put(game, win_x, y, rcast->color);
		pos_y += rcast->step_texture;
		y++;
	}
}

void	exit_dist(t_game *game, t_map *map, t_ray *ray)
{
	vertical_values(game, ray);
	exit_dist_vertical(game, map, ray);
	horizontal_values(game, ray);
	exit_dist_horizontal(game, map, ray);
	dist_to_exit(ray);
}

void	dist_to_exit(t_ray *ray)
{
	if (ray->dis_h < ray->dis_v && ray->dis_h > 0.0)
	{
		ray->r_side = 1;
		ray->dis_f = ray->dis_h;
		ray->hit_x = ray->ray_hx;
		ray->hit_y = ray->ray_hy;
	}
	else
	{
		ray->r_side = 0;
		ray->dis_f = ray->dis_v;
		ray->hit_x = ray->ray_vx;
		ray->hit_y = ray->ray_vy;
	}
}
