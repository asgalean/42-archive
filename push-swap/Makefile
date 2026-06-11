NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

CFILES = ft_split.c \
			moves_a.c \
			moves_all.c \
			moves_b.c \
			moves.c \
			push_swap.c \
			radix.c \
			sorting_2.c \
			sorting.c \
			stack_nodes_1.c \
			stack_nodes_2.c \
			utils_and_parse.c \
			ft_printf/ft_printf.c \
			ft_printf/ft_printf_utils.c

OFILES = $(CFILES:%.c=%.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ 

$(NAME): $(OFILES)
	$(CC) $(OFILES) -o $(NAME)

all: $(NAME)

clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
