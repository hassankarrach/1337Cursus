#include"philo.h"

void	ft_sleep(int x)
{
	long	i;

	i = ft_time();
	while (ft_time() - i < x)
		usleep(100);
}

void	philo_activity(t_philosopher *philo)
{
	pthread_mutex_lock(&philo->prog->forks[philo->left]);
	print_status(philo->prog, philo->pid, "has taken a fork\n");
	pthread_mutex_lock(&philo->prog->forks[philo->right]);
	print_status(philo->prog, philo->pid, "has taken a fork\n");
	philo->last_eat_time = ft_time();
	print_status(philo->prog, philo->pid, "is eating\n");
	philo->is_eating = 1;
	ft_sleep(philo->prog->time_to_eat);
	philo->meals_count += 1;
	pthread_mutex_unlock(&philo->prog->forks[philo->right]);
	pthread_mutex_unlock(&philo->prog->forks[philo->left]);
	if (philo->meals_count != philo->prog->max_meals)
	{
		print_status(philo->prog, philo->pid, "is sleeping\n");
		ft_sleep(philo->prog->time_to_sleep);
		print_status(philo->prog, philo->pid, "is thinking\n");
	}
	philo->is_eating = 0;
}

void	*start_routine(void *data)
{
	t_philosopher	*philo;
	int		i;

	philo = (t_philosopher *)data;
	i = 0;
	while (i < philo->prog->max_meals || philo->prog->death == 1)
	{
		philo_activity(philo);
		if (philo->meals_count == philo->prog->max_meals)
			philo->prog->death = 0;
		i++;
	}
	return (NULL);
}
