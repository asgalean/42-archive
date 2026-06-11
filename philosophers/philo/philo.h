/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgalean <asgalean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 18:03:04 by asgalean          #+#    #+#             */
/*   Updated: 2025/08/22 18:03:05 by asgalean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>

typedef struct s_parameters
{
	int				ongoing;
	int				philo_total;
	int				t_to_die;
	int				t_to_eat;
	int				t_to_sleep;
	int				max_eaten;
	int				philo_eaten_count;
	struct timeval	start_time;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	eat_mutex;
}	t_parameters;

typedef struct s_philo
{
	int					id;
	pthread_t			thread;
	pthread_mutex_t		fork;
	int					prev_meal; //esto va a ser un timepo (osea, date)
	int					eaten_count;
	struct s_parameters	*params;
	struct s_philo		*next;
}	t_philo;

//main.c
int		main(int argc, char *argv[]);
void	*routine(void *arg);

//routine.c
int		grab_my_fork(t_philo *philo);
int		grab_next_fork(t_philo *philo);
int		p_eat(t_philo *philo);
int		p_sleep(t_philo *philo);
int		p_think(t_philo *philo);

//routine_checks.c
int		philo_died(t_philo *p_philo, struct timeval current_time);
int		all_eaten(t_philo *p_philo, struct timeval current_time);

//table.c
void	free_table(t_philo *philo, t_parameters *parameters);
void	init_table(t_philo *philo);
void	create_table(t_philo *philo, t_parameters *parameters);

//parse.c
int		ft_strlen(char *string);
int		pseudo_atoi(char *number);
int		num_check(char *str);
int		check_params(int argc, char *argv[]);
int		get_params(t_parameters *parameters, int argc, char *argv[]);

#endif
