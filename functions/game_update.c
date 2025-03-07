/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_update.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgalean <asgalean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 18:44:17 by asgalean          #+#    #+#             */
/*   Updated: 2025/03/07 18:44:18 by asgalean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
