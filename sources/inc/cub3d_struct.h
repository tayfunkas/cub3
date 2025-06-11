/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grial <grial@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 13:29:35 by grial             #+#    #+#             */
/*   Updated: 2025/06/11 11:12:39 by grial            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_STRUCT_H
# define CUB3D_STRUCT_H

typedef struct s_color
{
	int				r;
	int				g;
	int				b;
	int				color;
}					t_color;

typedef struct s_ray
{
	int				r_side;
	double			r_dir;
	double			r_step;
	double			ray_vx;
	double			ray_vy;
	double			ray_hx;
	double			ray_hy;
	int				hit_x;
	int				hit_y;
	double			ray_t;
	double			del_x;
	double			del_y;
	double			dis_h;
	double			dis_v;
	double			dis_f;
	double			drw_x0;
	double			drw_y0;
}					t_ray;

typedef struct s_img
{
	void			*img;
	void			*img_addr;
	char			*addr;
	int				bpp;
	int				line_length;
	int				endian;
}					t_img;

typedef struct s_rend
{
	int				fps;
	int				close;
	int				draw_start;
	int				draw_end;
	double			height;
	double			tex_pos;
	double			step_texture;
	int				offset_x;
	int				offset_y;
	unsigned int	color;
	t_img			*texture;
}					t_rend;

typedef struct s_engine
{
	t_ray			*ray;
	t_rend			*rcast;
	t_img			*frame;
	t_img			*no_img;
	t_img			*so_img;
	t_img			*we_img;
	t_img			*ea_img;
	t_img			*ex_img;
	t_img			*dr_img;
	char			*no_path;
	char			*so_path;
	char			*we_path;
	char			*ea_path;
	char			*dr_path;
	t_color			*floor_color;
	t_color			*ceiling_color;
	int				animation;
}					t_engine;

typedef struct s_mini
{
	void			*mini_wall;
	void			*mini_floor;
	void			*mini_door;
	void			*player;
}					t_mini;

typedef struct s_map
{
	char			**data;
	int				m_height;
	int				m_width;
	int				vision;
	int				line_count;
	int				max_size;
	int				exit;
	int				pos_x;
	int				pos_y;
}					t_map;

typedef struct s_player
{
	int				player_count;
	int				dir;
	double			pos_x;
	double			pos_y;
	double			prev_dist;
	double			new_dist;
}					t_player;

typedef struct s_config
{
	int				no;
	int				so;
	int				we;
	int				ea;
	int				f;
	int				c;
}					t_config;

typedef struct s_game
{
	void			*mlx_ptr;
	void			*mlx_window;
	char			*map_file;
	int				*keys;
	int				error;
	t_config		*config;
	t_engine		*engine;
	t_map			*map;
	t_player		*player;
	t_mini			*mini;
}					t_game;

#endif