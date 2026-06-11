/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_and_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgalean <asgalean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 12:11:07 by asgalean          #+#    #+#             */
/*   Updated: 2025/05/01 13:39:51 by asgalean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

//******************************************************************************
//******************************************************************************

int	simple_atoi(char *number)
{
	int	n;
	int	i;
	int	sign;

	sign = 1;
	i = 0;
	n = 0;
	if (number[0] == '-')
	{
		sign = -1;
		i++;
	}
	if (number[0] == '+')
		i++;
	while (number[i] != '\0')
	{
		n = n * 10 + (number[i] - '0');
		i++;
	}
	n = sign * n;
	return (n);
}

//******************************************************************************
//******************************************************************************

int	pseudo_atoi(char *number, int *is_int)
{
	long long	n;
	int			i;
	int			sign;

	sign = 1;
	i = 0;
	n = 0;
	if (number[0] == '-')
	{
		sign = -1;
		i++;
	}
	if (number[0] == '+')
		i++;
	while (number[i] != '\0')
	{
		n = n * 10 + (number[i] - '0');
		i++;
	}
	n = sign * n;
	if (n < -2147483648 || n > 2147483647)
		return (*is_int = 0, 0);
	return (n);
}

//******************************************************************************
//******************************************************************************

int	parse_string(char *input)
{
	int		i;
	char	**input_matrix;

	i = 0;
	while (input[i] == ' ' || (input[i] <= 13 && input[i] >= 7))
		i++;
	if (input[i] == '\0')
		return (ft_printf("Error\n"), 0);
	input_matrix = ft_split(input, ' ');
	while (input_matrix[i])
	{
		if (!is_valid_number(input_matrix[i]))
		{
			free_matrix(input_matrix);
			return (ft_printf("Error\n"), 0);
		}
		i++;
	}
	free_matrix(input_matrix);
	return (1);
}

//******************************************************************************
//******************************************************************************

int	parse_inputs(int argc, char **inputs)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!is_valid_number(inputs[i]))
			return (ft_printf("Error\n"), 0);
		i++;
	}
	return (1);
}
