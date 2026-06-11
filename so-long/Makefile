NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -Imlx
LIBS = -Lmlx -lmlx -lX11 -lXext -lm

CFILES = so_long.c \
			functions/check_args_file.c \
			functions/cleaning_and_hook.c \
			functions/game_sprites.c \
			functions/print_player.c \
			functions/check_map_1.c \
			functions/game_info.c \
			functions/game_update.c \
			functions/print_tiles.c \
			functions/check_map_2.c \
			functions/game_player_movement.c \
			functions/parse.c \
			gnl_printf/get_next_line.c \
			gnl_printf/get_next_line_utils.c \
			gnl_printf/ft_printf.c \
			gnl_printf/ft_printf_utils.c

OFILES = $(CFILES:%.c=%.o)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDES)

$(NAME): $(OFILES)
	$(MAKE) -C mlx
	$(CC) $(OFILES) $(LIBS) $(INCLUDES) -o $(NAME)

all: $(NAME)

clean:
	rm $(OFILES)
	$(MAKE) -C mlx clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C mlx fclean

re: fclean all

.PHONY: all clean fclean re
