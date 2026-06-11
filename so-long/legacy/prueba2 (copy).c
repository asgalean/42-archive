#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#include "gnl/get_next_line.c"
#include "gnl/get_next_line_utils.c"
#include "so_long.h"

int	extension_valid(char *file_name)
{
	int	i;

	i = ft_strlen(file_name);
	if (file_name[i - 1] == 'r' && file_name[i - 2] == 'e'
		&& file_name[i - 3] == 'b' && file_name[i - 4] == '.')
		return (1);
	return (printf("Invalid extension\n"), 0);
}

//****************************************************************
//****************************************************************

int	fd_check(int fd)
{
	if (fd < 0)
		return (printf("Error while opening file\n"), 0);
	return (1);
}

//****************************************************************
//****************************************************************

int	row_counter(char *route, t_info *info)
{
	int		rows;
	int		fd;
	char	*line;

	rows = 0;
	fd = open(route, O_RDONLY);
	if (!fd_check(fd))
		return (0);
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		rows++;
		//printf("%d\n", rows);
	}
	close(fd);
	free(line);
	info->row_max = rows;
	//printf("%d\n", info->row_max);
	return (1);
}

//****************************************************************
//****************************************************************

int	dump_map(char *route, t_info *info)
{
	int	i;
	int	fd;

	info->map = (char **)malloc(sizeof(char *) * (info->row_max + 1));
	info->map[info->row_max] = 0;

	fd = open(route, O_RDONLY);

	i = 0;
	while (i < info->row_max)
	{
		info->map[i] = get_next_line(fd);
		//printf("%s", info->map[i]);
		i++;
	}
	close(fd);
	return (1);
}

//****************************************************************
//****************************************************************

int	ff_dump_map(char *route, t_info *info)
{
	int	i;
	int	fd;

	info->ff_map = (char **)malloc(sizeof(char *) * (info->row_max + 1));
	info->ff_map[info->row_max] = 0;

	fd = open(route, O_RDONLY);

	i = 0;
	while (i < info->row_max)
	{
		info->ff_map[i] = get_next_line(fd);
		//printf("%s", info->map[i]);
		i++;
	}
	close(fd);
	return (1);
}

//****************************************************************
//****************************************************************

int	size_check(t_info *info)
{
	int	col;
	int	col_max;
	int	row;

	if (!info->map)
		return (0);

	col_max = 0;
	while (info->map[0][col_max])
		col_max++;

	row = 0;
	while (info->map[row])
	{
		col = 0;
		while (info->map[row][col])
		{
			col++;
		}
		if (col != col_max)
			return (0);
		row++;
	}
	info->col_max = col_max;
	return (1);
}


//****************************************************************
//****************************************************************

int	check_borders(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->row_max)
	{
		if (info->map[i][0] != '1' || info->map[i][info->col_max - 1] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < info->col_max)
	{
		if (info->map[0][i] != '1' || info->map[info->row_max - 1][i] != '1')
			return (0);
		i++;
	}
	return (1);
}

//****************************************************************
//****************************************************************

