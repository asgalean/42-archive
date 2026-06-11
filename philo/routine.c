/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgalean <asgalean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 18:03:21 by asgalean          #+#    #+#             */
/*   Updated: 2025/08/22 18:03:23 by asgalean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	grab_my_fork(t_philo *philo)
{
	struct timeval	current_time;

	pthread_mutex_lock(&(philo->fork));
	gettimeofday(&current_time, NULL);
	pthread_mutex_lock(&(philo->params->print_mutex));
	if (philo->params->ongoing == 0)
		return (pthread_mutex_unlock(&(philo->fork)),
			pthread_mutex_unlock(&(philo->params->print_mutex)), -623);
	printf("%lums\tPhilo %d: has TAKEN his fork\n",
		(current_time.tv_sec - philo->params->start_time.tv_sec) * 1000
		+ (current_time.tv_usec - philo->params->start_time.tv_usec) / 1000,
		philo->id);
	pthread_mutex_unlock(&(philo->params->print_mutex));
	return (623);
}

//******************************************************************************
//******************************************************************************

int	grab_next_fork(t_philo *philo)
{
	struct timeval	current_time;

	pthread_mutex_lock(&(philo->next->fork));
	gettimeofday(&current_time, NULL);
	pthread_mutex_lock(&(philo->params->print_mutex));
	if (philo->params->ongoing == 0)
		return (pthread_mutex_unlock(&(philo->next->fork)),
			pthread_mutex_unlock(&(philo->fork)),
			pthread_mutex_unlock(&(philo->params->print_mutex)), -623);
	printf("%lums\tPhilo %d: has TAKEN the next fork\n",
		(current_time.tv_sec - philo->params->start_time.tv_sec) * 1000
		+ (current_time.tv_usec - philo->params->start_time.tv_usec) / 1000,
		philo->id);
	pthread_mutex_unlock(&(philo->params->print_mutex));
	return (623);
}

//******************************************************************************
//******************************************************************************

int	p_eat(t_philo *philo)
{
	struct timeval	current_time;

	pthread_mutex_lock(&(philo->params->eat_mutex));
	philo->eaten_count++;
	gettimeofday(&current_time, NULL);
	philo->prev_meal = (current_time.tv_sec - philo->params->start_time.tv_sec)
		* 1000
		+ (current_time.tv_usec - philo->params->start_time.tv_usec) / 1000;
	pthread_mutex_unlock(&(philo->params->eat_mutex));
	pthread_mutex_lock(&(philo->params->print_mutex));
	if (philo->params->ongoing == 0)
		return (pthread_mutex_unlock(&(philo->next->fork)),
			pthread_mutex_unlock(&(philo->fork)),
			pthread_mutex_unlock(&(philo->params->print_mutex)), -623);
	printf("%lums\tPhilo %d: is EATING\n",
		(current_time.tv_sec - philo->params->start_time.tv_sec) * 1000
		+ (current_time.tv_usec - philo->params->start_time.tv_usec) / 1000,
		philo->id);
	pthread_mutex_unlock(&(philo->params->print_mutex));
	usleep(philo->params->t_to_eat * 1000);
	pthread_mutex_unlock(&(philo->fork));
	pthread_mutex_unlock(&(philo->next->fork));
	return (623);
}

//******************************************************************************
//******************************************************************************

int	p_sleep(t_philo *philo)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	pthread_mutex_lock(&(philo->params->print_mutex));
	if (philo->params->ongoing == 0)
		return (pthread_mutex_unlock(&(philo->params->print_mutex)), -623);
	printf("%lums\tPhilo %d: is SLEEPING\n",
		(current_time.tv_sec - philo->params->start_time.tv_sec) * 1000
		+ (current_time.tv_usec - philo->params->start_time.tv_usec) / 1000,
		philo->id);
	pthread_mutex_unlock(&(philo->params->print_mutex));
	usleep(philo->params->t_to_sleep * 1000);
	return (623);
}

//******************************************************************************
//******************************************************************************

int	p_think(t_philo *philo)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	pthread_mutex_lock(&(philo->params->print_mutex));
	if (philo->params->ongoing == 0)
		return (pthread_mutex_unlock(&(philo->params->print_mutex)), -623);
	printf("%lums\tPhilo %d: is THIKNING\n",
		(current_time.tv_sec - philo->params->start_time.tv_sec) * 1000
		+ (current_time.tv_usec - philo->params->start_time.tv_usec) / 1000,
		philo->id);
	pthread_mutex_unlock(&(philo->params->print_mutex));
	return (623);
}
