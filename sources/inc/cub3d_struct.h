/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grial <grial@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 13:29:35 by grial             #+#    #+#             */
/*   Updated: 2025/04/10 16:42:57 by grial            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_STRUCT_H
# define CUB3D_STRUCT_H

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
	int	color;
}	t_color;

typedef struct s_cam
{
	float	x;
	float	ray_x;
	float	ray_y;
	
}	t_cam;

typedef struct s_img
{
	void		*img;
	void		*img_addr;
	char		*addr;
	int			bpp;
	int			line_length;
	int			endian;	
}	t_img;

typedef struct s_engine 
{
	t_img	*frame;
	t_cam	*cam;
	float	fov;
	float	ang_step;
	t_img	*no_img;
	t_img	*so_img;
	t_img	*we_img;
	t_img	*ea_img;
	char	*no_texture;
	char	*so_texture;
	char	*we_texture;
	char	*ea_texture;
	t_color	*floor_color;
	t_color	*ceiling_color;
}	t_engine;

typedef struct s_mini
{
	void	*wall;
	void	*floor;
	void	*door;
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
	int		dir;
	float	pos_x;
	float	pos_y;
}	t_player;

typedef struct s_ray
{
	double	ray_angle;
	double	wall_distance;
	int		hit_x;
	int		hit_y;
}	t_ray;

typedef struct s_config
{
	int	no;
	int	so;
	int	we;
	int	ea;
	int	f;
	int	c;
}	t_config;

typedef struct s_game
{
	void		*mlx_ptr;
	void		*mlx_window;
	char		*map_file;
	int			*keys;
	t_config	*config;
	t_engine	*engine;
	t_map		*map;
	t_player	*player;
	t_ray		*rays;
	t_mini		*mini;
}	t_game;

#endif