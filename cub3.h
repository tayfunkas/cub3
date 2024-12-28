#ifndef CUB3_H
#define CUB3_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line.h"

typedef struct s_map
{
    int     m_height;
    int     m_width;
    char    **data;
} t_map;

typedef struct s_player
{
    int     player_count;
    char    player_dir;
    int     player_x;
    int     player_y;
}   t_player;

typedef struct s_ray
{
    double  ray_angle;
    double  wall_distance;
    int     hit_x;
    int     hit_y;
}   t_ray;

typedef struct s_color
{
    int r;
    int g;
    int b;
}   t_color;

typedef struct s_game
{
    char    *no_texture;
    char    *so_texture;
    char    *we_texture;
    char    *ea_texture;
    t_color floor_color;
    t_color ceiling_color;
    t_map   *map;
    t_player    *player;
    t_ray   *rays;
}   t_game;

//checks.c
void    check_empty_map(t_game *game, int fd);
void    check_mapfile_name(t_game *game, char *map);
void    parse_file(t_game *game, char *filepath);
void    classify_line(t_game *game, char *line);
void    parse_texture(t_game *game, char *line, char **texture_path);
void    parse_color(t_game *game, char *line, t_color *color);
void    parse_map(t_game *game, char *line);
void    check_mapchars(char *line, t_game *game);
void    check_player(char **map, char *line, t_game *game);
char    **append_line_to_map(char **map, char *line, t_game *game);
int ft_arraylen(char **array);
//free.c
void    free_game(t_game *game);
void    handle_error(t_game *game, const char *error_message);
//initialize.c
void    initialize_game(t_game **game);
void    initialize_player(t_game **game);
//libft.c
int	ft_strncmp(const char *s1, const char *s2, size_t n);
int	ft_isdigit(int c);
char	*ft_strdup(char *src);
char	**ft_split(const char *str, char c);
int	ft_atoi(const char *str);
size_t	ft_strlen(const char *s);




#endif