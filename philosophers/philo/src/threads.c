#include "../includes/philo.h"

void	*monitor(void *philo_ptr)
{
	t_philo	*philo;

	philo = (t_philo *) philo_ptr;
	pthread_mutex_lock(&philo->args->write);
	printf("args val: %d", philo->args->dead_accured);
	pthread_mutex_unlock(&philo->args->write);
	while (philo->args->dead_accured == 0)
	{
		pthread_mutex_lock(&philo->lock);
		if (philo->args->finished >= philo->args->number_of_philosophers)
			philo->args->dead_accured = 1;
		pthread_mutex_unlock(&philo->lock);
	}
	return ((void *)0);
}

void	*supervisor(void *philo_ptr)
{
	t_philo	*philo;

	philo = (t_philo *) philo_ptr;
	while (philo->args->dead_accured == 0)
	{
		pthread_mutex_lock(&philo->lock);
		if (get_time() >= philo->time_to_die && philo->eating == 0)
			messages(DIED, philo);
		if (philo->eat_cont == philo->args->max_meals)
		{
			pthread_mutex_lock(&philo->args->lock);
			philo->args->finished++;
			philo->eat_cont++;
			pthread_mutex_unlock(&philo->args->lock);
		}
		pthread_mutex_unlock(&philo->lock);
	}
	return ((void *)0);
}

void	*routine(void *philo_ptr)
{
	t_philo	*philo;

	philo = (t_philo *) philo_ptr;
	philo->time_to_die = philo->args->dead_accured + get_time();
	if (pthread_create(&philo->t1, NULL, &supervisor, (void *)philo))
		return ((void *)1);
	while (philo->args->dead_accured == 0)
	{
		eat(philo);
		messages(THINKING, philo);
	}
	if (pthread_join(philo->t1, NULL))
		return ((void *)1);
	return ((void *)0);
}

int	thread_init(t_args *args)
{
	int			i;
	pthread_t	t0;

	i = -1;
	args->start_time = get_time();
	if (args->max_meals > 0)
	{
		if (pthread_create(&t0, NULL, &monitor, &args->philos[0]))
			return (error(TH_ERR, args));
	}
	while (++i < args->number_of_philosophers)
	{
		if (pthread_create(&args->tid[i], NULL, &routine, &args->philos[i]))
			return (error(TH_ERR, args));
		ft_usleep(1);
	}
	i = -1;
	while (++i < args->number_of_philosophers)
	{
		if (pthread_join(args->tid[i], NULL))
			return (error(JOIN_ERR, args));
	}
	return (0);
}