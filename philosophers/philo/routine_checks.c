/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_checks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgalean <asgalean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 18:03:32 by asgalean          #+#    #+#             */
/*   Updated: 2025/08/22 18:03:34 by asgalean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_died(t_philo *p_philo, struct timeval current_time)
{
	pthread_mutex_lock(&(p_philo->params->eat_mutex));
	if (((current_time.tv_sec - p_philo->params->start_time.tv_sec) * 1000
			+ (current_time.tv_usec - p_philo->params->start_time.tv_usec)
			/ 1000) - p_philo->prev_meal > p_philo->params->t_to_die)
	{
		pthread_mutex_unlock(&(p_philo->params->eat_mutex));
		pthread_mutex_lock(&(p_philo->params->print_mutex));
		p_philo->params->ongoing = 0;
		printf("%lums\tPhilo %d: DIED\n",
			(current_time.tv_sec - p_philo->params->start_time.tv_sec) * 1000
			+ (current_time.tv_usec - p_philo->params->start_time.tv_usec)
			/ 1000,
			p_philo->id);
		usleep(10);
		pthread_mutex_unlock(&(p_philo->params->print_mutex));
		return (-623);
	}
	else
		pthread_mutex_unlock(&(p_philo->params->eat_mutex));
	return (623);
}

//******************************************************************************
//******************************************************************************

int	all_eaten(t_philo *p_philo, struct timeval current_time)
{
	int	i;

	i = -1;
	while (++i < p_philo->params->philo_total)
	{
		pthread_mutex_lock(&(p_philo->params->eat_mutex));
		if (p_philo->eaten_count >= p_philo->params->max_eaten)
			p_philo->params->philo_eaten_count++;
		pthread_mutex_unlock(&(p_philo->params->eat_mutex));
		p_philo = p_philo->next;
	}
	if (p_philo->params->philo_eaten_count == p_philo->params->philo_total)
	{
		pthread_mutex_lock(&(p_philo->params->print_mutex));
		p_philo->params->ongoing = 0;
		printf("%lums\tAll philosophers have eaten\n",
			(current_time.tv_sec - p_philo->params->start_time.tv_sec) * 1000
			+ (current_time.tv_usec - p_philo->params->start_time.tv_usec)
			/ 1000);
		usleep(10);
		pthread_mutex_unlock(&(p_philo->params->print_mutex));
		return (-623);
	}
	return (623);
}
