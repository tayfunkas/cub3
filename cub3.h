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
} t_map;

typedef struct s_player
{
    int     player_count;
    char    player_dir;
    int     player_x;
    int     player_y;
}   t_player;

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
}   t_game;

typedef struct s_color
{
    int r;
    int g;
    int b;
}   t_color;




#endif