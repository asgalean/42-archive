NAME = philo

CC = cc
CFLAGS = -Wall -Wextra -Werror

CFILES = main.c \
			parse.c \
			routine.c \
			routine_checks.c \
			table.c

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