int	check_tiles(t_info *info)
{
	int	i;
	int	j;

	info->tokens = 0;
	i = 0;
	while (i < info->row_max)
	{
		j = 0;
		while (j < info->col_max)
		{
			if (info->map[i][j] == 'C')
				info->tokens++;
			if (info->map[i][j] != '1' && info->map[i][j] != '0'
				&& info->map[i][j] != 'P' && info->map[i][j] != 'C'
					&& info->map[i][j] != 'E')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

//****************************************************************
//****************************************************************

int	player_exit_number(t_info *info)
{
	int	i;
	int	j;
	int	player_count;
	int	exit_count;

	player_count = 0;
	exit_count = 0;
	i = -1;
	while (++i < info->row_max)
	{
		j = -1;
		while (++j < info->col_max)
		{
			if (info->map[i][j] == 'P')
				player_count++;
			if (info->map[i][j] == 'E')
				exit_count++;
		}
	}
	if (player_count != 1)
		return (printf("Error in number of players\n"), 0);
	if (exit_count != 1)
		return (printf("Error in number of exits\n"), 0);
	return (1);
}

//****************************************************************
//****************************************************************

void	ff_map_transformer(t_info *info)
{
	int	i;
	int	j;

	i = 0;
	while (info->ff_map[i])
	{
		j = 0;
		while (info->ff_map[i][j] != '\0')
		{
			if (info->ff_map[i][j] == '\n')
				info->ff_map[i][j] = '\0';
			j++;
		}
		i++;
	}
}

//****************************************************************
//****************************************************************

void floodfill(t_info *info, int row, int col)
{
	if (info->ff_map[row][col] == 'C')
		info->ff_tokens++;
	if (info->ff_map[row][col] == 'E')
		info->can_reach_exit = 1;
	info->ff_map[row][col] = 'X';
	if (row >= 0 && info->map[row - 1][col] != '1'
		&& info->ff_map[row - 1][col] != 'X')
		floodfill(info, row - 1, col);
	if (col >= 0 && info->map[row][col - 1] != '1'
		&& info->ff_map[row][col - 1] != 'X')
		floodfill(info, row, col - 1);
	if (row <= info->row_max - 1 && info->map[row + 1][col] != '1'
		&& info->ff_map[row + 1][col] != 'X')
		floodfill(info, row + 1, col);
	if (col <= info->col_max - 1 && info->map[row][col + 1] != '1'
		&& info->ff_map[row][col + 1] != 'X')
		floodfill(info, row, col + 1);
}

//****************************************************************
//****************************************************************

int	valid_path(t_info *info)
{
	info->can_reach_exit = 0;
	info->ff_tokens = 0;
	floodfill(info, info->player_row, info->player_col);
	
	if (!info->can_reach_exit)
		return (printf("Player can't reach exit\n"), 0);
	if (info->ff_tokens != info->tokens)
		return (printf("Collectable out of bounds\n"), 0);
	return (1);
}

//****************************************************************
//****************************************************************

void player_exit_pos_get(t_info *info)
{
	int	i;
	int	j;
	
	i = 0;
	while (i < info->row_max)
	{
		j = 0;
		while (j < info->col_max)
		{
			if (info->map[i][j] == 'P')
			{
				info->player_row = i;
				info->player_col = j;
			}
			if (info->map[i][j] == 'E')
			{
				info->exit_row = i;
				info->exit_col = j;
			}
			j++;
		}
		i++;
	}
}

//****************************************************************
//****************************************************************

int	check_objects(t_info *info)
{
	if (!player_exit_number(info))
		return (0);
	if (info->tokens == 0)
		return (printf("There are no collectables\n"), 0);
	player_exit_pos_get(info);
	if (!valid_path(info))
		return (0);
	return (1);
}

//****************************************************************
//****************************************************************

int	is_good_map(t_info *info)
{
	if (!check_borders(info))
		return (printf("Borders not legal\n"), 0);
	if (!check_tiles(info))
		return (printf("Tiles not valid\n"), 0);
	if (!check_objects(info))
		return (0);
	return (1);
}

//****************************************************************
//****************************************************************

void	ff_map_free(t_info *info)
{
	int	i;
	
	i = 0;
	while (info->ff_map[i])
	{
		free(info->ff_map[i]);
		i++;
	}
	free(info->ff_map);
}

//****************************************************************
//****************************************************************

int	map_check(t_info *info)
{
	if (!size_check(info))
	{
		ff_map_free(info);
		return (printf("Size not valid\n"), 0);
	}
	if (!is_good_map(info))
	{
		ff_map_free(info);
		return (0);
	}
	ff_map_free(info);
	return (1);

}

//****************************************************************
//****************************************************************

void	map_transformer(t_info *info)
{
	int	i;
	int	j;

	i = 0;
	while (info->map[i])
	{
		j = 0;
		while (info->map[i][j] != '\0')
		{
			if (info->map[i][j] == '\n')
				info->map[i][j] = '\0';
			j++;
		}
		i++;
	}
}

//****************************************************************
//****************************************************************

void	print_map(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->row_max)
	{
		printf("%s\n", info->map[i]);
		i++;
	}
}

//****************************************************************
//****************************************************************

void	play_stats_init(t_info *info)
{
	info->owned_tokens = 0;
	info->move_count = 0;
	info->on_exit = 0;
	info->moving = 1;
}

//****************************************************************
//****************************************************************

void	load_map_sprites(t_img *img, void *mlx)
{
	img->floor = mlx_xpm_file_to_image(mlx, "sprites/ground.xpm",
		&img->width, &img->height);
	img->wall = mlx_xpm_file_to_image(mlx, "sprites/wall1.xpm",
		&img->width, &img->height);
	img->coin = mlx_xpm_file_to_image(mlx, "sprites/collectable.xpm",
		&img->width, &img->height);
	img->exit_0 = mlx_xpm_file_to_image(mlx, "sprites/exit_0.xpm",
		&img->width, &img->height);
	img->exit_25 = mlx_xpm_file_to_image(mlx, "sprites/exit_25.xpm",
		&img->width, &img->height);
	img->exit_50 = mlx_xpm_file_to_image(mlx, "sprites/exit_50.xpm",
		&img->width, &img->height);
	img->exit_75 = mlx_xpm_file_to_image(mlx, "sprites/exit_75.xpm",
		&img->width, &img->height);
	img->exit_100 = mlx_xpm_file_to_image(mlx, "sprites/exit_100.xpm",
		&img->width, &img->height);
}

//****************************************************************
//****************************************************************

void	load_player_sprites(t_img *img, void *mlx)
{
	img->p_idle = mlx_xpm_file_to_image(mlx, "sprites/gold_down_idle.xpm",
		&img->width, &img->height);
	img->p_up_1 = mlx_xpm_file_to_image(mlx, "sprites/gold_up1.xpm",
		&img->width, &img->height);
	img->p_up_2 = mlx_xpm_file_to_image(mlx, "sprites/gold_up2.xpm",
		&img->width, &img->height);
	img->p_down_1 = mlx_xpm_file_to_image(mlx, "sprites/gold_down1.xpm",
		&img->width, &img->height);
	img->p_down_2 = mlx_xpm_file_to_image(mlx, "sprites/gold_down2.xpm",
		&img->width, &img->height);
	img->p_left_1 = mlx_xpm_file_to_image(mlx, "sprites/gold_left.xpm",
		&img->width, &img->height);
	img->p_left_2 = mlx_xpm_file_to_image(mlx, "sprites/gold_left2.xpm",
		&img->width, &img->height);
	img->p_right_1 = mlx_xpm_file_to_image(mlx, "sprites/gold_right.xpm",
		&img->width, &img->height);
	img->p_right_2 = mlx_xpm_file_to_image(mlx, "sprites/gold_right2.xpm",
		&img->width, &img->height);
}

//****************************************************************
//****************************************************************

void	load_all_sprites(t_img *img, void *mlx)
{
	load_player_sprites(img, mlx);
	load_map_sprites(img, mlx);
}

//****************************************************************
//****************************************************************

void	map_to_window(void	*mlx, void *mlx_win,  t_info info, t_img img)
{
	int		i;
	int		j;
	
	i = -1;
	while (++i < info.row_max)
	{
		j = -1;
		while (++j < info.col_max)
		{
			if (info.map[i][j] == '0')
				mlx_put_image_to_window(mlx, mlx_win, img.floor,
					j * 64, i * 64);
			if (info.map[i][j] == '1')
				mlx_put_image_to_window(mlx, mlx_win, img.wall, j * 64, i * 64);
			if (info.map[i][j] == 'E')
				mlx_put_image_to_window(mlx, mlx_win, img.exit_0,
					j * 64, i * 64);
			if (info.map[i][j] == 'C')
				mlx_put_image_to_window(mlx, mlx_win, img.coin, j * 64, i * 64);
			if (info.map[i][j] == 'P')
				mlx_put_image_to_window(mlx, mlx_win, img.p_idle,
					j * 64, i * 64);
		}
	}
}

//****************************************************************
//****************************************************************

void	print_floor(t_info *info, t_window *mlx, t_img img)
{
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, img.floor,
		info->player_col * 64, info->player_row * 64);
}

//****************************************************************
//****************************************************************

void	print_exit(t_info *info, t_window *mlx, t_img img)
{
	if ((info->owned_tokens * 100)/info->tokens < 25)
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, img.exit_0,
			info->exit_col * 64, info->exit_row * 64);
	else if ((info->owned_tokens * 100)/info->tokens < 50)
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, img.exit_25,
			info->exit_col * 64, info->exit_row * 64);
	else if ((info->owned_tokens * 100)/info->tokens < 75)
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, img.exit_50,
			info->exit_col * 64, info->exit_row * 64);
	else if ((info->owned_tokens * 100)/info->tokens < 100)
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, img.exit_75,
			info->exit_col * 64, info->exit_row * 64);
	else if ((info->owned_tokens * 100)/info->tokens == 100)
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, img.exit_100,
			info->exit_col * 64, info->exit_row * 64);
}

