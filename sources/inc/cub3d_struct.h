/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grial <grial@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 13:29:35 by grial             #+#    #+#             */
/*   Updated: 2025/02/19 17:20:58 by grial            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_STRUCT_H
# define CUB3D_STRUCT_H

typedef struct s_mini
{
	void	*wall;
	void	*door;
	void	*floor;
	void	*player;
}	t_mini;

typedef struct s_map
{
	int		m_height;
	int		m_width;
	char	**data;
	int		line_count;
}	t_map;

typedef struct s_player
{
	int		player_count;
	int		player_dir;
	int		player_x;
	int		player_y;
}	t_player;

typedef struct s_ray
{
	double	ray_angle;
	double	wall_distance;
	int		hit_x;
	int		hit_y;
}	t_ray;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_game
{
	void		*mlx_ptr;
	void		*mlx_window;
	char		*no_texture;
	char		*so_texture;
	char		*we_texture;
	char		*ea_texture;
	char		*map_file;
	t_color		floor_color;
	t_color		ceiling_color;
	t_map		*map;
	t_player	*player;
	t_ray		*rays;
	t_mini		*mini;
}	t_game;

#endif