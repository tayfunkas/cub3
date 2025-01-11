/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grial <grial@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 10:22:08 by tkasapog          #+#    #+#             */
/*   Updated: 2025/01/10 19:22:08 by grial            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3_H
# define CUB3_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "get_next_line.h"
# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include "cub3_keys.h"

# define WIN_W 1280
# define WIN_H 720
# define MIN_S 8

typedef struct s_mini
{
	void	*wall;
	void	*door;
	void	*floor;
	void	*player;
	
} t_mini;

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

//checks.c
void	check_empty_map(t_game *game, int fd);
void	check_mapfile_name(t_game *game, char *map);
void	check_mapchars(char *line, t_game *game);
void	check_player(char **map, char *line, t_game *game);
//parse_map.c
void	parse_file(t_game *game);
void	classify_line(t_game *game, char *line);
void	parse_map(t_game *game, char *line);
char	**append_line_to_map(char **map, char *line, t_game *game);
//free.c
int		free_game(t_game *game);
void	handle_error(t_game *game, const char *error_message);
//initialize.c
void	initialize_game(t_game **game);
void	initialize_player(t_game *game);
//validate_map.c
void	pad_map_to_rectangle(t_game *game);
void	validate_map(t_game *game);
int		validate_borders(t_map *map);
//check_textures.c
int		has_xpm_extension(const char *filename);
void	check_texture(const char *path, const char *message, t_game *game);
void	check_images(t_game *game);
void	parse_texture(t_game *game, char *line, char **texture_path);
//check_colors.c
void	parse_color(t_game *game, char *line, t_color *color);
int		ft_alldigit(char *str);
void	ft_free_split(char **array);
//parsing_utils.c
char	*ft_strtrim_spaces(char *line);
int		ft_arraylen(char **array);
int		ft_is_all_spaces(char *line);
//init_game.c
int		key_hook(int key, t_game *game);
void	init_game(t_game *game);
//direcction_player.c
void	direcction_player(int key, t_game *game);
void	move_player(int key, t_game *game);

#endif
