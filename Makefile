##NAME = cub3D
##
##CC = cc
##CFLAGS = -Wall -Wextra -Werror -g
##RM = rm -rf
##
##SOURCES = 	sources/map_parsing/checks.c \
##	sources/map_parsing/parsing_utils.c \
##	sources/map_parsing/validate_map.c \
##	sources/map_parsing/check_textures.c \
##	sources/map_parsing/check_colors.c \
##	sources/map_parsing/parse_map.c \
##	sources/free.c \
##	sources/initialize.c \
##	sources/init_game.c \
##	sources/main.c \
##	sources/move/move_player.c \
##	sources/move/keys.c \
##	sources/ray_casting/rc_fov.c \
##	sources/ray_casting/render_background.c
##
##OBJECTS = $(SOURCES:.c=.o)
##
##LIBFT_PATH = ./libft
##LIBFT_LIB = $(LIBFT_PATH)/libft.a
##LBMLX_PATH = minilibx-linux
##LBMLX_LIB = $(LBMLX_PATH)/libmlx.a
##INC_LIB = -L$(LIBFT_PATH) -lft
##INC_MLX = -L$(LBMLX_PATH) -lmlx
##
##all: $(NAME)
##
##$(NAME): $(OBJECTS) $(LIBFT_LIB) $(LBMLX_LIB)
##	$(CC) $(CFLAGS) $(OBJECTS) $(INC_LIB) $(INC_MLX) -lXext -lX11 -lm -lz -o $(NAME)
##
##$(LIBFT_LIB):
##	make -C $(LIBFT_PATH)
##
##$(LBMLX_LIB):
##	make -C $(LBMLX_PATH)
##
##%.o: %.c
##	$(CC) $(CFLAGS) -I$(LBMLX_PATH) -c $< -o $@
##
##clean:
##	$(RM) $(OBJECTS)
##	make -C $(LIBFT_PATH) clean
##	make -C $(LBMLX_PATH) clean
##
##fclean: clean
##	$(RM) $(NAME)
##	make -C $(LIBFT_PATH) fclean
##
##re: fclean all
##
##.PHONY: all clean fclean re
##
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

ifeq ($(UNAME_S), Darwin)
	LBMLX_PATH = minilibx-mac
	LBMLX_LIB = $(LBMLX_PATH)/libmlx.a
	INC_MLX = -L$(LBMLX_PATH) -lmlx -framework OpenGL -framework AppKit
endif

# Libft
LIBFT_PATH = ./libft
LIBFT_LIB = $(LIBFT_PATH)/libft.a
INC_LIB = -L$(LIBFT_PATH) -lft

# Fuentes y objetos
SOURCES = 	sources/map_parsing/checks.c \
			sources/map_parsing/parsing_utils.c \
			sources/map_parsing/validate_map.c \
			sources/map_parsing/check_textures.c \
			sources/map_parsing/check_colors.c \
			sources/map_parsing/parse_map.c \
			sources/free.c \
			sources/initialize.c \
			sources/init_game.c \
			sources/main.c \
			sources/move/move_player.c \
			sources/move/keys.c \
			sources/ray_casting/rc_fov.c \
			sources/ray_casting/render_background.c

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
