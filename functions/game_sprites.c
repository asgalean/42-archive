/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgalean <asgalean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 18:43:53 by asgalean          #+#    #+#             */
/*   Updated: 2025/03/07 18:43:55 by asgalean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	load_map_sprites(t_img *img, void *mlx)
{
	img->floor = mlx_xpm_file_to_image(mlx, "textures/ground.xpm",
			&img->width, &img->height);
	img->wall = mlx_xpm_file_to_image(mlx, "textures/wall1.xpm",
			&img->width, &img->height);
	img->coin = mlx_xpm_file_to_image(mlx, "textures/collectable.xpm",
			&img->width, &img->height);
	img->exit_0 = mlx_xpm_file_to_image(mlx, "textures/exit_0.xpm",
			&img->width, &img->height);
	img->exit_25 = mlx_xpm_file_to_image(mlx, "textures/exit_25.xpm",
			&img->width, &img->height);
	img->exit_50 = mlx_xpm_file_to_image(mlx, "textures/exit_50.xpm",
			&img->width, &img->height);
	img->exit_75 = mlx_xpm_file_to_image(mlx, "textures/exit_75.xpm",
			&img->width, &img->height);
	img->exit_100 = mlx_xpm_file_to_image(mlx, "textures/exit_100.xpm",
			&img->width, &img->height);
	img->exit_100_2 = mlx_xpm_file_to_image(mlx, "textures/exit_100_2.xpm",
			&img->width, &img->height);
}

//****************************************************************
//****************************************************************

void	load_player_sprites(t_img *img, void *mlx)
{
	img->p_idle = mlx_xpm_file_to_image(mlx, "textures/gold_down_idle.xpm",
			&img->width, &img->height);
	img->p_up_1 = mlx_xpm_file_to_image(mlx, "textures/gold_up1.xpm",
			&img->width, &img->height);
	img->p_up_2 = mlx_xpm_file_to_image(mlx, "textures/gold_up2.xpm",
			&img->width, &img->height);
	img->p_down_1 = mlx_xpm_file_to_image(mlx, "textures/gold_down1.xpm",
			&img->width, &img->height);
	img->p_down_2 = mlx_xpm_file_to_image(mlx, "textures/gold_down2.xpm",
			&img->width, &img->height);
	img->p_left_1 = mlx_xpm_file_to_image(mlx, "textures/gold_left.xpm",
			&img->width, &img->height);
	img->p_left_2 = mlx_xpm_file_to_image(mlx, "textures/gold_left2.xpm",
			&img->width, &img->height);
	img->p_right_1 = mlx_xpm_file_to_image(mlx, "textures/gold_right.xpm",
			&img->width, &img->height);
	img->p_right_2 = mlx_xpm_file_to_image(mlx, "textures/gold_right2.xpm",
			&img->width, &img->height);
}

//****************************************************************
//****************************************************************

void	load_all_sprites(t_img *img, void *mlx)
{
	load_player_sprites(img, mlx);
	load_map_sprites(img, mlx);
}
