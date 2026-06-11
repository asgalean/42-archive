/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgalean <asgalean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 18:02:48 by asgalean          #+#    #+#             */
/*   Updated: 2025/08/22 18:02:50 by asgalean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	all_alone_by_myself(t_parameters parameters)
{
	printf("0ms\tPhilo 0: has TAKEN his fork\n");
	usleep(parameters.t_to_die * 1000);
	printf("%dms\tPhilo 0: DIED\n", parameters.t_to_die + 1);
}

//******************************************************************************
//******************************************************************************

void	*routine(void *arg) //delay between odd and even to not overlap
{
	t_philo			*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		usleep(philo->params->philo_total);
	else
		usleep(philo->params->philo_total * 100);
	while (1)
	{
		if (grab_my_fork(philo) < 0)
			return (NULL);
		if (grab_next_fork(philo) < 0)
			return (NULL);
		if (p_eat(philo) < 0)
			return (NULL);
		if (p_sleep(philo) < 0)
			return (NULL);
		if (p_think(philo) < 0)
			return (NULL);
	}
}

//******************************************************************************
//******************************************************************************

int	main(int argc, char *argv[])
{
	t_parameters	parameters;
	t_philo			*philo;
	struct timeval	current_time;

	if (argc != 5 && argc != 6)
		return (printf("Invalid parameter count\n"));
	if (!check_params(argc, argv))
		return (printf("Invalid input\n"));
	if (get_params(&parameters, argc, argv) == 1)
		return (all_alone_by_myself(parameters), 0);
	philo = (t_philo *)malloc(sizeof(t_philo));
	create_table(philo, &parameters);
	while (1)
	{
		gettimeofday(&current_time, NULL);
		if (philo_died(philo, current_time) < 0)
			break ;
		parameters.philo_eaten_count = 0;
		if (argc == 6 && all_eaten(philo, current_time) < 0)
			break ;
		philo = philo->next;
	}
	usleep(100);
	free_table(philo, &parameters);
	return (0);
}
