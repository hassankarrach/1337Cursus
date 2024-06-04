#include "../../includes/philo.h"

void init_mutexes(pthread_mutex_t *forks_mutexes, int forks_count)
{
	int i = 0;
	while (i < forks_count)
	{
		if (pthread_mutex_init(&forks_mutexes[i], NULL) != 0)
			print_error("error initializing a mutex.", 1);
		i++;
	}
}

void init_threads(t_philo_data *philo_data, pthread_t *philosophers, int philosophers_count)
{
	int i = 0;

	while (i < philosophers_count)
	{
		if (pthread_create(&philosophers[i], NULL, philosopher_life, (void *)philo_data->philosopher_threads[i]) != 0)
			print_error("error initializing a thread.", 1);
		i++;
	}
}

