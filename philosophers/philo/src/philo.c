#include "../includes/philo.h"

static int	case_one(t_args *args)
{
	args->start_time = get_time();
	if (pthread_create(&args->tid[0], NULL, &routine, &args->philos[0]))
		return (error(TH_ERR, args));
	pthread_detach(args->tid[0]);
	while (args->dead_accured == 0)
		ft_usleep(0);
	ft_exit(args);
	return (0);
}

void	clear_data(t_args	*args)
{
	if (args->tid)
		free(args->tid);
	if (args->forks)
		free(args->forks);
	if (args->philos)
		free(args->philos);
}


int main(int ac, char **av) {
	t_args args;

	//parsing
	parse_args(ac, av, &args);
	//initing
	if (init(&args))
		return (1);
	if (args.number_of_philosophers == 1)
		return (case_one(&args));
	if (thread_init(&args))
		return (1);
	ft_exit(&args);
	return (0);
}
