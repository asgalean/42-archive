/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgalean <asgalean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 18:44:41 by asgalean          #+#    #+#             */
/*   Updated: 2025/03/07 18:44:43 by asgalean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	map_and_ff_map_get(char *route, t_info *info)
{
	dump_map(route, info);
	map_transformer(info);
	ff_dump_map(route, info);
	ff_map_transformer(info);
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
		i++;
	}
	close(fd);
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
