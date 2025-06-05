/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasapog <tkasapog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 17:53:10 by grial             #+#    #+#             */
/*   Updated: 2025/06/05 13:22:18 by tkasapog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	render(t_game *game)
{
	mlx_clear_window(game->mlx_ptr, game->mlx_window);
	usleep(10000);
	render_background(game);
	handle_movement(game);
	raycasting(game, game->engine->ray, game->engine->rcast);
	draw_minimap(game);
	draw_miniplayer(game);
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_window, game->mini->player,
		game->player->pos_y * MIN_S, game->player->pos_x * MIN_S);
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_window,
		game->engine->frame->img, 0, 0);
	return (1);
}

void	render_wall_column(t_game *game, t_ray *ray, t_rend *rcast, int win_x)
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
		rcast->color = get_pixel_color(rcast->texture, rcast->offset_x, tex_y);
		my_mlx_pixel_put(game, win_x, y, rcast->color);
		pos_y += rcast->step_texture;
		y++;
	}
}

void	get_tex(t_game *game, t_ray *ray)
{
	if (game->map->data[ray->hit_y][ray->hit_x] == 'D')
	{
		game->engine->rcast->texture = game->engine->dr_img;
		return ;
	}
	if (!ray->r_side)
	{
		if (ray->r_dir >= 90 && ray->r_dir <= 270)
			game->engine->rcast->texture = game->engine->so_img;
		else
			game->engine->rcast->texture = game->engine->no_img;
	}
	else
	{
		if (ray->r_dir >= 180 && ray->r_dir <= 360)
			game->engine->rcast->texture = game->engine->we_img;
		else
			game->engine->rcast->texture = game->engine->ea_img;
	}
}

int	get_texture_offset_x(t_game *game, t_ray *ray)
{
	double	wall_hit;
	int		offset_x;

	if (ray->r_side == 0)
		wall_hit = game->player->pos_y + ray->dis_f * -sin(to_rad(ray->r_dir));
	else
		wall_hit = game->player->pos_x + ray->dis_f * cos(to_rad(ray->r_dir));
	wall_hit -= floor(wall_hit);
	offset_x = (int)(wall_hit * (double)BLOCK);
	return (offset_x);
}
