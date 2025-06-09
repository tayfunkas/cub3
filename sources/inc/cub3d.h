/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grial <grial@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 10:22:08 by tkasapog          #+#    #+#             */
/*   Updated: 2025/06/09 17:59:29 by grial            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include "cub3d_config.h"
# include "cub3d_keys.h"
# include "cub3d_struct.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define M_PI 3.14159265358979323846
// map_parsing

//	animination.c
void	animation(t_game *game, t_engine *eng);
// assign_line.c
void	check_line_config(t_game *game, char *line);
void	classify_line(t_game *game, char *line);

// check_colors.c
void	parse_color(t_game *game, char *line, t_color *color);
int		ft_alldigit(char *str);
void	ft_free_split(char **array);

// check_textures.c
int		has_xpm_extension(const char *filename);
void	check_texture(const char *path, const char *message, t_game *game);
void	check_images(t_game *game);
void	parse_texture(t_game *game, char *line, char **texture_path);
void	check_duplicates_or_missing(t_game *game);

//	checks.c
void	check_empty_map(t_game *game, int fd);
void	check_mapfile_name(t_game *game, char *map);
bool	check_mapchars(char *line, t_game *game);
void	check_player_position(t_game *game);
bool	check_player(char **map, char *line, t_game *game);

// parse_map.c
void	parse_file(t_game *game);
void	parse_map(t_game *game, char *line);
char	**append_line_to_map(char **map, char *line, t_game *game);

// parsing_utils.c
char	*ft_strtrim_spaces(char *line);
int		ft_arraylen(char **array);
int		ft_is_all_spaces(char *line);
void	count_commas(t_game *game, const char *line);

// validate_map.c
void	pad_map_to_rectangle(t_game *game);
void	validate_map(t_game *game);
void	check_map_tile(t_game *game, char **map, int x, int y);
int		validate_borders(t_map *map);

// move
// keys.c
int		key_press(int key, t_game *game);
int		key_release(int key, t_game *game);

// player_move.c
void	handle_movement(t_game *game);
void	player_direction(t_player *player, int key);
void	player_move(t_player *player, t_map *map, int key);
void	player_strafe(t_player *player, t_map *map, int key);
int		check_collision(t_map *map, float x, float y);

// ray_casting
void	draw_minimap(t_game *game);
// rc_fov.c
void	draw_ray_line(t_game *game, t_player *player, int x_width, float x);
float	distance(float x1, float y1, float x2, float y2);
void	my_mlx_pixel_put(t_game *game, int x, int y, int color);

void	open_door(t_player *player, t_map *map);
// render_background.c
void	render_background(t_game *game);

//	check_wall.c
void	wall_dist(t_game *game, t_map *map, t_ray *ray);
void	dist_to_wall(t_ray *ray);

//	check_wall_utils.c
int		is_wall(t_map *map, int int_y, int int_x);
void	vertical_values(t_game *game, t_ray *ray);
void	horizontal_values(t_game *game, t_ray *ray);
void	ray_dist_horizontal(t_game *game, t_map *map, t_ray *ray);
void	ray_dist_vertical(t_game *game, t_map *map, t_ray *ray);

//	mini_map.c
void	draw_miniplayer(t_game *game);
void	draw_map(t_game *game);
void	get_exit(t_map *map);

//	raycasting.c
void	raycasting(t_game *game, t_ray *ray, t_rend *rcast);

//	raycasting_utils.c
double	to_rad(double ang);
void	fix_ang(t_ray *ray, double player_dir, double i);
void	fix_fisheye(t_game *game, t_ray *ray);
void	set_wall_draw_limits(t_ray *ray, t_rend *rcast);
int		get_offset_y(int tex_y);

//	get_pixel_color.c
int		get_pixel_color(t_img *texture, int x, int y);

// free_engine.c
void	free_engine(t_engine *engine, void *mlx_ptr);
void	free_img(void *mlx_ptr, t_img **img);
void	free_texture_path(t_engine *engine);
void	free_engine_texture(t_engine *engine);
void	free_color(t_color **color);

//	draw_wall.c
void	render_wall_column(t_game *game, t_ray *ray, t_rend *rcast, int win_x);
void	get_tex(t_game *game, t_ray *ray);
int		get_texture_offset_x(t_game *game, t_ray *ray);

//	free.c
int		free_game(t_game *game);
void	free_mini(t_mini *mini, void *mlx_ptr);
void	free_map(t_map *map);
void	handle_error(t_game *game, const char *error_message);

//	init_game.c
int		key_hook(int key, t_game *game);
void	init_game(t_game *game);
int		mouse_move(int x, int y, t_game *game);
int		render(t_game *game);

//	initialize.c
void	initialize_game(t_game **game);
void	initialize_img(t_engine *engine);
void	initialize_mini(t_game *game);
void	initialize_config(t_game *game);
void	initialize_render(t_game *game);
void	initialize_ray(t_game *game);

//	initialize_engine.c
void	initialize_engine(t_game *game);
void	initialize_img(t_engine *engine);

//	initialize_player.c
void	initialize_player(t_game *game);
void	get_player_init_position(t_map *map, t_player *player);
int		is_player(char c);
int		player_dir(char c);
void	player_exit(t_game *game, t_player *player, t_map *map);

//  load_image.c
void	load_img(t_game *game);
void	load_img_and_check(void *mlx, t_img *img, char *path, t_game *game);

//  render_exit.c
void	render_exit(t_game *game, t_ray *ray, t_rend *rcast);
void	render_exit_column(t_game *game, t_ray *ray, t_rend *rcast, int win_x);
void	exit_dist(t_game *game, t_map *map, t_ray *ray);
void	dist_to_exit(t_ray *ray);

//  check_exit_utils.c
int		is_exit(t_map *map, int int_y, int int_x);
void	exit_dist_vertical(t_game *game, t_map *map, t_ray *ray);
void	exit_dist_horizontal(t_game *game, t_map *map, t_ray *ray);

#endif
