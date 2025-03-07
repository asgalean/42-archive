/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgalean <asgalean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 18:44:06 by asgalean          #+#    #+#             */
/*   Updated: 2025/03/07 18:44:07 by asgalean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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

int	check_objects(t_info *info)
{
	if (!player_exit_number(info))
		return (0);
	if (info->tokens == 0)
		return (ft_printf("There are no collectables\n"), 0);
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
		return (ft_printf("Borders not legal\n"), 0);
	if (!check_tiles(info))
		return (ft_printf("Tiles not valid\n"), 0);
	if (!check_objects(info))
		return (0);
	return (1);
}
