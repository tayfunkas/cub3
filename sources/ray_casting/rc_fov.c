/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_fov.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grial <grial@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 18:55:33 by grial             #+#    #+#             */
/*   Updated: 2025/05/23 13:04:20 by grial            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void cast_single_ray(t_game *game, int x_width, double ray_angle)
{
	(void)x_width;
	double ray_dir_x = cos(ray_angle);
	double ray_dir_y = sin(ray_angle);
	double ray_x = game->player->pos_x;
	double ray_y = game->player->pos_y;

	double delta_dist_x = fabs(1.0 / ray_dir_x);
	double delta_dist_y = fabs(1.0 / ray_dir_y);

	int step_x = (ray_dir_x < 0) ? -1 : 1;
	int step_y = (ray_dir_y < 0) ? -1 : 1;

	int map_x = (int)ray_x;
	int map_y = (int)ray_y;

	double side_dist_x = (ray_dir_x < 0)
							 ? (ray_x - map_x) * delta_dist_x
							 : (map_x + 1.0 - ray_x) * delta_dist_x;

	double side_dist_y = (ray_dir_y < 0)
							 ? (ray_y - map_y) * delta_dist_y
							 : (map_y + 1.0 - ray_y) * delta_dist_y;

	int hit = 0;

	while (!hit)
	{
		if (side_dist_x < side_dist_y)
		{
			side_dist_x += delta_dist_x;
			map_x += step_x;
		}
		else
		{
			side_dist_y += delta_dist_y;
			map_y += step_y;
		}
		if (map_x >= 0 && map_x < game->map->m_height && map_y >= 0 && map_y < (int)ft_strlen(game->map->data[map_x]) && game->map->data[map_x][map_y] == '1')
		{
			hit = 1;
		}
	}

	// Dibuja la pared una vez que se detecta colisión
	//draw_wall(game, x_width, ray_x + ray_dir_x, ray_y + ray_dir_y, ray_angle);
}


// void	draw_fov(t_game *game, t_player *player)
//{
//	int		i;
//	int		dir;
//	double	ray_angle;
//
//	i = 0;
//	while (i < WIN_W)
//	{
//		ray_angle = player->dir - (game->engine->fov / 2.0) + (i
//				* (game->engine->fov / ((float)WIN_W - 1)));
//		if (ray_angle < 0)
//			ray_angle += 2 * M_PI;
//		else if (ray_angle > 2 * M_PI)
//			ray_angle -= 2 * M_PI;
//		get_ang(game->engine->cam, ray_angle);
//		calculate_side_distances(game->player, ray_angle, &game->engine->cam->ray_x, &game->engine->cam->ray_y);
//
//		i++;
//	}
// }


void calculate_side_distances(t_player *player, double ray_angle,
							  double *side_dist_x, double *side_dist_y)
{
	if (ray_angle < 0)
		ray_angle += 2 * M_PI;
	else if (ray_angle > 2 * M_PI)
		ray_angle -= 2 * M_PI;
	if (cos(ray_angle) > 0)
		*side_dist_x = (1.0 - (player->pos_x - floor(player->pos_x))) / cos(ray_angle);
	else if (cos(ray_angle) < 0)
		*side_dist_x = (player->pos_x - floor(player->pos_x)) / cos(ray_angle);
	else
		*side_dist_x = INFINITY;
	if (sin(ray_angle) > 0)
		*side_dist_y = (1.0 - (player->pos_y - floor(player->pos_y))) / sin(ray_angle);
	else if (sin(ray_angle) < 0)
		*side_dist_y = (player->pos_y - floor(player->pos_y)) / sin(ray_angle);
	else
		*side_dist_y = INFINITY;
}

void get_ang(t_ray *cam, double ray_angle)
{
	cam->ray_x = cos(ray_angle);
	cam->ray_y = sin(ray_angle);
}


float distance(float x1, float y1, float x2, float y2)
{
	float dx;
	float dy;

	dx = x2 - x1;
	dy = y2 - y1;
	return (sqrt((dx * dx) + (dy * dy)));
}

void my_mlx_pixel_put(t_game *game, int x, int y, int color)
{
	char *dst;

	if (!game || !game->engine || !game->engine->frame || !game->engine->frame->addr)
	{
		printf("Invalid pointer in my_mlx_pixel_put\n");
		return;
	}
	if (x >= 0 && x < WIN_W && y >= 0 && y < WIN_H)
	{
		dst = game->engine->frame->addr + (y * game->engine->frame->line_length + x * (game->engine->frame->bpp / 8));
		*(unsigned int *)dst = color;
	}
}


float get_height(t_game *game, float x, float y, float ang)
{
	float dist;
	float height;

	dist = distance(x, y, game->player->pos_x, game->player->pos_y) * cos(ang);
	height = (BLOCK / (dist * BLOCK)) * (WIN_H / 2);
	return (height);
}

int get_texture_offset(float scale)
{
	int init_point;

	int mid_point; // change name, is not the mid_point
	mid_point = (BLOCK / scale);
	init_point = (BLOCK / 2) - (mid_point / 2);
	return (init_point);
}



