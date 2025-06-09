/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grial <grial@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 12:04:16 by grial             #+#    #+#             */
/*   Updated: 2025/06/09 16:39:44 by grial            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	delete_previous_img(t_game *game, t_engine *engine)
{
	free_img(game->mlx_ptr, &engine->no_img);
	free_img(game->mlx_ptr, &engine->so_img);
	free_img(game->mlx_ptr, &engine->we_img);
	free_img(game->mlx_ptr, &engine->ea_img);
	free_img(game->mlx_ptr, &engine->dr_img);
	free_img(game->mlx_ptr, &engine->ex_img);
}

static int	alloc_imgs(t_engine *engine)
{
	engine->no_img = malloc(sizeof(t_img));
	engine->so_img = malloc(sizeof(t_img));
	engine->we_img = malloc(sizeof(t_img));
	engine->ea_img = malloc(sizeof(t_img));
	engine->dr_img = malloc(sizeof(t_img));
	engine->ex_img = malloc(sizeof(t_img));
	if (!engine->no_img || !engine->so_img || !engine->we_img || !engine->ea_img
		|| !engine->dr_img)
		return (0);
	engine->no_img->img = NULL;
	engine->so_img->img = NULL;
	engine->we_img->img = NULL;
	engine->ea_img->img = NULL;
	engine->dr_img->img = NULL;
	engine->ex_img->img = NULL;
	return (1);
}

void	animation(t_game *game, t_engine *engine)
{
	if (engine->rcast->fps == 40)
	{
		delete_previous_img(game, engine);
		if (!alloc_imgs(engine))
			return ;
		load_img_and_check(game->mlx_ptr, engine->no_img, "textures/NO.xpm",
			game);
		load_img_and_check(game->mlx_ptr, engine->ea_img, "textures/EA.xpm",
			game);
		load_img_and_check(game->mlx_ptr, engine->so_img, "textures/SO.xpm",
			game);
		load_img_and_check(game->mlx_ptr, engine->we_img, "textures/WE.xpm",
			game);
		load_img_and_check(game->mlx_ptr, engine->ex_img, "textures/EX.xpm",
			game);
		engine->rcast->fps = 0;
	}
	else if (engine->rcast->fps == 20)
	{
		delete_previous_img(game, engine);
		if (!alloc_imgs(engine))
			return ;
		load_img_and_check(game->mlx_ptr, engine->no_img, "textures/EA.xpm",
			game);
		load_img_and_check(game->mlx_ptr, engine->ea_img, "textures/WE.xpm",
			game);
		load_img_and_check(game->mlx_ptr, engine->so_img, "textures/NO.xpm",
			game);
		load_img_and_check(game->mlx_ptr, engine->we_img, "textures/SO.xpm",
			game);
		load_img_and_check(game->mlx_ptr, engine->ex_img, "textures/EX1.xpm",
			game);
	}
}
