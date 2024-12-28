NAME = cub3

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -rf

SOURCES = checks.c \
	sources/free.c \
	sources/initialize.c \
	sources/get_next_line.c \
	sources/get_next_line_utils.c \
	sources/parsing_utils.c 

OBJECTS = $(SOURCES:.c=.o)

INCLUDES = -I./mlx

MLX_DIR = ./mlx

MLX_LIB = $(MLX_DIR)/libmlx.a

MLX = -L$(MLX_DIR) -lmlx -lXext -lX11  # For Linux
# MLX = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit  # For macOS

all: $(NAME)

$(NAME): $(OBJECTS) $(MLX_LIB)
	$(CC) $(CFLAGS) $(OBJECTS) $(MLX) -o $(NAME)

$(MLX_LIB):
	make -C $(MLX_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJECTS)
	make -C $(MLX_DIR) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(MLX_DIR) clean

re: fclean all

.PHONY: all clean fclean re