//****************************************************************
//****************************************************************

void	print_left(t_info *info, t_window *mlx, t_img img)
{
	if (info->moving == 1)
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, img.p_left_1,
			info->player_col * 64, info->player_row * 64);
	if (info->moving == 2)
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, img.p_left_2,
			info->player_col * 64, info->player_row * 64);
}

//****************************************************************
//****************************************************************

void	print_right(t_info *info, t_window *mlx, t_img img)
{
	if (info->moving == 1)
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, img.p_right_1,
			info->player_col * 64, info->player_row * 64);
	if (info->moving == 2)
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, img.p_right_2,
			info->player_col * 64, info->player_row * 64);
}

//****************************************************************
//****************************************************************

void	print_up(t_info *info, t_window *mlx, t_img img)
{
	if (info->moving == 1)
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, img.p_up_1,
			info->player_col * 64, info->player_row * 64);
	if (info->moving == 2)
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, img.p_up_2,
			info->player_col * 64, info->player_row * 64);
}

//****************************************************************
//****************************************************************

void	print_down(t_info *info, t_window *mlx, t_img img)
{
	if (info->moving == 1)
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, img.p_down_1,
			info->player_col * 64, info->player_row * 64);
	if (info->moving == 2)
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, img.p_down_2,
			info->player_col * 64, info->player_row * 64);
}


