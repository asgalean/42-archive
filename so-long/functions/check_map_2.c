/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgalean <asgalean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 18:44:28 by asgalean          #+#    #+#             */
/*   Updated: 2025/03/07 18:44:29 by asgalean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	map_check(t_info *info)
{
	if (!size_check(info))
	{
		ff_map_free(info);
		return (ft_printf("Size not valid\n"), 0);
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
	}
	close(fd);
	free(line);
	info->row_max = rows;
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
		return (ft_printf("Error in number of players\n"), 0);
	if (exit_count != 1)
		return (ft_printf("Error in number of exits\n"), 0);
	return (1);
}

//****************************************************************
//****************************************************************

void	floodfill(t_info *info, int row, int col)
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
		return (ft_printf("Player can't reach exit\n"), 0);
	if (info->ff_tokens != info->tokens)
		return (ft_printf("Collectable out of bounds\n"), 0);
	return (1);
}
