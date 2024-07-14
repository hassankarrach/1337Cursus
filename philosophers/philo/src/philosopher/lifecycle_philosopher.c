#include "../../includes/philo.h"

static int	ft_write_status(t_philosopher_thread *philo, char *msg)
{
	pthread_mutex_lock(&philo->t_prog->sync_mutex);
	if (philo->t_prog->death_occured || philo->t_prog->everybody_full)
	{
		pthread_mutex_unlock(&philo->t_prog->sync_mutex);
		return (0);
	}
	printf("%llu %d %s\n", get_time() - philo->t_prog->start_time,
		philo->id, msg);
	pthread_mutex_unlock(&philo->t_prog->sync_mutex);
	return (1);
}

static int	ft_should_stop(t_philosopher_thread *philo)
{
	pthread_mutex_lock(&philo->t_prog->sync_mutex);
	if (philo->t_prog->death_occured || philo->t_prog->everybody_full)
	{
		pthread_mutex_unlock(&philo->t_prog->sync_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->t_prog->sync_mutex);
	return (0);
}

static int	ft_get_forks(t_philosopher_thread *philo)
{
	if (ft_should_stop(philo))
		return (0);
	pthread_mutex_lock(&philo->left_fork);
	if (!ft_write_status(philo, "has taken a fork"))
	{
		pthread_mutex_unlock(&philo->left_fork);
		return (0);
	}
	if (ft_should_stop(philo))
		return (0);
	pthread_mutex_lock(philo->right_fork);
	if (!ft_write_status(philo, "has taken a fork"))
	{
		pthread_mutex_unlock(&philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		return (0);
	}
	return (1);
}

static int	ft_sleep_think(t_philosopher_thread *philo)
{
	if (!ft_write_status(philo, "is sleeping"))
		return (0);
	ft_usleep(philo->t_prog->time_2_sleep);
	if (!ft_write_status(philo, "is thinking"))
		return (0);
	return (1);
}

void	*philosopher_life(void *data)
{
	t_philosopher_thread	*philo;

	philo = (t_philosopher_thread *)data;
	if (!(philo->id & 1))
		ft_usleep(10);
	while (1)
	{
		if (!ft_get_forks(philo))
			break ;
		pthread_mutex_lock(&philo->t_prog->sync_mutex);
		philo->meals_count++;
		philo->last_meal_time = get_time();
		pthread_mutex_unlock(&philo->t_prog->sync_mutex);
		ft_write_status(philo, "is eating");
		ft_usleep(philo->t_prog->time_2_eat);
		pthread_mutex_lock(&philo->t_prog->sync_mutex);
		if (philo->meals_count == philo->t_prog->max_meals)
		philo->t_prog->total_finished += (philo->t_prog->max_meals != -1);
		pthread_mutex_unlock(&philo->t_prog->sync_mutex);
		pthread_mutex_unlock(&philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		if (!ft_sleep_think(philo))
			break ;
	}
	return (NULL);
}