//****************************************************************
//****************************************************************

void	free_images(t_window *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->img.p_idle);
	mlx_destroy_image(mlx->mlx, mlx->img.p_up_1);
	mlx_destroy_image(mlx->mlx, mlx->img.p_up_2);
	mlx_destroy_image(mlx->mlx, mlx->img.p_down_1);
	mlx_destroy_image(mlx->mlx, mlx->img.p_down_2);
	mlx_destroy_image(mlx->mlx, mlx->img.p_left_1);
	mlx_destroy_image(mlx->mlx, mlx->img.p_left_2);
	mlx_destroy_image(mlx->mlx, mlx->img.p_right_1);
	mlx_destroy_image(mlx->mlx, mlx->img.p_right_2);
	mlx_destroy_image(mlx->mlx, mlx->img.floor);
	mlx_destroy_image(mlx->mlx, mlx->img.wall);
	mlx_destroy_image(mlx->mlx, mlx->img.coin);
	mlx_destroy_image(mlx->mlx, mlx->img.exit_0);
	mlx_destroy_image(mlx->mlx, mlx->img.exit_25);
	mlx_destroy_image(mlx->mlx, mlx->img.exit_50);
	mlx_destroy_image(mlx->mlx, mlx->img.exit_75);
	mlx_destroy_image(mlx->mlx, mlx->img.exit_100);
}

//****************************************************************
//****************************************************************

void free_map(t_window *mlx)
{
	int	i;
	
	i = 0;
	while (mlx->info.map[i])
	{
		free(mlx->info.map[i]);
		i++;
	}
	free(mlx->info.map);
}

//****************************************************************
//****************************************************************

int	close_game(t_window *mlx)
{
	free_images(mlx);
	free_map(mlx);
	mlx_destroy_window(mlx->mlx, mlx->mlx_win);
	mlx_destroy_display(mlx->mlx);
	free(mlx->mlx);
	exit(1);
}

//****************************************************************
//****************************************************************

void	exit_position_update_and_print(t_info *info, t_window *mlx)
{
	info->map[info->player_row][info->player_col] = 'E';
	print_exit(info, mlx, mlx->img);
}

//****************************************************************
//****************************************************************

void	floor_position_update_and_print(t_info *info, t_window *mlx)
{
	info->map[info->player_row][info->player_col] = '0';
	print_floor(info, mlx, mlx->img);
}

//****************************************************************
//****************************************************************

void	update_moving(t_info *info)
{
	if (info->moving == 1)
		info->moving = 2;
	else
		info->moving = 1;
}

//****************************************************************
//****************************************************************

void	move_left(t_info *info, t_window *mlx)
{
	if (info->on_exit == 1)
		exit_position_update_and_print(info, mlx);
	else
		floor_position_update_and_print(info, mlx);
	if (info->player_col > 0
		&& info->map[info->player_row][info->player_col - 1] != '1')
	{
		info->on_exit = 0;
		if (info->map[info->player_row][info->player_col - 1] == 'C')
		{
			info->owned_tokens++;
			print_exit(info, mlx, mlx->img);
		}
		if (info->map[info->player_row][info->player_col - 1] == 'E')
		{
			info->on_exit = 1;
			if (info->owned_tokens == info->tokens)
				close_game(mlx);
		}
		info->player_col--;
		printf("Number of moves: %d\n", ++info->move_count);
	}
		update_moving(info);
		info->map[info->player_row][info->player_col] = 'P';
		print_left(info, mlx, mlx->img);
}

//****************************************************************
//****************************************************************

