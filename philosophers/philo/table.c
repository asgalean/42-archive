/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgalean <asgalean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 18:03:38 by asgalean          #+#    #+#             */
/*   Updated: 2025/08/22 18:03:41 by asgalean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_table(t_philo *philo, t_parameters *parameters)
{
	int		i;
	t_philo	*old;

	i = 0;
	while (i < parameters->philo_total)
	{
		pthread_join(philo->thread, NULL);
		philo = philo->next;
		i++;
	}
	i = 0;
	while (i < parameters->philo_total)
	{
		old = philo;
		pthread_mutex_destroy(&(philo->fork));
		if (i != parameters->philo_total - 1)
			philo = philo->next;
		free(old);
		i++;
	}
	pthread_mutex_destroy(&(parameters->print_mutex));
	pthread_mutex_destroy(&(parameters->eat_mutex));
}

//******************************************************************************
//******************************************************************************

void	init_table(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->params->philo_total)
	{
		pthread_create(&(philo->thread), NULL, &routine, philo);
		philo = philo->next;
		i++;
	}
}

//******************************************************************************
//******************************************************************************

void	create_table(t_philo *philo, t_parameters *parameters)
{
	int		i;
	t_philo	*new;
	t_philo	*og;

	i = 0;
	og = philo;
	while (i < parameters->philo_total)
	{
		philo->params = parameters;
		philo->id = i;
		philo->eaten_count = 0;
		philo->prev_meal = 0;
		pthread_mutex_init(&(philo->fork), NULL);
		if (i != parameters->philo_total - 1)
		{
			new = (t_philo *)malloc(sizeof(t_philo));
			philo->next = new;
			philo = philo->next;
		}
		i++;
	}
	philo->next = og;
	init_table(philo);
}
