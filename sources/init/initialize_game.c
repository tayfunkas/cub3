/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_game.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grial <grial@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 09:33:51 by tkasapog          #+#    #+#             */
/*   Updated: 2025/06/05 16:19:25 by grial            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	initialize_game(t_game **game)
{
	*game = malloc(sizeof(t_game));
	if (!*game)
		handle_error(*game, "Memory allocation failied for game structure.");
	ft_bzero(*game, sizeof(t_game));
	(*game)->mlx_ptr = NULL;
	(*game)->mlx_window = NULL;
	(*game)->map_file = NULL;
	(*game)->keys = ft_calloc(MAX_KEYCODE, sizeof(int));
	if (!(*game)->keys)
		handle_error(*game, "Memory allocation failed for keys array.");
	(*game)->map = malloc(sizeof(t_map));
	if (!(*game)->map)
		handle_error(*game, "Memory allocation failed for map structure.");
	(*game)->map->m_height = 0;
	(*game)->map->m_width = 0;
	(*game)->map->data = NULL;
	(*game)->map->line_count = 0;
	initialize_player(*game);
	initialize_engine(*game);
	initialize_config(*game);
	initialize_mini(*game);
	initialize_ray(*game);
	initialize_render(*game);
	return ;
}

void	initialize_render(t_game *game)
{
	game->engine->rcast = malloc(sizeof(t_rend));
	if (!game->engine->rcast)
	{
		printf("Error initialize_render()");
		return ;
	}
	printf("Fix case where initialize_render does not work");
	game->engine->rcast->fps = 5000;
	game->engine->rcast->draw_start = 0;
	game->engine->rcast->draw_end = 0;
	game->engine->rcast->height = 0;
	game->engine->rcast->tex_pos = 0;
	game->engine->rcast->step_texture = 0;
	game->engine->rcast->offset_x = 0;
	game->engine->rcast->offset_y = 0;
	game->engine->rcast->color = 0;
	game->engine->rcast->texture = NULL;
	return ;
}

void	initialize_ray(t_game *game)
{
	game->engine->ray = malloc(sizeof(t_ray));
	if (!game->engine->ray)
	{
		printf("Error initialize_ray()");
		return ;
	}
	printf("Fix case does not work initialize_ray");
	game->engine->ray->r_step = (double)FOV / (double)WIN_W;
	game->engine->ray->r_side = 0;
	game->engine->ray->hit_x = 0;
	game->engine->ray->hit_y = 0;
	game->engine->ray->r_dir = 0.0;
	game->engine->ray->ray_vx = 0.0;
	game->engine->ray->ray_vy = 0.0;
	game->engine->ray->ray_hx = 0.0;
	game->engine->ray->ray_hy = 0.0;
	game->engine->ray->ray_t = 0.0;
	game->engine->ray->del_x = 0.0;
	game->engine->ray->del_y = 0.0;
	game->engine->ray->dis_h = 0.0;
	game->engine->ray->dis_v = 0.0;
	game->engine->ray->dis_f = 0.0;
	return ;
}

void	initialize_mini(t_game *game)
{
	game->mini = ft_calloc(1, sizeof(t_mini));
	if (!game->mini)
		handle_error(game, "Failed to allocate mini");
	game->mini->mini_wall = NULL;
	game->mini->mini_door = NULL;
	game->mini->mini_floor = NULL;
	game->mini->player = NULL;
}

void	initialize_config(t_game *game)
{
	game->config = malloc(sizeof(t_config));
	if (!game->config)
		handle_error(game, "Memory allocation failed for config structure.");
	game->config->no = 0;
	game->config->so = 0;
	game->config->ea = 0;
	game->config->we = 0;
	game->config->f = 0;
	game->config->c = 0;
}