void	move_right(t_info *info, t_window *mlx)
{
	if (info->on_exit == 1)
		exit_position_update_and_print(info, mlx);
	else
		floor_position_update_and_print(info, mlx);
	if (info->player_col < info->col_max
		&& info->map[info->player_row][info->player_col + 1] != '1')
	{
		info->on_exit = 0;
		if (info->map[info->player_row][info->player_col + 1] == 'C')
		{
			info->owned_tokens++;
			print_exit(info, mlx, mlx->img);
		}
		if (info->map[info->player_row][info->player_col + 1] == 'E')
		{
			info->on_exit = 1;
			if (info->owned_tokens == info->tokens)
				close_game(mlx);
		}
		info->player_col++;
		printf("Number of moves: %d\n", ++info->move_count);
	}
		update_moving(info);
		info->map[info->player_row][info->player_col] = 'P';
		print_right(info, mlx, mlx->img);
}

//****************************************************************
//****************************************************************

void	move_up(t_info *info, t_window *mlx)
{
	if (info->on_exit == 1)
		exit_position_update_and_print(info, mlx);
	else
		floor_position_update_and_print(info, mlx);
	if (info->player_row > 0
		&& info->map[info->player_row - 1][info->player_col] != '1')
	{
		info->on_exit = 0;
		if (info->map[info->player_row - 1][info->player_col] == 'C')
		{
			info->owned_tokens++;
			print_exit(info, mlx, mlx->img);
		}
		if (info->map[info->player_row - 1][info->player_col] == 'E')
		{
			info->on_exit = 1;
			if (info->owned_tokens == info->tokens)
				close_game(mlx);
		}
		info->player_row--;
		printf("Number of moves: %d\n", ++info->move_count);
	}
		update_moving(info);
		info->map[info->player_row][info->player_col] = 'P';
		print_up(info, mlx, mlx->img);
}

//****************************************************************
//****************************************************************

void	move_down(t_info *info, t_window *mlx)
{
	if (info->on_exit == 1)
		exit_position_update_and_print(info, mlx);
	else
		floor_position_update_and_print(info, mlx);
	if (info->player_row < info->row_max
		&& info->map[info->player_row + 1][info->player_col] != '1')
	{
		info->on_exit = 0;
		if (info->map[info->player_row + 1][info->player_col] == 'C')
		{
			info->owned_tokens++;
			print_exit(info, mlx, mlx->img);
		}
		if (info->map[info->player_row + 1][info->player_col] == 'E')
		{
			info->on_exit = 1;
			if (info->owned_tokens == info->tokens)
				close_game(mlx);
		}
		info->player_row++;
		printf("Number of moves: %d\n", ++info->move_count);
	}
		update_moving(info);
		info->map[info->player_row][info->player_col] = 'P';
		print_down(info, mlx, mlx->img);
}


//****************************************************************
//****************************************************************

int	key_hook(int keycode, t_window *mlx)
{
	if (keycode == 65307)
		close_game(mlx);
	if (keycode == 97 || keycode == 65361)
		move_left(&mlx->info, mlx);
	if (keycode == 100 || keycode == 65363)
		move_right(&mlx->info, mlx);
	if (keycode == 119 || keycode == 65362)
		move_up(&mlx->info, mlx);
	if (keycode == 115 || keycode == 65364)
		move_down(&mlx->info, mlx);
	//printf("Hello from key_hook! : %d\n", keycode);
	
	return (0);
}

//****************************************************************
//****************************************************************

int	main(int argc, char *argv[])
{
	//t_info	info;
	//int		i;
	
	
	t_window	mlx;
	//void	*mlx;
	//void	*mlx_win;
	
	
	//t_img	img;

	if (argc > 2)
		return (printf("Too many arguments\n"), 1);
	if (argc < 2)
		return (printf("Too few arguments\n"), 1);
	if (!extension_valid(argv[1]))
		return (1);
	if(!row_counter(argv[1], &mlx.info) || mlx.info.row_max < 3)
		return (printf("Invalid map\n"), 1);
	dump_map(argv[1], &mlx.info);
	map_transformer(&mlx.info);
	
	ff_dump_map(argv[1], &mlx.info);
	ff_map_transformer(&mlx.info);
	
	//print_map(&mlx.info);
	//printf("valid: %d\n", map_check(&mlx.info));
	if (!map_check(&mlx.info))
		return (free_map(&mlx), 1);
	//printf("token count: %d\n", mlx.info.tokens);

	play_stats_init(&mlx.info);
	
	mlx.mlx = mlx_init();
	mlx.mlx_win = mlx_new_window(mlx.mlx,
		mlx.info.col_max * 64, mlx.info.row_max * 64, "Pokemon Silver");
	load_all_sprites(&mlx.img, mlx.mlx);
	map_to_window(mlx.mlx, mlx.mlx_win, mlx.info, mlx.img);
	mlx_key_hook(mlx.mlx_win, key_hook, &mlx);
	mlx_hook(mlx.mlx_win, 17, 0, close_game, &mlx);
	mlx_loop(mlx.mlx);
}
