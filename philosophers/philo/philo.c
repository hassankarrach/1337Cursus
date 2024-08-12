#include "philo.h"

static void parser(int ac, char **av, t_prog *arg)
{
    if (ac > 6 || ac < 5)
        print_error("invalid number of arguments.", 1);
    is_only_numbers(av);
    arg->number_of_philosophers = ft_atol(av[1]);
    arg->time_2_die = ft_atol(av[2]);
    arg->time_2_eat = ft_atol(av[3]);
    arg->time_2_sleap = ft_atol(av[4]);
    if (ac == 6)
        arg->max_meals = ft_atol(av[5]);
    else
        arg->max_meals = -1;
    if (arg->number_of_philosophers < 1 || arg->number_of_philosophers > 200)
        print_error("invalid number of philosophers!", 1);
    if (ac == 6 && arg->max_meals < 1)
        print_error("a philosopher must eat at least once!", 1);
    if (arg->time_2_die < 0 || arg->time_2_eat < 0 || arg->time_2_sleap < 0
        || arg->time_2_die > INT_MAX || arg->time_2_eat > INT_MAX || arg->time_2_sleap > INT_MAX)
        print_error("invalid time!", 1);

    arg->start_time = get_time();
}

int main(int ac, char **av)
{
    t_prog args;
    int i;

    ft_memset(&args, 0, sizeof(t_prog));
    parser(ac, av, &args);

    init_forks(&args);
    init_philos(&args);

    i = 0;
    while (i < args.number_of_philosophers)
    {
        pthread_create(&args.philosopher_threads[i].thread, NULL, &routine, &args.philosopher_threads[i]);
        i++;
    }
    monitor_simulation(&args);
    
    join_threads(&args);
    return (0);
}	