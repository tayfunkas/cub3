/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grial <grial@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 12:04:16 by grial             #+#    #+#             */
/*   Updated: 2025/06/11 11:35:10 by grial            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	delete_previous_img(t_game *game, t_engine *engine)
{
	free_img(game->mlx_ptr, &engine->no_img);
	free_img(game->mlx_ptr, &engine->so_img);
	free_img(game->mlx_ptr, &engine->we_img);
	free_img(game->mlx_ptr, &engine->ea_img);
	free_img(game->mlx_ptr, &engine->ex_img);
}

static int	alloc_imgs(t_engine *engine)
{
	engine->no_img = malloc(sizeof(t_img));
	engine->so_img = malloc(sizeof(t_img));
	engine->we_img = malloc(sizeof(t_img));
	engine->ea_img = malloc(sizeof(t_img));
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

void	animation(t_game *game, t_engine *en)
{
	if (en->rcast->fps == 40 && en->animation)
	{
		delete_previous_img(game, en);
		if (!alloc_imgs(en))
			return ;
		load_img_and_check(game->mlx_ptr, en->no_img, "textures/NO.xpm", game);
		load_img_and_check(game->mlx_ptr, en->ea_img, "textures/EA.xpm", game);
		load_img_and_check(game->mlx_ptr, en->so_img, "textures/SO.xpm", game);
		load_img_and_check(game->mlx_ptr, en->we_img, "textures/WE.xpm", game);
		load_img_and_check(game->mlx_ptr, en->ex_img, "textures/EX.xpm", game);
		en->rcast->fps = 0;
	}
	else if (en->rcast->fps == 20 && en->animation)
	{
		delete_previous_img(game, en);
		if (!alloc_imgs(en))
			return ;
		load_img_and_check(game->mlx_ptr, en->no_img, "textures/EA.xpm", game);
		load_img_and_check(game->mlx_ptr, en->ea_img, "textures/WE.xpm", game);
		load_img_and_check(game->mlx_ptr, en->so_img, "textures/NO.xpm", game);
		load_img_and_check(game->mlx_ptr, en->we_img, "textures/SO.xpm", game);
		load_img_and_check(game->mlx_ptr, en->ex_img, "textures/EX1.xpm", game);
	}
}
