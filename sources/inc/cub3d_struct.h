/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grial <grial@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 13:29:35 by grial             #+#    #+#             */
/*   Updated: 2025/03/05 13:53:25 by grial            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_STRUCT_H
# define CUB3D_STRUCT_H

typedef struct s_img
{
	char	*img_data;
	void	*img;
	int		width;
	int		height;
	int		bpp;
	int		size_line;
	int		endian;
}	t_img;

typedef struct s_color
{
	int		r;
	int		g;
	int		b;
}	t_color;

typedef struct s_engine
{
	t_img	*frame;
	float	ang_step;
	void	*text[4];
	char	*NO;
	char	*EA;
	char	*SO;
	char	*WE;
	t_color	floor;
	t_color	ceiling;
}	t_engine;

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
	float	player_x;
	float	player_y;
}	t_player;

typedef struct s_game
{
	void		*mlx_ptr;
	void		*mlx_window;
	char		*map_file;
	t_map		*map;
	t_player	*player;
	t_mini		*mini;
	t_engine	*engine;
}	t_game;

#endif