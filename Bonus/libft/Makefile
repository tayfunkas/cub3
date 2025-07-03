NAME = libft.a

SRC =	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c \
	ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c \
	ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c \
	ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c ft_printf_hexaupper.c ft_hexadecimal.c ft_printf_addr.c ft_printf_char.c\
	ft_printf_hexa.c ft_printf_hexaupper.c ft_printf_numb.c ft_printf_hexaupper.c ft_printf_str.c ft_printf_uint.c ft_printf.c \
	get_next_line_utils.c get_next_line.c

BONUS_SRC =	ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c

SRC_OBJS := $(SRC:%.c=%.o)

BONUS_OBJS := $(BONUS_SRC:%.c=%.o)

ALL_OBJS := $(SRC_OBJS) $(BONUS_OBJS)

CC = cc

CCFLAGS = -Wall -Werror -Wextra -I.

RM = rm -f

ARNAME = ar rcs $(NAME)

RANNAME = ranlib $(NAME)

all: $(NAME)

%.o: %.c
	$(CC) $(CCFLAGS) -o $@ -c $<

$(NAME): $(SRC_OBJS)
	$(ARNAME) $(SRC_OBJS) 
	$(RANNAME)

clean:
	 $(RM) $(ALL_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

bonus:	$(ALL_OBJS)
	$(ARNAME) $(ALL_OBJS)
	$(RANNAME)
