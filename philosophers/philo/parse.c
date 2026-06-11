/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgalean <asgalean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 18:02:57 by asgalean          #+#    #+#             */
/*   Updated: 2025/08/22 18:42:42 by asgalean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_params(t_parameters *parameters, int argc, char *argv[])
{
	parameters->ongoing = 1;
	parameters->philo_total = pseudo_atoi(argv[1]);
	parameters->t_to_die = pseudo_atoi(argv[2]);
	parameters->t_to_eat = pseudo_atoi(argv[3]);
	parameters->t_to_sleep = pseudo_atoi(argv[4]);
	pthread_mutex_init(&(parameters->print_mutex), NULL);
	pthread_mutex_init(&(parameters->eat_mutex), NULL);
	gettimeofday(&(parameters->start_time), NULL);
	if (argc == 6)
		parameters->max_eaten = pseudo_atoi(argv[5]);
	else
		parameters->max_eaten = -1;
	parameters->philo_eaten_count = 0;
	return (parameters->philo_total);
}

//******************************************************************************
//******************************************************************************

int	check_params(int argc, char *argv[])
{
	int	i;

	i = 1;
	if (pseudo_atoi(argv[1]) == 0)
		return (0);
	while (i < argc)
	{
		if (!num_check(argv[i]))
			return (0);
		if (pseudo_atoi(argv[i]) < 0)
			return (0);
		i++;
	}
	return (623);
}

//******************************************************************************
//******************************************************************************

int	num_check(char *str)
{
	int	i;

	i = 0;
	while (i < ft_strlen(str))
	{
		if (str[i] > '9' || str[i] < '0')
			return (0);
		i++;
	}
	return (623);
}

//******************************************************************************
//******************************************************************************

int	pseudo_atoi(char *number)
{
	long long	n;
	int			i;

	i = 0;
	n = 0;
	while (number[i] != '\0')
	{
		n = n * 10 + (number[i] - '0');
		i++;
	}
	if (n > 2147483647 || n < -2147483648)
		return (-623);
	return (n);
}

//******************************************************************************
//******************************************************************************

int	ft_strlen(char *string)
{
	int	i;

	i = 0;
	while (string[i])
		i++;
	return (i);
}
