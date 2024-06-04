#ifndef PHILO_H
# define PHILO_H

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

typedef pthread_mutex_t t_mtx;

typedef enum	t_status{
	EATING,
	THINKING,
	SLEEPING,
	STARVING,
	DEAD
}	status;

typedef	struct s_fork
{
	t_mtx	fork;
	int		fork_id;
}	t_fork;

typedef struct s_philosopher_thread{
	int	id;
	status state;
	int time_to_die;
	int time_to_eat;
	int time_to_sleep;

	t_fork	*left_fork;
	t_fork	*right_fork;

	long	last_meal_time;
	long	meals_count;
}	t_philosopher_thread;

typedef struct s_philo_data{
	int number_of_philosophers;
	int time_to_die;
	int time_to_eat;
	int time_to_sleep;
	int number_of_times_each_philosopher_must_eat;
	t_philosopher_thread **philosopher_threads;
}   t_philo_data;

// Utils.
int		ft_atoi(const char *str);
void	print_error(char *err_msg, int should_exit);
void	threads_wait(pthread_t *philosophers, int philosophers_count);

// == philosophers ================
void *philosopher_life(void *data);
t_philosopher_thread *new_philosopher(int id);
void create_threads(t_philo_data *philo_data);
void init_philosophers_list(t_philo_data *philo_data);
void *philosopher_life(void *data);

// == inits =======================
void init_mutexes(pthread_mutex_t *forks_mutexes, int forks_count);
void init_threads(t_philo_data *philo_data, pthread_t *philosophers, int philosophers_count);

#endif
