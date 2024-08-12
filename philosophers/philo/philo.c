#include "philo.h"

int	death(t_philosopher *philo)
{
	philo->prog->death = 0;
	pthread_mutex_lock(&philo->prog->write);
	printf("%lld %d %s", ft_time()
		- philo->prog->start, philo->pid + 1, "died\n");
	return (0);
}
int	is_alive(t_philosopher *philo)
{
	int	i;

	while (1) // infinite loop, so it keeps checking if philosopher is alive
	{
		i = 0;
		while (i < philo->prog->nb_philo) // for each philosopher
		{
			if (!philo->is_eating && ft_time() // check if philosopher should be dead
				- philo->last_eat_time >= philo->prog->time_to_die)
			{
				if (philo->meals_count != philo->prog->max_meals) // if philosopher didn't eat enough
					return (death(philo));
				return (0);
			}
			else if (philo->prog->time_to_die < philo->prog->time_to_eat
				|| philo->prog->time_to_die < philo->prog->time_to_sleep)
				return (death(philo));
			i++;
		}
	}
	return (1);
}
static int	start_threads(t_program *prog)
{
	int	i;

	i = 0;
	prog->start = ft_time(); // get start time
	while (i < prog->nb_philo) // create threads for each philosopher
	{
		prog->philosopher[i]->last_eat_time = ft_time(); // get last eat time
		if (pthread_create(&prog->philosopher[i]->thd_philo, NULL,
				&start_routine, (void *)prog->philosopher[i]) != 0)
			return (0);
		i++;
		usleep(100); // sleep for 100 microseconds, so threads don't start at the same time
	}
	is_alive(*prog->philosopher); // check if philosopher is alive
	return (1);
}
static t_program	*parser(int argc, char **argv)
{
	t_program	*prog;
	int		counter;

	counter = 1; // skip program name
	prog = (t_program *)malloc(sizeof(t_program) * 1); // allocate memory for program struct
	if (prog == NULL)
		return (NULL);
	prog->nb_philo = ft_atoi(argv[counter++]);
	prog->time_to_die = ft_atoi(argv[counter++]);
	prog->time_to_eat = ft_atoi(argv[counter++]);
	prog->time_to_sleep = ft_atoi(argv[counter++]);
	prog->max_meals = -1;
	prog->death = 1;
	if (argc - 1 == 5)
		prog->max_meals = ft_atoi(argv[counter]);
	prog->forks = init_fork(prog);
	prog->philosopher = init_philo(prog);
	if (prog->philosopher == NULL || prog->nb_philo == 0)
		return (NULL);
	if (pthread_mutex_init(&prog->write, NULL) != 0)
		return (NULL);
	return (prog);
}

int	main(int argc, char **argv)
{
	t_program	*prog;

	prog = NULL;
	if (is_args_valid(argc, argv) != 1) // check if arguments are valid
	{
		printf("Error: Invalid Argument\n");
		return (0);
	}
	prog = parser(argc, argv); // fill program struct
	if (prog == NULL)
		return (0);
	start_threads(prog);
}
