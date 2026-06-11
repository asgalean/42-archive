/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgalean <asgalean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 18:44:11 by asgalean          #+#    #+#             */
/*   Updated: 2025/03/07 18:44:12 by asgalean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	player_exit_pos_get(t_info *info)
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

void	play_stats_init(t_info *info)
{
	info->owned_tokens = 0;
	info->move_count = 0;
	info->on_exit = 0;
	info->moving = 1;
}
