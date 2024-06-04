#include "../includes/philo.h"

static void	parse_args(int ac, char **av, t_philo_data *philo)
{
	if (ac > 6 || ac < 5)
		print_error("invalid number of argments.", 1);
	philo->number_of_philosophers = ft_atoi(av[1]);
	philo->time_to_die = ft_atoi(av[2]);
	philo->time_to_eat = ft_atoi(av[3]);
	philo->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		philo->number_of_times_each_philosopher_must_eat = ft_atoi(av[5]);

	if (philo->number_of_philosophers < 1)
		print_error("must be at least one philosopher.", 1);
	if (ac == 6 && philo->number_of_times_each_philosopher_must_eat < 1)
		print_error("a philosopher must eat at least once, if specefied.", 1);
	if (philo->time_to_die < 0 || philo->time_to_eat < 0 || philo->time_to_sleep < 0)
		print_error("a timestamp must be greater than zero.", 1);
}

int main(int argc, char* argv[]) {
	t_philo_data philo_data;
	
	parse_args(argc, argv, &philo_data);
	init_philosophers_list(&philo_data);

	pthread_t philosophers[philo_data.number_of_philosophers];
	pthread_mutex_t forks_mutexes[philo_data.number_of_philosophers];

	create_threads(&philo_data);
	
	init_mutexes(forks_mutexes, philo_data.number_of_philosophers);
	init_threads(&philo_data, philosophers, philo_data.number_of_philosophers);

	threads_wait(philosophers, philo_data.number_of_philosophers);
	return 0;
}