CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = push_swap
BONUS_NAME = checker

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
        find_min_pos.c \
        ft_is_sorted.c \
        main.c
OBJS = $(SRCS:.c=.o)

BONUS_SRC = bonus/get_next_line_bonus.c \
        bonus/get_next_line_utils_bonus.c \
        bonus/ft_checker_bonus.c \
        bonus/ft_exit_error.c \
        libft/ft_strncmp.c \
        libft/ft_putchar_fd.c \
        libft/ft_putstr_fd.c \
        libft/ft_split.c \
        libft/ft_atoi.c \
        libft/ft_isdigit.c \
        libft/ft_abs.c \
        parsing.c \
        bonus/ft_push_operations.c \
        bonus/ft_swap_operations.c \
        bonus/ft_rotate_operations.c \
        bonus/ft_reverse_rotate_operations.c \
        stack_utils.c \
        ft_is_sorted.c \

BONUS_OBJS = $(BONUS_SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus : $(BONUS_NAME)

$(BONUS_NAME) : $(BONUS_OBJS) 
	$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(BONUS_NAME)

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re
