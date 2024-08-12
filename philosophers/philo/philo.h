#ifndef PHILO_H
#define PHILO_H

#include <pthread.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <stdint.h>
#include <sys/time.h>
#include <stdbool.h>

// Macros
#define TAKE_FORK "has taken a fork";
#define EATING "is eating";
#define SLEEPING "is sleeping";
#define THINKING "is thinking";
#define DIED "died";

typedef struct s_prog t_prog;

typedef struct s_philo
{
	// Philosopher Id
	int id;
	// meals calcs
	long last_meal_time;
	long meals_count;
	bool is_full;
	// Thread struct
	pthread_t thread;
	// args_cpy
	t_prog *args;
	// Philo Mutexs
	pthread_mutex_t *left_fork;
	pthread_mutex_t *right_fork;
	pthread_mutex_t philo_mutex;

} t_philo;
typedef struct s_prog
{
	int number_of_philosophers;
	// save time of program starting.
	long start_time;
	// params
	long time_2_die;
	long time_2_eat;
	long time_2_sleap;
	// ========== Flags
	int death_alert;
	int evrybody_full;
	int finished_philos;
	int max_meals;
	// ==========

	// lockers
	pthread_mutex_t sync_mutex; // not used (yet || useless)
	pthread_mutex_t print_lock;
	pthread_mutex_t death_lock;
	pthread_mutex_t meals_lock;

	t_philo 		*philosopher_threads;
	pthread_mutex_t *forks;
} t_prog;

// Parsing.
void is_only_numbers(char **av);
// Utils.
size_t get_time(void);
int ft_usleep(__useconds_t time);
int print_error(char *err_msg, int should_exit);
long ft_atol(const char *ptr);
void *ft_memset(void *ptr, int value, size_t len);
// Inits.
void init_forks(t_prog *args);
void init_philos(t_prog *args);
// Routine.
void *routine(void *ptr);
void put_message(t_philo *philo, char *msg);
// Actions.
void join_threads(t_prog *args);
// Monitorings.
int is_philo_dead_starving(t_philo *philo);
void monitor_simulation(t_prog *args);


#endif