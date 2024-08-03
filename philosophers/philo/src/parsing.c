#include "../includes/philo.h"

static void is_only_numbers(char **av)
{
    int i;
    int j;

    i = 0;
    av++;
    while (av[i])
    {
        j = 0;
        while (av[i][j])
        {
            if (av[i][j] == ' ')
            {
                j++;
                continue;
            }
            if (av[i][j] < '0' || av[i][j] > '9')
            {
                error("invalid arg!", NULL);
            }
            j++;
        }    
        i++;
    }
}

void	parse_args(int ac, char **av, t_args *args)
{
	int i;

	i = 0;
	if (ac > 6 || ac < 5)
		error("invalid number of argments.", NULL);
	is_only_numbers(av);
	args->number_of_philosophers = (int)ft_atoi(av[1]);
	args->time2die = (u_int64_t)ft_atoi(av[2]);
	args->time2eat = (u_int64_t)ft_atoi(av[3]);
	args->time2sleep = (u_int64_t)ft_atoi(av[4]);
	if (ac == 6)
		args->max_meals = (int)ft_atoi(av[5]);
	else
		args->max_meals = -1;

	if (args->number_of_philosophers < 1 || args->number_of_philosophers > 200)
		error("invalid number of philosophers.", NULL);
	if (ac == 6 && args->max_meals < 1)
		error("a philosopher must eat at least once, if specefied.", NULL);
	if (args->time2die < 0 || args->time2eat < 0 || args->time2sleep < 0)
		error("a timestamp must be greater than zero.", NULL);
    args->finished = 0;
    args->dead_accured = 0;
	args->start_time = get_time();

    pthread_mutex_init(&args->lock, NULL);
    pthread_mutex_init(&args->write, NULL);
}