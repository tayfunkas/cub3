# Nombre del ejecutable
NAME = cub3D
BONUS_NAME = cub3D_bonus

# Compilador y flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -rf

# Librerías externas
LIBFT_PATH = ./libft
LIBFT_LIB = $(LIBFT_PATH)/libft.a
INC_LIB = -L$(LIBFT_PATH) -lft

LBMLX_PATH = ./minilibx-linux
LBMLX_LIB = $(LBMLX_PATH)/libmlx.a
INC_MLX = -L$(LBMLX_PATH) -lmlx -lXext -lX11 -lm -lz

# Fuentes Mandatory
SRC = \
	Mandatory/animations/animation.c \
	Mandatory/free/free.c \
	Mandatory/free/free_engine.c \
	Mandatory/init/initialize_engine.c \
	Mandatory/init/initialize_game.c \
	Mandatory/init/initialize_player.c \
	Mandatory/init_game.c \
	Mandatory/load_image.c \
	Mandatory/main.c \
	Mandatory/map_parsing/assign_line.c \
	Mandatory/map_parsing/check_colors.c \
	Mandatory/map_parsing/check_textures.c \
	Mandatory/map_parsing/checks.c \
	Mandatory/map_parsing/get_exit.c \
	Mandatory/map_parsing/parse_map.c \
	Mandatory/map_parsing/parsing_utils.c \
	Mandatory/map_parsing/validate_map.c \
	Mandatory/mini_map/draw_minimap.c \
	Mandatory/mini_map/mini_map.c \
	Mandatory/move/keys.c \
	Mandatory/move/move_player.c \
	Mandatory/move/move_utils.c \
	Mandatory/move/open_door.c \
	Mandatory/ray_casting/check_wall.c \
	Mandatory/ray_casting/check_wall_utils.c \
	Mandatory/ray_casting/check_exit_utils.c \
	Mandatory/ray_casting/raycasting.c \
	Mandatory/ray_casting/raycasting_utils.c \
	Mandatory/ray_casting/render.c \
	Mandatory/ray_casting/render_exit.c \
	Mandatory/ray_casting/render_background.c \
	Mandatory/utils/get_pixel_color.c

# Fuentes Bonus
SRC_BONUS = \
	Bonus/animations/animation.c \
	Bonus/free/free.c \
	Bonus/free/free_engine.c \
	Bonus/init/initialize_engine.c \
	Bonus/init/initialize_game.c \
	Bonus/init/initialize_player.c \
	Bonus/init_game.c \
	Bonus/load_image.c \
	Bonus/main.c \
	Bonus/map_parsing/assign_line.c \
	Bonus/map_parsing/check_colors.c \
	Bonus/map_parsing/check_textures.c \
	Bonus/map_parsing/checks.c \
	Bonus/map_parsing/get_exit.c \
	Bonus/map_parsing/parse_map.c \
	Bonus/map_parsing/parsing_utils.c \
	Bonus/map_parsing/validate_map.c \
	Bonus/mini_map/draw_minimap.c \
	Bonus/mini_map/mini_map.c \
	Bonus/move/keys.c \
	Bonus/move/move_player.c \
	Bonus/move/move_utils.c \
	Bonus/move/open_door.c \
	Bonus/ray_casting/check_wall.c \
	Bonus/ray_casting/check_wall_utils.c \
	Bonus/ray_casting/check_exit_utils.c \
	Bonus/ray_casting/raycasting.c \
	Bonus/ray_casting/raycasting_utils.c \
	Bonus/ray_casting/render.c \
	Bonus/ray_casting/render_exit.c \
	Bonus/ray_casting/render_background.c \
	Bonus/utils/get_pixel_color.c

# Objetos
OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

# Reglas
all: $(NAME)

$(NAME): $(OBJ) $(LIBFT_LIB) $(LBMLX_LIB)
	$(CC) $(CFLAGS) $(OBJ) $(INC_LIB) $(INC_MLX) -o $(NAME)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(OBJ_BONUS) $(LIBFT_LIB) $(LBMLX_LIB)
	$(CC) $(CFLAGS) $(OBJ_BONUS) $(INC_LIB) $(INC_MLX) -o $(BONUS_NAME)

# Compilar libft y MLX
$(LIBFT_LIB):
	make -C $(LIBFT_PATH)

$(LBMLX_LIB):
	make -C $(LBMLX_PATH)

# Compilación de objetos
%.o: %.c
	$(CC) $(CFLAGS) -I$(LIBFT_PATH) -I$(LBMLX_PATH) -c $< -o $@

# Limpieza
clean:
	$(RM) $(OBJ) $(OBJ_BONUS)
	make -C $(LIBFT_PATH) clean
	make -C $(LBMLX_PATH) clean

fclean: clean
	$(RM) $(NAME) $(BONUS_NAME)
	make -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all bonus clean fclean re
