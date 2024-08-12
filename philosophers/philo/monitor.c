#include "philo.h"

int is_philo_dead_starving(t_philo *philo) // This function will check if a philo is dead due to starvation
{
	size_t curr_time;

	curr_time = get_time();
	pthread_mutex_lock(&philo->args->death_lock);
	if (philo->args->death_alert)
	{
		pthread_mutex_unlock(&philo->args->death_lock);
		return (1);
	}
	pthread_mutex_lock(&philo->philo_mutex);
	if (curr_time - philo->last_meal_time > (size_t)philo->args->time_2_die)
	{
		philo->args->death_alert = 1;
		pthread_mutex_unlock(&philo->args->death_lock);
		pthread_mutex_unlock(&philo->philo_mutex);
		put_message(philo, "died");
		return (1);
	}
	pthread_mutex_unlock(&philo->args->death_lock);
	pthread_mutex_unlock(&philo->philo_mutex);
	return (0);
}

int all_philos_full(t_prog *args) // This function will check if all philos finished their meals
{
	pthread_mutex_lock(&args->meals_lock);
	if (args->max_meals != -1 && args->finished_philos == args->number_of_philosophers)
	{
		args->evrybody_full = 1;
		pthread_mutex_unlock(&args->meals_lock);
		return (1);
	}
	pthread_mutex_unlock(&args->meals_lock);
	return (0);
}


void monitor_simulation(t_prog *args)
{
	int philo_id;

	philo_id = 0;
	while (philo_id < args->number_of_philosophers)
	{
		if (is_philo_dead_starving(&args->philosopher_threads[philo_id]) || all_philos_full(args))
			break;
		philo_id++;
		if (philo_id == args->number_of_philosophers)
			philo_id = 0;
	}
}