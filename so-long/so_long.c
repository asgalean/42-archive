/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgalean <asgalean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 15:11:35 by asgalean          #+#    #+#             */
/*   Updated: 2025/03/07 15:11:37 by asgalean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_window	mlx;

	if (!input_check(argc, argv[1]))
		return (1);
	if (!row_counter(argv[1], &mlx.info) || mlx.info.row_max < 3)
		return (ft_printf("Invalid map\n"), 1);
	map_and_ff_map_get(argv[1], &mlx.info);
	if (!map_check(&mlx.info))
		return (free_map(&mlx), 1);
	play_stats_init(&mlx.info);
	mlx.mlx = mlx_init();
	mlx.mlx_win = mlx_new_window(mlx.mlx,
			mlx.info.col_max * 64, mlx.info.row_max * 64, "Pokemon Silver");
	load_all_sprites(&mlx.img, mlx.mlx);
	map_to_window(mlx.mlx, mlx.mlx_win, mlx.info, mlx.img);
	mlx_key_hook(mlx.mlx_win, key_hook, &mlx);
	mlx_hook(mlx.mlx_win, 17, 0, close_game, &mlx);
	mlx_loop(mlx.mlx);
}
