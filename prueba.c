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
	if (file_name[i-1] == 'r' && file_name[i-2] == 'e'
		&& file_name[i-3] == 'b' && file_name[i-4] == '.')
		return (1);
	return (printf("Invalid extension"), 0);
}

//****************************************************************
//****************************************************************

int	fd_check(int fd)
{
	if (fd < 0)
		return (printf("Error while opening file"), 0);
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
	info->map[row][col] = 'X';
	if (row >= 0 && info->map[row - 1][col] != '1' && info->map[row - 1][col] != 'X')
		floodfill(info, row - 1, col);
	if (col >= 0 && info->map[row][col - 1] != '1' && info->map[row][col - 1] != 'X')
		floodfill(info, row, col - 1);
	if (row <= info->row_max - 1 && info->map[row + 1][col] != '1'
		&& info->map[row + 1][col] != 'X')
		floodfill(info, row + 1, col);
	if (col <= info->col_max - 1 && info->map[row][col + 1] != '1'
		&& info->map[row][col + 1] != 'X')
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
		return (printf("Size not valid\n"), 0);
	if (!is_good_map(info))
		return (0);
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

int	main(int argc, char *argv[])
{
	t_info	info;
	int		i;

	if (argc > 2)
		return (printf("Too many arguments\n"), 1);
	if (argc < 2)
		return (printf("Too few arguments\n"), 1);
	if (!extension_valid(argv[1]))
		return (1);
	if(!row_counter(argv[1], &info))
		return (1);
	dump_map(argv[1], &info);
	map_transformer(&info);
	
	ff_dump_map(argv[1], &info);
	ff_map_transformer(&info);
	
	print_map(&info);
	printf("valid: %d\n", map_check(&info));
	printf("token count: %d\n", info.tokens);


	i = 0;
	while (info.map[i])
	{
		free(info.map[i]);
		i++;
	}
	free(info.map);

/*
	int	i;
	int	fd;
	int	rows;
	char	*line;
*/
	/*
	rows = 0;
	fd = open("puto_mapa", O_RDONLY);
	line = get_next_line(fd);
	while(line)
	{
		free(line);
		line = get_next_line(fd);
		rows++;
		printf("%d\n", rows);
	}
	close(fd);
	free(line);
	*/
	//printf("_______\n_______");********************************************

	/*
	map = (char **)malloc(sizeof(char *) * (rows + 1));
	map[rows] = 0;

	fd = open("puto_mapa", O_RDONLY);

	i = 0;
	while(i < rows)
	{
		map[i] = get_next_line(fd);
		printf("%s", map[i]);
		i++;
	}

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	close(fd);
	*/
}
