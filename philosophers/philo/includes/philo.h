#ifndef PHILO_H
# define PHILO_H

#include <pthread.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <stdint.h>
#include <sys/time.h>

// typedef enum	e_status{
// 	EATING,
// 	THINKING,
// 	SLEEPING,
// 	STARVING,
// 	DEAD
// };
// typedef enum	e_fork
// {
// 	LEFT,
// 	RIGHT
// };

typedef struct s_philosopher_thread{
	int		id; //philosopher number

	pthread_mutex_t	left_fork;	//The philosophers own fork.
	pthread_mutex_t	*right_fork; //The other fork he will need.

	uint64_t	last_meal_time;
	long		meals_count;

	pthread_t		thread;

	struct s_program *t_prog;
}	t_philosopher_thread;

typedef struct s_program{
	int						number_of_philosophers;

	u_int64_t				start_time;

	int 					time_2_die;
	int 					time_2_eat;
	int 					time_2_sleep;

	//flags
	int						death_occured; //A flag if a philosopher happend to die.
	int						everybody_full; // A flag if all philos are finished.

	int						total_finished; // a total of finished philos
	int 					max_meals; //optional

	pthread_mutex_t			sync_mutex; // Mutex for synchronizing access to shared variables
	t_philosopher_thread	philosopher_threads[200];
}   t_program;


// Parsing.
void					is_only_numbers(char **av);

// Utils.
int						ft_atoi(const char *str);
int						print_error(char *err_msg, int should_exit);
u_int64_t				get_time(void);
int						ft_usleep(useconds_t time);

// philosophers.
void					*philosopher_life(void *data);

// inits.
void 					init_mutexes(pthread_mutex_t *forks_mutexes, int forks_count);
void 					init_threads(t_program *philo_data, pthread_t *philosophers, int philosophers_count);

#endif
