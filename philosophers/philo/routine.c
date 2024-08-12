#include "philo.h"

void put_message(t_philo *philo, char *msg)
{
	pthread_mutex_lock(&philo->args->print_lock);
	printf("%ld %d %s\n", get_time() - philo->args->start_time, philo->id, msg);
	pthread_mutex_unlock(&philo->args->print_lock);
}

static int take_forks(t_philo *philo)
{
	pthread_mutex_t *first_fork;
	pthread_mutex_t *second_fork;

	if (philo->id % 2 == 0)
	{
		first_fork = philo->right_fork;
		second_fork = philo->left_fork;
	}
	else
	{
		first_fork = philo->left_fork;
		second_fork = philo->right_fork;
	}
	pthread_mutex_lock(first_fork);
	put_message(philo, "has taken a fork");
	if (philo->args->number_of_philosophers == 1)
	{
		ft_usleep(philo->args->time_2_die);
		pthread_mutex_unlock(first_fork); // unlock the fork, should be??
		return (0);
	}

	pthread_mutex_lock(second_fork);
	put_message(philo, "has taken a fork");

	return (1);
}
static void drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}
static int eat(t_philo *philo)
{
	put_message(philo, "is eating");
	philo->last_meal_time = get_time();
	ft_usleep(philo->args->time_2_eat);
	philo->meals_count++;

	pthread_mutex_lock(&philo->args->meals_lock);
	if (philo->args->max_meals != -1 && philo->meals_count >= philo->args->max_meals)
		philo->args->finished_philos++;
	pthread_mutex_unlock(&philo->args->meals_lock);

	drop_forks(philo);
	return (1);
}
static int sleap(t_philo *philo)
{
	put_message(philo, "is sleeping");
	ft_usleep(philo->args->time_2_sleap);
	return (1);
}
static int think(t_philo *philo)
{
	put_message(philo, "is thinking");
	return (1);
}

void *routine(void *ptr)
{
	t_philo *philo;

	philo = (t_philo *)ptr;

	while (1)
	{
		if (philo->args->death_alert || philo->args->evrybody_full)
			break;

		if (!take_forks(philo))
			break;
		eat(philo);
		sleap(philo);
		think(philo);
	}

	return (NULL);
}