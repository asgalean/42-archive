/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgalean <asgalean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 11:36:14 by asgalean          #+#    #+#             */
/*   Updated: 2025/02/25 12:41:05 by asgalean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>
# include "gnl_printf/get_next_line.h"
# include "gnl_printf/ft_printf.h"

typedef struct s_info
{
	char	**map;
	int		row_max;
	int		col_max;
	int		tokens;
	int		ff_tokens;
	int		can_reach_exit;
	char	**ff_map;
	int		player_row;
	int		player_col;
	int		exit_row;
	int		exit_col;
	int		owned_tokens;
	int		move_count;
	int		on_exit;
	int		moving;
}		t_info;

typedef struct s_img
{
	void	*p_idle;
	void	*p_up_1;
	void	*p_up_2;
	void	*p_down_1;
	void	*p_down_2;
	void	*p_left_1;
	void	*p_left_2;
	void	*p_right_1;
	void	*p_right_2;
	void	*floor;
	void	*wall;
	void	*coin;
	void	*exit_0;
	void	*exit_25;
	void	*exit_50;
	void	*exit_75;
	void	*exit_100;
	void	*exit_100_2;
	int		width;
	int		height;
}	t_img;

typedef struct s_window
{
	void	*mlx;
	void	*mlx_win;
	t_img	img;
	t_info	info;
	int		img_width;
	int		img_height;
	int		win_width;
	int		win_height;
}		t_window;

//	PARSE
int		dump_map(char *route, t_info *info);
int		ff_dump_map(char *route, t_info *info);
void	map_transformer(t_info *info);
void	ff_map_transformer(t_info *info);
void	map_and_ff_map_get(char *route, t_info *info);

//	CHECKS
//		ARGS
int		input_check(int arg_num, char *route);

//		FILE
int		extension_valid(char *file_name);
int		fd_check(int fd);

//		MAP
int		size_check(t_info *info);
int		check_borders(t_info *info);
int		check_tiles(t_info *info);
int		check_objects(t_info *info);
int		is_good_map(t_info *info);
int		map_check(t_info *info);
int		row_counter(char *route, t_info *info);
int		player_exit_number(t_info *info);
void	floodfill(t_info *info, int row, int col);
int		valid_path(t_info *info);

//	GAME
//		INFO
void	player_exit_pos_get(t_info *info);
void	play_stats_init(t_info *info);

//		SPRITES
void	load_map_sprites(t_img *img, void *mlx);
void	load_player_sprites(t_img *img, void *mlx);
void	load_all_sprites(t_img *img, void *mlx);

//		GAMEPLAY
void	exit_position_update_and_print(t_info *info, t_window *mlx);
void	floor_position_update_and_print(t_info *info, t_window *mlx);
void	update_moving(t_info *info);
void	move_left(t_info *info, t_window *mlx);
void	move_right(t_info *info, t_window *mlx);
void	move_up(t_info *info, t_window *mlx);
void	move_down(t_info *info, t_window *mlx);

//	PRINT
//		PLAYER
void	print_left(t_info *info, t_window *mlx, t_img img);
void	print_right(t_info *info, t_window *mlx, t_img img);
void	print_up(t_info *info, t_window *mlx, t_img img);
void	print_down(t_info *info, t_window *mlx, t_img img);

//		TILES
void	print_floor(t_info *info, t_window *mlx, t_img img);
void	print_exit(t_info *info, t_window *mlx, t_img img);
void	map_to_window(void *mlx, void *mlx_win, t_info info, t_img img);
void	birb_fly(t_window *mlx, t_info *info, t_img img);

//	MLX HOOK
int		key_hook(int keycode, t_window *mlx);

//	CLEANING
void	ff_map_free(t_info *info);
void	free_images(t_window *mlx);
void	free_map(t_window *mlx);
int		close_game(t_window *mlx);

#endif
