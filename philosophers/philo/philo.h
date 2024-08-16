/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarrach <hkarrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 08:07:50 by hkarrach          #+#    #+#             */
/*   Updated: 2024/08/15 01:07:54 by hkarrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include <stdint.h>
# include <sys/time.h>
# include <stdbool.h>
# include <limits.h>
# include <stdatomic.h>

# define TAKE_FORK "has taken a fork"
# define EATING "is eating"
# define SLEEPING "is sleeping"
# define THINKING "is thinking"
# define DIED "died"

typedef struct s_prog	t_prog;

typedef struct s_philo
{
	int				id;
	pthread_t		thread;
	atomic_long		last_meal_time;
	atomic_long		meals_count;
	atomic_bool		is_full;
	t_prog			*args;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
}	t_philo;

typedef struct s_prog
{
	long			number_of_philosophers;
	long			time_2_die;
	long			time_2_eat;
	long			time_2_sleap;
	long			max_meals;
	long			start_time;
	atomic_int		death_alert;
	atomic_int		evrybody_full;
	atomic_long		finished_philos;
	atomic_bool		philos_are_ready;
	pthread_mutex_t	table_lock;
	pthread_mutex_t	print_lock;
	t_philo			*philosopher_threads;
	pthread_mutex_t	*forks;
}	t_prog;

// Simulation
void	*routine(void *ptr);
void	put_message(t_philo *philo, char *msg);
int		is_philo_dead_starving(t_philo *philo);
void	monitor_simulation(t_prog *args);
int		simulation_should_end(t_prog *args);
void	exit_simulation(t_prog *args);

// Utils
int		print_error(char *err_msg, int should_exit);
long	ft_atol(const char *nptr);
void	*ft_memset(void *ptr, int value, size_t len);

// Initins
void	init_forks(t_prog *args);
void	init_philos(t_prog *args);

// Actions
int		take_forks(t_philo *philo);
void	drop_forks(t_philo *philo);
int		eat(t_philo *philo);
int		sleap(t_philo *philo);
int		think(t_philo *philo);

// Time management
long	get_time(void);
void	ft_usleep(long time, t_prog *args);

#endif