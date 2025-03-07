/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgalean <asgalean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 18:42:37 by asgalean          #+#    #+#             */
/*   Updated: 2025/03/07 18:42:40 by asgalean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	input_check(int arg_num, char *route)
{
	if (arg_num > 2)
		return (ft_printf("Too many arguments\n"), 0);
	if (arg_num < 2)
		return (ft_printf("Too few arguments\n"), 0);
	if (!extension_valid(route))
		return (0);
	return (1);
}

//****************************************************************
//****************************************************************

int	extension_valid(char *file_name)
{
	int	i;

	i = ft_strlen(file_name);
	if (file_name[i - 1] == 'r' && file_name[i - 2] == 'e'
		&& file_name[i - 3] == 'b' && file_name[i - 4] == '.')
		return (1);
	return (ft_printf("Invalid extension\n"), 0);
}

//****************************************************************
//****************************************************************

int	fd_check(int fd)
{
	if (fd < 0)
		return (ft_printf("Error while opening file\n"), 0);
	return (1);
}
