/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tiles.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgalean <asgalean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 18:44:23 by asgalean          #+#    #+#             */
/*   Updated: 2025/03/07 18:44:23 by asgalean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	print_floor(t_info *info, t_window *mlx, t_img img)
{
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, img.floor,
		info->player_col * 64, info->player_row * 64);
}

//****************************************************************
//****************************************************************

void	print_exit(t_info *info, t_window *mlx, t_img img)
{
	if ((info->owned_tokens * 100) / info->tokens < 25)
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, img.exit_0,
			info->exit_col * 64, info->exit_row * 64);
	else if ((info->owned_tokens * 100) / info->tokens < 50)
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, img.exit_25,
			info->exit_col * 64, info->exit_row * 64);
	else if ((info->owned_tokens * 100) / info->tokens < 75)
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, img.exit_50,
			info->exit_col * 64, info->exit_row * 64);
	else if ((info->owned_tokens * 100) / info->tokens < 100)
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, img.exit_75,
			info->exit_col * 64, info->exit_row * 64);
	else if ((info->owned_tokens * 100) / info->tokens == 100)
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, img.exit_100,
			info->exit_col * 64, info->exit_row * 64);
}

//****************************************************************
//****************************************************************

void	map_to_window(void *mlx, void *mlx_win, t_info info, t_img img)
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

void	birb_fly(t_window *mlx, t_info *info, t_img img)
{
	static int	i = 1;

	if (info->on_exit == 1)
		return ;
	if (i == 1)
	{
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, img.exit_100,
			info->exit_col * 64, info->exit_row * 64);
		i = 2;
	}
	else if (i == 2)
	{
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, img.exit_100_2,
			info->exit_col * 64, info->exit_row * 64);
		i = 1;
	}
}
