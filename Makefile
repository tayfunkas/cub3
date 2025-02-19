NAME = cub3D

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -rf

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
	sources/move/direcction_player.c

OBJECTS = $(SOURCES:.c=.o)

LIBFT_PATH = ./libft
LIBFT_LIB = $(LIBFT_PATH)/libft.a
LBMLX_PATH = minilibx-linux
LBMLX_LIB = $(LBMLX_PATH)/libmlx.a
INC_LIB = -L$(LIBFT_PATH) -lft
INC_MLX = -L$(LBMLX_PATH) -lmlx

all: $(NAME)

$(NAME): $(OBJECTS) $(LIBFT_LIB) $(LBMLX_LIB)
	$(CC) $(CFLAGS) $(OBJECTS) $(INC_LIB) $(INC_MLX) -lXext -lX11 -lm -lz -o $(NAME)

$(LIBFT_LIB):
	make -C $(LIBFT_PATH)

$(LBMLX_LIB):
	make -C $(LBMLX_PATH)

%.o: %.c
	$(CC) $(CFLAGS) -I$(LBMLX_PATH) -c $< -o $@

clean:
	$(RM) $(OBJECTS)
	make -C $(LIBFT_PATH) clean
	make -C $(LBMLX_PATH) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re
