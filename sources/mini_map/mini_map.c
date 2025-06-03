#include "../inc/cub3d.h"

void	draw_line(t_game *game, float x0, float y0, float x1, float y1,
		int color)
{
	float	dx;
	float	dy;
	float	steps;
	int		i;

	dx = x1 - x0;
	dy = y1 - y0;
	float x_inc, y_inc;
	steps = fmaxf(fabsf(dx), fabsf(dy));
	if (steps == 0)
		return ;
	x_inc = dx / steps;
	y_inc = dy / steps;
	for (i = 0; i < steps; i++)
	{
		my_mlx_pixel_put(game, (int)x0, (int)y0, color);
		x0 += x_inc;
		y0 += y_inc;
	}
}

void	draw_ray(t_game *game, t_ray *ray)
{
	double	end_x;
	double	end_y;

	end_x = game->player->pos_x + cos(to_rad(ray->r_dir)) * ray->dis_f;
	end_y = game->player->pos_y - sin(to_rad(ray->r_dir)) * ray->dis_f;
	draw_line(game, 10 * MIN_S, 10
		* MIN_S, end_x * (double)MIN_S, end_y * (double)MIN_S,
		0xFF0F0F);
}

void	draw_minimap(t_game *game)
{
	int		dir_i;
	int		win_x;
	double	ang_d;
	t_ray	*ray;

	ray = game->engine->ray;
	dir_i = game->player->dir + (FOV / 2);
	win_x = 0;
	ang_d = 0.0;
	draw_map(game);
	draw_player(game);
	while (win_x < 20)
	{
		fix_ang(ray, dir_i, -ang_d);
		wall_dist(game, game->map, ray);
		draw_ray(game, ray);
		ang_d += ray->r_step;
		win_x += 1;
	}
}

static void	draw_miniblock(t_game *game, int scr_x, int scr_y, int color)
{
	int	x;
	int	y;

	y = 0;
	while (y < MIN_S)
	{
		x = 0;
		while (x < MIN_S)
		{
			my_mlx_pixel_put(game, scr_x + x, scr_y + y, color);
			x++;
		}
		y++;
	}
}

void	draw_map(t_game *game)
{
	double	start_x;
	double	start_y;
	int		map_x;
	int		map_y;
	int		color;
	int		i;
	int		j;

	i = 0;
	start_x = game->player->pos_x - 10.0;
	start_y = game->player->pos_y - 10.0;
	while (i < 80)
	{
		j = 0;
		while (j < 80)
		{
			map_y = (int)(start_y + i);
			map_x = (int)(start_x + j);
			color = get_cell_color(game, map_y, map_x);
			scr_x = j * MIN_S - (int)((start_x - (int)start_x) * MIN_S);
			scr_y = i * MIN_S - (int)((start_y - (int)start_y) * MIN_S);
			draw_miniblock(game, scr_x, scr_y, color);
			j++;
		}
		i++;
	}
}

static int	get_cell_color(t_game *game, int map_y, int map_x)
{
	if (map_y >= 0 && map_y < game->map->m_height &&
		map_x >= 0 && map_x < (int)ft_strlen(game->map->data[map_y]))
	{
		if (game->map->data[map_y][map_x] == '1')
			return (0xAAAAAA);
		else if (game->map->data[map_y][map_x] == '0')
			return (0x222222);
	}
	return (0x000000);
}


void	draw_player(t_game *game)
{
	int	center_x = 10 * MIN_S + (MIN_S / 2);
	int	center_y = 10 * MIN_S + (MIN_S / 2);
	int	color = 0xFF0000;
	int	size = 2;

	for (int y = center_y - size / 2; y < center_y + size / 2; y++)
	{
		for (int x = center_x - size / 2; x < center_x + size / 2; x++)
		{
			my_mlx_pixel_put(game, x, y, color);
		}
	}
}
