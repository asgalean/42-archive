/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgalean <asgalean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 18:44:01 by asgalean          #+#    #+#             */
/*   Updated: 2025/03/07 18:44:02 by asgalean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
