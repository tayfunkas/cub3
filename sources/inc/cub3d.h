/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasapog <tkasapog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 10:22:08 by tkasapog          #+#    #+#             */
/*   Updated: 2025/04/28 18:39:32 by tkasapog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <fcntl.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "../libft/get_next_line.h"
# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include "cub3d_keys.h"
# include "cub3d_struct.h"
# include <math.h>

# define M_PI 3.14159265358979323846
# define WIN_W 1280
# define WIN_H 720
# define MIN_S 8
# define BLOCK 64
# define STEP 0.07
# define FOV 90

void	get_player_init_position(t_map *map, t_player *player);
int		is_player(char c);
//map_parsing
//assign_line.c
void	check_line_config(t_game *game, char *line);
void	classify_line(t_game *game, char *line);
//check_colors.c
void	parse_color(t_game *game, char *line, t_color *color);
int		ft_alldigit(char *str);
void	ft_free_split(char **array);
//check_textures.c
int		has_xpm_extension(const char *filename);
void	check_texture(const char *path, const char *message, t_game *game);
void	check_images(t_game *game);
void	parse_texture(t_game *game, char *line, char **texture_path);
void	check_duplicates_or_missing(t_game *game);
//checks.c
void	check_empty_map(t_game *game, int fd);
void	check_mapfile_name(t_game *game, char *map);
bool	check_mapchars(char *line, t_game *game);
bool	check_player(char **map, char *line, t_game *game);
//parse_map.c
void	parse_file(t_game *game);
void	parse_map(t_game *game, char *line);
char	**append_line_to_map(char **map, char *line, t_game *game);
//parsing_utils.c
char	*ft_strtrim_spaces(char *line);
int		ft_arraylen(char **array);
int		ft_is_all_spaces(char *line);
//validate_map.c
void	pad_map_to_rectangle(t_game *game);
void	validate_map(t_game *game);
int		validate_borders(t_map *map);
//move
//keys.c
int		key_press(int key, t_game *game);
int		key_release(int key, t_game *game);
//player_move.c
void	handle_movement(t_game *game);
void	player_direction(t_player *player, int key);
void	player_move(t_player *player, t_map *map, int key);
void	player_strafe(t_player *player, t_map *map, int key);
int		check_collision(t_map *map, float x, float y);
//ray_casting
//rc_fov.c
void	draw_ray_line(t_game *game, t_player *player, int x_width, float x);
void	draw_fov(t_game *game, t_player *player);
void	draw_wall(t_game *game, int x_width, float x, float y, float ang);
int     draw_check_collision(t_game *game, int x_width, float x, float y, float ang);
float	distance(float x1, float y1, float x2, float y2);
void	my_mlx_pixel_put(t_game *game, int x, int y, int color);
//free_engine.c
void	free_engine_images(t_engine *engine, void *mlx_ptr);
void	free_engine_texture(t_engine *engine);
void	handle_error(t_game *game, const char *error_message);
//free.c
int		free_game(t_game *game);
void	free_mini(t_mini *mini, void *mlx_ptr);
void	free_map(t_map *map);
//init_game.c
int		key_hook(int key, t_game *game);
void	init_game(t_game *game);
int     mouse_move(int x, int y, t_game *game);
//initialize.c
void	initialize_game(t_game **game);
void	initialize_player(t_game *game);
void	initialize_engine(t_game *game);
void	initialize_mini(t_game *game);
void	initialize_config(t_game *game);

#endif
