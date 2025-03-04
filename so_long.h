/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgalean <asgalean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 11:36:14 by asgalean          #+#    #+#             */
/*   Updated: 2025/02/25 12:41:05 by asgalean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <mlx.h>

//updatear el huevo cada vez que se coge una moneda

typedef struct s_info
{
	char	**map;
	int		row_max;
	int		col_max;
	
	int		tokens;
	
	int		ff_tokens;
	int		can_reach_exit;

	char	**ff_map;
	
	int		player_row;
	int		player_col;
	int		exit_row;
	int		exit_col;
	
	int		owned_tokens;
	int		move_count;
	int		on_exit;
	int		moving;
	
}		t_info;

typedef struct s_img
{
	void	*p_idle;
	void	*p_up_1;
	void	*p_up_2;
	void	*p_down_1;
	void	*p_down_2;
	void	*p_left;
	void	*p_right;
	void	*floor;
	void	*wall;
	void	*coin;
	void	*exit_0;
	void	*exit_25;
	void	*exit_50;
	void	*exit_75;
	void	*exit_100;
	int		width;
	int		height;
	
}	t_img;

typedef	struct s_window
{
	void	*mlx;
	void	*mlx_win;
	t_img	img;
	t_info	info;
	int		img_width;
	int		img_height;
	int		win_width;
	int		win_height;
	
}		t_window;


