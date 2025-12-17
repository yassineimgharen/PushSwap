CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS =  libft/ft_putchar_fd.c \
        libft/ft_putstr_fd.c \
        libft/ft_split.c \
        libft/ft_atoi.c \
        libft/ft_strdup.c \
        libft/ft_strlen.c \
        libft/ft_isdigit.c \
        libft/ft_strncmp.c \
        libft/ft_abs.c \
        parsing.c \
        push_operations.c \
        swap_operations.c \
        rotate_operations.c \
        reverse_rotate_operations.c \
        stack_utils.c \
        sort.c \
        sort_big.c \
        move_to_top.c \
        rotate_ab_push_to_a.c \
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
