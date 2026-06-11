/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_player_movement.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgalean <asgalean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 18:44:34 by asgalean          #+#    #+#             */
/*   Updated: 2025/03/07 18:44:34 by asgalean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
		ft_printf("Number of moves: %d\n", ++info->move_count);
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
		ft_printf("Number of moves: %d\n", ++info->move_count);
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
		ft_printf("Number of moves: %d\n", ++info->move_count);
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
		ft_printf("Number of moves: %d\n", ++info->move_count);
	}
	update_moving(info);
	info->map[info->player_row][info->player_col] = 'P';
	print_down(info, mlx, mlx->img);
}
