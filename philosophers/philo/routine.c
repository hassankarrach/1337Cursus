#include "philo.h"

static int simulation_should_end(t_prog *args)
{
    int should_end;

    pthread_mutex_lock(&args->death_lock);
    should_end = args->death_alert || args->evrybody_full;
    pthread_mutex_unlock(&args->death_lock);
    return (should_end);
}
void put_message(t_philo *philo, char *msg)
{
	pthread_mutex_lock(&philo->args->print_lock);
	printf("%ld %d %s\n", get_time() - philo->args->start_time, philo->id, msg);
	pthread_mutex_unlock(&philo->args->print_lock);
}
static int take_forks(t_philo *philo)
{
    if (simulation_should_end(philo->args))
        return (0);

    pthread_mutex_lock(philo->left_fork);
    if (simulation_should_end(philo->args))
    {
        pthread_mutex_unlock(philo->left_fork);
        return (0);
    }
    put_message(philo, "has taken a fork");

    if (philo->args->number_of_philosophers == 1)
    {
        ft_usleep(philo->args->time_2_die);
        pthread_mutex_unlock(philo->left_fork);
        return (0);
    }

    pthread_mutex_lock(philo->right_fork);
    if (simulation_should_end(philo->args))
    {
        pthread_mutex_unlock(philo->left_fork);
        pthread_mutex_unlock(philo->right_fork);
        return (0);
    }
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
	if (simulation_should_end(philo->args))
		return (0);
	put_message(philo, "is eating");
	philo->last_meal_time = get_time();
	ft_usleep(philo->args->time_2_eat);

	pthread_mutex_lock(&philo->args->meals_lock);
	philo->meals_count++;
	if (philo->args->max_meals != -1 && philo->meals_count >= (size_t)philo->args->max_meals)
		philo->args->finished_philos++;
	pthread_mutex_unlock(&philo->args->meals_lock);

	drop_forks(philo);
	return (1);
}
static int sleap(t_philo *philo)
{
	if (simulation_should_end(philo->args))
		return (0);
	put_message(philo, "is sleeping");
	ft_usleep(philo->args->time_2_sleap);
	return (1);
}
static int think(t_philo *philo)
{
	if (simulation_should_end(philo->args))
		return (0);
	put_message(philo, "is thinking");
	return (1);
}

void *routine(void *ptr)
{
    t_philo *philo;

    philo = (t_philo *)ptr;

    wait_philos(philo->args);
    if (philo->args->max_meals == 0)
        return (NULL);
    
    // Add a small delay based on philosopher ID to improve fairness
    if (philo->id % 2 == 0)
        usleep(15000);

    while (!simulation_should_end(philo->args))
    {
        if (!take_forks(philo))
            break;
        if (!eat(philo))
            break;
        if (!sleap(philo))
            break;
        if (!think(philo))
            break;
    }

    return (NULL);
}