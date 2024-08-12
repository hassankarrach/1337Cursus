#include "philo.h"

pthread_mutex_t	*init_fork(t_program *prog)
{
	pthread_mutex_t	*forks;
	int				i;

	i = 0;
	forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* prog->nb_philo);
	if (forks == NULL)
		return (NULL);
	while (i < prog->nb_philo)
	{
		if (pthread_mutex_init(&forks[i], 0) != 0)
			return (NULL);
		i++;
	}
	return (forks);
}

t_philosopher	**init_philo(t_program *prog)
{
	t_philosopher	**philos;
	int		i;

	i = 0;
	philos = (t_philosopher **)malloc(sizeof(t_philosopher *) * prog->nb_philo + 1);
	if (philos == NULL)
		return (NULL);
	while (i < prog->nb_philo)
	{
		philos[i] = (t_philosopher *)malloc(sizeof(t_philosopher));
		if (philos[i] == NULL)
			return (NULL);
		if (pthread_mutex_init(&philos[i]->eating, 0) != 0)
			return (NULL);
		philos[i]->prog = prog;
		philos[i]->pid = i;
		philos[i]->is_eating = 0;
		philos[i]->meals_count = 0;
		philos[i]->left = i;
		philos[i]->right = (i + 1) % philos[i]->prog->nb_philo; // circular
		i++;
	}
	return (philos);
}

long long	ft_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}
