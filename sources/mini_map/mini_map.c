/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grial <grial@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 12:04:16 by grial             #+#    #+#             */
/*   Updated: 2025/06/04 14:43:31 by grial            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static int	get_minimap_color(char tile)
{
	if (tile == '1')
		return (0xAAAAAA);
	if (tile == '0')
		return (0x222222);
	return (0x000000);
}

static void	draw_minimap_tile(t_game *game, int i, int j, int color)
{
	int	x;
	int	y;

	y = 0;
	while (y < MIN_S)
	{
		x = 0;
		while (x < MIN_S)
		{
			my_mlx_pixel_put(game, j * MIN_S + x, i * MIN_S + y, color);
			x++;
		}
		y++;
	}
}

void	draw_minimap(t_game *game)
{
	int	i;
	int	j;
	int	color;

	i = 0;
	while (i < game->map->m_height)
	{
		j = 0;
		while (j < (int)ft_strlen(game->map->data[i]))
		{
			color = get_minimap_color(game->map->data[i][j]);
			draw_minimap_tile(game, i, j, color);
			j++;
		}
		i++;
	}
}


void	draw_miniplayer(t_game *game)
{
	int	center_x;
	int	center_y;
	int	i;
	int	j;

	center_x = (int)(game->player->pos_x * MIN_S);
	center_y = (int)(game->player->pos_y * MIN_S);

	i = center_y - PLY_S / 2;
	while (i < center_y + PLY_S / 2)
	{
		j = center_x - PLY_S / 2;
		while (j < center_x + PLY_S / 2)
		{
			my_mlx_pixel_put(game, j, i, PLY_C);
			j++;
		}
		i++;
	}
}
