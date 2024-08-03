#include "../includes/philo.h"

static int	alloc(t_args *args)
{
	args->tid = malloc(sizeof(pthread_t) * args->number_of_philosophers);
	if (!args->tid)
		return (error(ALLOC_ERR_1, args));
	args->forks = malloc(sizeof(pthread_mutex_t) * args->number_of_philosophers);
	if (!args->forks)
		return (error(ALLOC_ERR_2, args));
	args->philos = malloc(sizeof(t_philo) * args->number_of_philosophers);
	if (!args->philos)
		return (error(ALLOC_ERR_3, args));
	return (0);
}

static int	init_forks(t_args *args)
{
	int	i;

	i = -1;
	while (++i < args->number_of_philosophers)
		pthread_mutex_init(&args->forks[i], NULL);
	i = 0;
	args->philos[0].l_fork = &args->forks[0];
	args->philos[0].r_fork = &args->forks[args->number_of_philosophers - 1];
	i = 1;
	while (i < args->number_of_philosophers)
	{
		args->philos[i].l_fork = &args->forks[i];
		args->philos[i].r_fork = &args->forks[i - 1];
		i++;
	}
	return (0);
}

static void	init_philos(t_args *args)
{
	int	i;

	i = 0;
	while (i < args->number_of_philosophers)
	{
		args->philos[i].args = args;
		args->philos[i].id = i + 1;
		args->philos[i].time_to_die = args->time2die;
		args->philos[i].eat_cont = 0;
		args->philos[i].eating = 0;
		args->philos[i].status = 0;
		pthread_mutex_init(&args->philos[i].lock, NULL);
		i++;
	}
}

int	init(t_args *args)
{
	if (alloc(args))
		return (1);
	if (init_forks(args))
		return (1);
	init_philos(args);
	return (0);
}