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
    if (msg[0] == 'd' || !simulation_should_end(philo->args))
	    printf("%ld %d %s\n", get_time() - philo->args->start_time, philo->id, msg);
	pthread_mutex_unlock(&philo->args->print_lock);
}
static int take_forks(t_philo *philo, pthread_mutex_t *first_fork, pthread_mutex_t *second_fork)
{
    if (simulation_should_end(philo->args))
        return (0);

    pthread_mutex_lock(first_fork);
    if (simulation_should_end(philo->args))
    {
        pthread_mutex_unlock(first_fork);
        return (0);
    }
    put_message(philo, "has taken a fork");

    if (philo->args->number_of_philosophers == 1)
    {
        ft_usleep(philo->args->time_2_die);
        pthread_mutex_unlock(first_fork);
        return (0);
    }
    pthread_mutex_lock(second_fork);    
    if (simulation_should_end(philo->args))
    {
        pthread_mutex_unlock(first_fork);
        pthread_mutex_unlock(second_fork);
        return (0);
    }
    put_message(philo, "has taken a fork");

    return (1);
}
static void drop_forks(pthread_mutex_t *first_fork, pthread_mutex_t *second_fork)
{
	pthread_mutex_unlock(first_fork);
	pthread_mutex_unlock(second_fork);
}
static int eat(t_philo *philo)
{
	if (simulation_should_end(philo->args))
		return (0);
	put_message(philo, "is eating");
    pthread_mutex_lock(&philo->philo_mutex);
	philo->last_meal_time = get_time();
    pthread_mutex_unlock(&philo->philo_mutex);
	ft_usleep(philo->args->time_2_eat);

	pthread_mutex_lock(&philo->args->meals_lock);
	philo->meals_count++;
	if (philo->args->max_meals != -1 && philo->meals_count >= (size_t)philo->args->max_meals)
		philo->args->finished_philos++;
	pthread_mutex_unlock(&philo->args->meals_lock);
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
    pthread_mutex_t *first_fork;
    pthread_mutex_t *second_fork;

    philo = (t_philo *)ptr;
    if (philo->args->max_meals == 0)
        return (NULL);

    if (philo->id % 2 == 0)
    {
        first_fork = philo->left_fork;
        second_fork = philo->right_fork;
    }
    else
    {
        first_fork = philo->right_fork;
        second_fork = philo->left_fork;
    }
    // Add a small delay based on philosopher ID to improve fairness
    if (philo->id % 2 == 0)
        usleep(500);

    while (!simulation_should_end(philo->args))
    {
        if (!take_forks(philo, first_fork, second_fork))
            break;
        if (!eat(philo))
            break;
        drop_forks(first_fork, second_fork);
        if (!sleap(philo))
            break;
        if (!think(philo))
            break;
    }

    return (NULL);
}