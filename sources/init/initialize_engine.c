/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_engine.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grial <grial@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 09:33:51 by tkasapog          #+#    #+#             */
/*   Updated: 2025/06/04 17:15:39 by grial            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	initialize_engine(t_game *game)
{
	game->engine = malloc(sizeof(t_engine));
	if (!game->engine)
		return ;
	game->engine->ray = NULL;
	game->engine->rcast = NULL;
	initialize_img(game->engine);
	game->engine->frame = malloc(sizeof(t_img));
	game->engine->floor_color = malloc(sizeof(t_color));
	if (!game->engine->floor_color)
		return ;
	game->engine->floor_color->r = -1;
	game->engine->floor_color->g = -1;
	game->engine->floor_color->b = -1;
	game->engine->ceiling_color = malloc(sizeof(t_color));
	if (!game->engine->ceiling_color)
		return ;
	game->engine->ceiling_color->r = -1;
	game->engine->ceiling_color->g = -1;
	game->engine->ceiling_color->b = -1;
		game->engine->no_path = NULL;
	game->engine->so_path = NULL;
	game->engine->we_path = NULL;
	game->engine->ea_path = NULL;
	game->engine->dr_path = NULL;
}

void	initialize_img(t_engine *engine)
{
	engine->no_img = malloc(sizeof(t_img));
	if (!engine->no_img)
		return ;
	engine->no_img->img = NULL;
	engine->so_img = malloc(sizeof(t_img));
	if (!engine->so_img)
		return ;
	engine->so_img->img = NULL;
	engine->we_img = malloc(sizeof(t_img));
	if (!engine->we_img)
		return ;
	engine->we_img->img = NULL;
	engine->ea_img = malloc(sizeof(t_img));
	if (!engine->ea_img)
		return ;
	engine->ea_img->img = NULL;
	engine->dr_img = malloc(sizeof(t_img));
	if (!engine->dr_img)
		return ;
	engine->dr_img->img = NULL;
}
