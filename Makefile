CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS =  libft/ft_putchar_fd.c \
        libft/ft_putstr_fd.c \
        libft/ft_split.c \
        libft/ft_atoi.c \
        libft/ft_strdup.c \
        libft/ft_strlen.c \
        libft/ft_isdigit.c \
        parsing.c \
        operations.c \
        stack_utils.c \
        sort.c \
        sort_big.c \
        move_to_top.c \
        main.c
OBJS = $(SRCS:.c=.o)

NAME = push_swap

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

