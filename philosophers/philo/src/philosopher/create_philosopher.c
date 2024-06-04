#include "../../includes/philo.h"

t_philosopher_thread *new_philosopher(int id)
{
	t_philosopher_thread *new_philosopher = malloc(sizeof(t_philosopher_thread));
	if (!new_philosopher)
		return (NULL);
	new_philosopher->id = id;
	new_philosopher->state = THINKING;
	return (new_philosopher);
}

void create_threads(t_philo_data *philo_data)
{
	int i = 0;
	static int uuid = 1;
	t_philosopher_thread *curr_philo;

	while (i < philo_data->number_of_philosophers)
	{
		curr_philo = new_philosopher(uuid++);
		philo_data->philosopher_threads[i] = curr_philo;
		i++;
	}
}

void init_philosophers_list(t_philo_data *philo_data)
{
	int	philos_count;

	philos_count = philo_data->number_of_philosophers;
	t_philosopher_thread **philosophers_threads;
	
	philosophers_threads = malloc(sizeof(t_philo_data) * philos_count);
	philosophers_threads[philos_count] = NULL;
	philo_data->philosopher_threads = philosophers_threads;
}