NAME = cub3

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -rf

SOURCES = sources/checks.c \
	sources/free.c \
	sources/initialize.c \
	sources/get_next_line.c \
	sources/get_next_line_utils.c \
	sources/parsing_utils.c \
	sources/border_check.c \
	sources/check_images.c \
	sources/parse_map.c \
	sources/main.c 

OBJECTS = $(SOURCES:.c=.o)

LIBFT_DIR = ./libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a


all: $(NAME)

$(NAME): $(OBJECTS) $(LIBFT_LIB) 
	$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT_LIB) -o $(NAME)

$(LIBFT_LIB):
	make -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJECTS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
