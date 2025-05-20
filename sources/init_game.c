/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grial <grial@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:51:00 by grial             #+#    #+#             */
/*   Updated: 2025/05/20 18:35:52 by grial            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/cub3d.h"

//void	draw_line(t_game *game, float x0, float y0, float x1, float y1,
//			int color);
void	load_img(t_game *game);
void	*hook_img(t_game *game, char c);
int		render(t_game *game);
//void	raycasting(t_game *game);

void	init_game(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		handle_error(game, "Failed to initialize MLX");
	game->mlx_window = mlx_new_window(game->mlx_ptr, WIN_W, WIN_H, "cub3D");
	game->engine->frame->img = mlx_new_image(game->mlx_ptr, WIN_W, WIN_H);
	game->engine->frame->addr = mlx_get_data_addr(game->engine->frame->img,
			&game->engine->frame->bpp, &game->engine->frame->line_length,
			&game->engine->frame->endian);
	if (!game->engine->frame->img || !game->engine->frame->addr)
		handle_error(game, "Failed to create or retrieve image data");
	load_img(game);
	mlx_hook(game->mlx_window, 17, 0, free_game, game);
	mlx_hook(game->mlx_window, 2, 1L << 0, key_press, game);
	mlx_hook(game->mlx_window, 3, 1L << 1, key_release, game);
	// mlx_hook(game->mlx_window, 6, PointerMotionMask, mouse_move, game);
	printf("rendering\n");
	mlx_loop_hook(game->mlx_ptr, render, game);
	mlx_loop(game->mlx_ptr);
}

void	clear_image(t_game *game, int color)
{
	int x, y;
	y = 0;
	while (y < WIN_H)
	{
		x = 0;
		while (x < WIN_W)
		{
			my_mlx_pixel_put(game, x, y, color);
			x++;
		}
		y++;
	}
}

void	draw_minimap(t_game *game)
{
	int	color;

	int i, j;
	for (i = 0; i < game->map->m_height; i++)
	{
		for (j = 0; j < (int)ft_strlen(game->map->data[i]); j++)
		{
			if (game->map->data[i][j] == '1')
				color = 0xAAAAAA; // gris para muros
			else if (game->map->data[i][j] == '0')
				color = 0x222222; // gris oscuro para espacio vacío
			else
				color = 0x000000;
			// negro para cualquier otro (puede ser ajustado)
			// dibujar bloque de MIN_S x MIN_S píxeles
			for (int y = 0; y < MIN_S; y++)
			{
				for (int x = 0; x < MIN_S; x++)
				{
					my_mlx_pixel_put(game, j * MIN_S + x, i * MIN_S + y, color);
				}
			}
		}
	}
}

void	draw_miniplayer(t_game *game)
{
	int	center_x;
	int	center_y;

	center_x = (int)(game->player->pos_x * MIN_S);
	center_y = (int)(game->player->pos_y * MIN_S);
	int color = 0xFF0000; // Rojo para el jugador
	int size = 8;         // Tamaño del jugador (8x8 píxeles)
	// Dibujamos un cuadrado de 8x8 alrededor de la posición del jugador
	for (int y = center_y - size / 2; y < center_y + size / 2; y++)
	{
		for (int x = center_x - size / 2; x < center_x + size / 2; x++)
		{
			my_mlx_pixel_put(game, x, y, color);
		}
	}
}

int	render(t_game *game)
{
	render_background(game);
	handle_movement(game);
	usleep(10000);
	mlx_clear_window(game->mlx_ptr, game->mlx_window);
	draw_minimap(game);
	draw_miniplayer(game);
	raycasting(game, game->engine->ray);
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_window, game->mini->player,
		game->player->pos_y * MIN_S, game->player->pos_x * MIN_S);
	// draw_fov(game, game->player);
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_window,
		game->engine->frame->img, 0, 0);
	return (1);
}

void	*hook_img(t_game *game, char c)
{
	if (c == '1')
		return (game->mini->wall);
	else
		return (game->mini->floor);
	return (NULL);
}

void	load_img(t_game *game)
{
	int	img_width;
	int	img_height;

	// game->mini = malloc(sizeof(t_mini));
	//		###     MINIMAP     ###
	if (!game->mini)
	{
		ft_putstr_fd("Error: game->mini not initialized\n", 2);
		exit(EXIT_FAILURE);
	}
	game->mini->wall = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/mini_map/wall.xpm", &img_width, &img_height);
	if (!game->mini->wall)
	{
		ft_putstr_fd("Error: Failed to load wall texture\n", 2);
		exit(EXIT_FAILURE);
	}
	game->mini->floor = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/mini_map/floor.xpm", &img_width, &img_height);
	if (!game->mini->floor)
	{
		ft_putstr_fd("Error: Failed to load floor texture\n", 2);
		exit(EXIT_FAILURE);
	}
	game->mini->player = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/mini_map/player.xpm", &img_width, &img_height);
	if (!game->mini->player)
	{
		ft_putstr_fd("Error: Failed to load player texture\n", 2);
		exit(EXIT_FAILURE);
	}
	//		###     TEXTURE     ###
	game->engine->no_img->img = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/NO.xpm", &img_width, &img_height);
	if (!game->engine->no_img->img)
	{
		ft_putstr_fd("Error: Failed to load player texture\n", 2);
		exit(EXIT_FAILURE);
	}
	game->engine->no_img->addr = mlx_get_data_addr(game->engine->no_img->img,
			&game->engine->no_img->bpp, &game->engine->no_img->line_length,
			&game->engine->no_img->endian);
	game->engine->ea_img->img = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/EA.xpm", &img_width, &img_height);
	if (!game->engine->ea_img)
	{
		ft_putstr_fd("Error: Failed to load player texture\n", 2);
		exit(EXIT_FAILURE);
	}
	game->engine->ea_img->addr = mlx_get_data_addr(game->engine->ea_img->img,
			&game->engine->ea_img->bpp, &game->engine->ea_img->line_length,
			&game->engine->ea_img->endian);
	game->engine->so_img->img = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/SO.xpm", &img_width, &img_height);
	if (!game->engine->so_img)
	{
		ft_putstr_fd("Error: Failed to load player texture\n", 2);
		exit(EXIT_FAILURE);
	}
	game->engine->so_img->addr = mlx_get_data_addr(game->engine->so_img->img,
			&game->engine->so_img->bpp, &game->engine->so_img->line_length,
			&game->engine->so_img->endian);
	game->engine->we_img->img = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/WE.xpm", &img_width, &img_height);
	if (!game->engine->we_img)
	{
		ft_putstr_fd("Error: Failed to load player texture\n", 2);
		exit(EXIT_FAILURE);
	}
	game->engine->we_img->addr = mlx_get_data_addr(game->engine->we_img->img,
			&game->engine->we_img->bpp, &game->engine->we_img->line_length,
			&game->engine->we_img->endian);
}

int	mouse_move(int x, int y, t_game *game)
{
	static int	last_x = -1;
	int			delta_x;

	(void)y;
	if (last_x == -1)
	{
		last_x = x;
		return (0);
	}
	delta_x = x - last_x;
	if (delta_x != 0)
	{
		game->player->dir -= delta_x * 0.5;
		if (game->player->dir < 0)
			game->player->dir += 360;
		if (game->player->dir >= 360)
			game->player->dir -= 360;
		last_x = x;
	}
	return (0);
}


//void	raycasting(t_game *game)
//{
//	int	i;
//	int	color;
//	int	start_x;
//	int	start_y;
//
//	double dx, dy;
//	start_x = (int)(game->player->pos_x * BLOCK);
//	start_y = (int)(game->player->pos_y * BLOCK);
//	i = 0;
//	while (i < 50) // hasta chocar con pared (solo para debug visual)
//	{
//		dx = cos(to_rad(game->player->dir)) * i;
//		dy = -sin(to_rad(game->player->dir)) * i;
//		color = 0xFF0F0F;
//		my_mlx_pixel_put(game, start_x + (int)dx, start_y + (int)dy, color);
//		i += 1;
//	}
//	check_wall(game);
//}

//void	check_wall(t_game *game)
//{
//	double	aTan;
//	int		dof;
//	int		max_dof;
//	t_map	*map;
//	double	dist_v = 0.0;
//	double	dist_h = 0.0;
//
//	float	rx = 0.0; 
//	float	ry = 0.0;
//	float xo, yo = 0.0;
//	int mx, my = 0;
//	dof = 0;
//	max_dof = 50;
//	map = game->map;
//	aTan = 1.0 / tan(to_rad(game->player->dir));
//	
//	// HORIZONTAL
//	if (game->player->dir > 180.0)
//	{
//		ry = floor(game->player->pos_y) + 1;
//		rx = (game->player->pos_y - ry) * aTan + game->player->pos_x;
//		yo = 1;
//		xo = -yo * aTan;
//	}
//	else if (game->player->dir < 180.0)
//	{
//		ry = floor(game->player->pos_y) + 0.0001;
//		rx = (game->player->pos_y - ry) * aTan + game->player->pos_x;
//		yo = -1;
//		xo = -yo * aTan;
//	}
//	else if (game->player->dir == 0 || game->player->dir == 180)
//		return ;
//	while (dof < max_dof)
//	{
//		mx = (int)(rx);
//		my = (int)(ry);
//		if (my >= 0 && my < map->m_height && mx >= 0
//			&& mx < (int)ft_strlen(map->data[my]) && map->data[my][mx] == '1')
//		{
//			dist_h = sqrt((rx - game->player->pos_x) * (rx - game->player->pos_x)
//				+ (ry - game->player->pos_y) * (ry - game->player->pos_y));
//			//draw_line(game, game->player->pos_x * BLOCK, game->player->pos_y
//			//	* BLOCK, rx * BLOCK, ry * BLOCK, 0x00FF00);
//			break ;
//		}
//		else
//		{
//			rx += xo;
//			ry += yo;
//			dof++;
//		}
//	}
//	
//	// VERTICAL
//	dof = 0;
//	aTan = tan(to_rad(game->player->dir));
//	if (game->player->dir < 90 || game->player->dir > 270)
//	{
//		rx = ((int)game->player->pos_x) + 1;
//		ry = (game->player->pos_x - rx) * aTan + game->player->pos_y;
//		xo = 1;
//		yo = -xo * aTan;
//	}
//	else if (game->player->dir > 90 && game->player->dir < 270)
//	{
//		printf("hola2\n");
//		rx = ((int)game->player->pos_x) - 1;
//		ry = (game->player->pos_x - rx) * aTan + game->player->pos_y;
//		xo = -1;
//		yo = -xo * aTan;
//	}
//	while (dof < max_dof)
//	{
//		mx = (int)(rx);
//		my = (int)(ry);
//		if (my >= 0 && my < map->m_height && mx >= 0
//			&& mx < (int)ft_strlen(map->data[my]) && map->data[my][mx] == '1')
//		{
//			printf("hit : %i : %i\n", my, mx);
//			dist_v = sqrt((rx - game->player->pos_x) * (rx - game->player->pos_x)
//				+ (ry - game->player->pos_y) * (ry - game->player->pos_y));
//			printf("dv: %f\n", dist_v);
//			//draw_line(game, game->player->pos_x * BLOCK, game->player->pos_y
//			//	* BLOCK, rx * BLOCK, ry * BLOCK, 0x00FF00);
//			break ;
//		}
//		else
//		{
//			rx += xo;
//			ry += yo;
//			dof++;
//		}
//	}
//}

//void	draw_line(t_game *game, float x0, float y0, float x1, float y1,
//		int color)
//{
//	float	dx;
//	float	dy;
//	float	steps;
//	int		i;
//
//	dx = x1 - x0;
//	dy = y1 - y0;
//	float x_inc, y_inc;
//	steps = fmaxf(fabsf(dx), fabsf(dy));
//	if (steps == 0)
//		return ;
//	x_inc = dx / steps;
//	y_inc = dy / steps;
//	for (i = 0; i < steps; i++)
//	{
//		my_mlx_pixel_put(game, (int)x0, (int)y0, color);
//		x0 += x_inc;
//		y0 += y_inc;
//	}
//}
//