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

void	play_stats_init(t_info *info)
{
	info->owned_tokens = 0;
	info->move_count = 0;
	info->on_exit = 0;
	info->moving = 1;
}
