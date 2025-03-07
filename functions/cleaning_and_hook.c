/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning_and_hook.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgalean <asgalean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 18:43:42 by asgalean          #+#    #+#             */
/*   Updated: 2025/03/07 18:43:44 by asgalean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	key_hook(int keycode, t_window *mlx)
{
	if (keycode == 65307)
		close_game(mlx);
	if (keycode == 97 || keycode == 65361)
		move_left(&mlx->info, mlx);
	if (keycode == 100 || keycode == 65363)
		move_right(&mlx->info, mlx);
	if (keycode == 119 || keycode == 65362)
		move_up(&mlx->info, mlx);
	if (keycode == 115 || keycode == 65364)
		move_down(&mlx->info, mlx);
	if ((mlx->info.owned_tokens * 100) / mlx->info.tokens == 100)
		birb_fly(mlx, &mlx->info, mlx->img);
	return (0);
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

void	free_map(t_window *mlx)
{
	int	i;

	i = 0;
	while (mlx->info.map[i])
	{
		free(mlx->info.map[i]);
		i++;
	}
	free(mlx->info.map);
}

//****************************************************************
//****************************************************************


void	free_images(t_window *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->img.p_idle);
	mlx_destroy_image(mlx->mlx, mlx->img.p_up_1);
	mlx_destroy_image(mlx->mlx, mlx->img.p_up_2);
	mlx_destroy_image(mlx->mlx, mlx->img.p_down_1);
	mlx_destroy_image(mlx->mlx, mlx->img.p_down_2);
	mlx_destroy_image(mlx->mlx, mlx->img.p_left_1);
	mlx_destroy_image(mlx->mlx, mlx->img.p_left_2);
	mlx_destroy_image(mlx->mlx, mlx->img.p_right_1);
	mlx_destroy_image(mlx->mlx, mlx->img.p_right_2);
	mlx_destroy_image(mlx->mlx, mlx->img.floor);
	mlx_destroy_image(mlx->mlx, mlx->img.wall);
	mlx_destroy_image(mlx->mlx, mlx->img.coin);
	mlx_destroy_image(mlx->mlx, mlx->img.exit_0);
	mlx_destroy_image(mlx->mlx, mlx->img.exit_25);
	mlx_destroy_image(mlx->mlx, mlx->img.exit_50);
	mlx_destroy_image(mlx->mlx, mlx->img.exit_75);
	mlx_destroy_image(mlx->mlx, mlx->img.exit_100);
	mlx_destroy_image(mlx->mlx, mlx->img.exit_100_2);
}

//****************************************************************
//****************************************************************

int	close_game(t_window *mlx)
{
	free_images(mlx);
	free_map(mlx);
	mlx_destroy_window(mlx->mlx, mlx->mlx_win);
	mlx_destroy_display(mlx->mlx);
	free(mlx->mlx);
	exit(1);
}
