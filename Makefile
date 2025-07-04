NAME = cub3D

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -rf

# Detectar sistema operativo
UNAME_S := $(shell uname -s)

# Configuración por defecto (Linux)
LBMLX_PATH = minilibx-linux
LBMLX_LIB = $(LBMLX_PATH)/libmlx.a
INC_MLX = -L$(LBMLX_PATH) -lmlx -lXext -lX11 -lm -lz

# Libft
LIBFT_PATH = ./libft
LIBFT_LIB = $(LIBFT_PATH)/libft.a
INC_LIB = -L$(LIBFT_PATH) -lft

# Fuentes y objetos
SOURCES = 	sources/animations/animation.c \
			sources/free/free.c \
			sources/free/free_engine.c \
			sources/init/initialize_engine.c \
			sources/init/initialize_game.c \
			sources/init/initialize_player.c \
			sources/init_game.c \
			sources/load_image.c \
			sources/main.c \
			sources/map_parsing/assign_line.c \
			sources/map_parsing/check_colors.c \
			sources/map_parsing/check_textures.c \
			sources/map_parsing/checks.c \
			sources/map_parsing/get_exit.c \
			sources/map_parsing/parse_map.c \
			sources/map_parsing/parsing_utils.c \
			sources/map_parsing/validate_map.c \
			sources/mini_map/draw_minimap.c \
			sources/mini_map/mini_map.c \
			sources/move/keys.c \
			sources/move/move_player.c \
			sources/move/move_utils.c \
			sources/move/open_door.c \
			sources/ray_casting/check_wall.c \
			sources/ray_casting/check_wall_utils.c \
			sources/ray_casting/check_exit_utils.c \
			sources/ray_casting/raycasting.c \
			sources/ray_casting/raycasting_utils.c \
			sources/ray_casting/render.c \
			sources/ray_casting/render_exit.c \
			sources/ray_casting/render_background.c \
			sources/utils/get_pixel_color.c

OBJECTS = $(SOURCES:.c=.o)

# Compilación principal
all: $(NAME)

$(NAME): $(OBJECTS) $(LIBFT_LIB) $(LBMLX_LIB)
	$(CC) $(CFLAGS) $(OBJECTS) $(INC_LIB) $(INC_MLX) -o $(NAME)

# Compilar libft
$(LIBFT_LIB):
	make -C $(LIBFT_PATH)

# Compilar MLX
$(LBMLX_LIB):
	make -C $(LBMLX_PATH)

# Compilar archivos .o
%.o: %.c
	$(CC) $(CFLAGS) -I$(LBMLX_PATH) -I$(LIBFT_PATH) -c $< -o $@

# Limpiar
clean:
	$(RM) $(OBJECTS)
	make -C $(LIBFT_PATH) clean
	make -C $(LBMLX_PATH) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re
