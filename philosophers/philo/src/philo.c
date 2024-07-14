#include "../includes/philo.h"

static void	parse_args(int ac, char **av, t_program *philo)
{
	int i;

	i = 0;
	if (ac > 6 || ac < 5)
		print_error("invalid number of argments.", 1);
	is_only_numbers(av);
	philo->number_of_philosophers = ft_atoi(av[1]);
	philo->time_2_die = ft_atoi(av[2]);
	philo->time_2_eat = ft_atoi(av[3]);
	philo->time_2_sleep = ft_atoi(av[4]);
	if (ac == 6)
		philo->max_meals = ft_atoi(av[5]);
	else
		philo->max_meals = -1;

	if (philo->number_of_philosophers < 1 || philo->number_of_philosophers > 200)
		print_error("invalid number of philosophers.", 1);
	if (ac == 6 && philo->max_meals < 1)
		print_error("a philosopher must eat at least once, if specefied.", 1);
	if (philo->time_2_die < 0 || philo->time_2_eat < 0 || philo->time_2_sleep < 0)
		print_error("a timestamp must be greater than zero.", 1);

	pthread_mutex_init(&philo->sync_mutex, NULL);
	philo->start_time = get_time();
}
static void	Philos_init(t_program *philo)
{
	int	i;

	i = -1;
	while (++i < philo->number_of_philosophers)
	{
		philo->philosopher_threads[i].id = i + 1; //Assign id to each philo
		philo->philosopher_threads[i].last_meal_time = philo->start_time; //set last meal time
		pthread_mutex_init(&philo->philosopher_threads[i].left_fork, NULL); //Protext the fork
		if (i + 1 == philo->number_of_philosophers)
			philo->philosopher_threads[i].right_fork = &philo->philosopher_threads[0].left_fork;
		else
			philo->philosopher_threads[i].right_fork = &philo->philosopher_threads[i + 1].left_fork;
		philo->philosopher_threads[i].t_prog = philo;
	}
}

int	break_life(t_program *philo, int *i)
{
	pthread_mutex_lock(&philo->sync_mutex); //Protect the following
	if (get_time() - philo->philosopher_threads[*i].last_meal_time >= (unsigned long long)philo->time_2_die
		|| philo->total_finished == philo->number_of_philosophers)
	{
		if (philo->max_meals != -1
			&& philo->total_finished == philo->number_of_philosophers)
		{
			philo->everybody_full = 1;
			pthread_mutex_unlock(&philo->philosopher_threads[*i].left_fork);
			printf("Every philosopher has eaten %d times\n", philo->max_meals);
		}
		else
		{
			philo->death_occured = 1;
			pthread_mutex_unlock(&philo->philosopher_threads[*i].left_fork);
			printf("%llu %d died\n", get_time() - philo->start_time, philo->philosopher_threads[*i].id);
		}
		pthread_mutex_unlock(&philo->sync_mutex);
		return (1);
	}
	if (*i + 1 == philo->number_of_philosophers)
		*i = -1;
	pthread_mutex_unlock(&philo->sync_mutex);
	return (0);
}
int main(int argc, char* argv[]) {
	t_program philo_data;
	int i;
	
	memset(&philo_data, 0, sizeof(t_program));
	parse_args(argc, argv, &philo_data);
	Philos_init(&philo_data);

	//Create Philos
	i = -1;
	while (++i < philo_data.number_of_philosophers)
		pthread_create(&philo_data.philosopher_threads[i].thread, NULL, philosopher_life, &philo_data.philosopher_threads[i]);

	i = -1;
	while (++i < philo_data.number_of_philosophers
		&& !break_life(&philo_data, &i))
		i = i + 0;
	//wait for them
	i = -1;
	while (++i < philo_data.number_of_philosophers)
		pthread_join(philo_data.philosopher_threads[i].thread, NULL);
	i = -1;
	while (++i < philo_data.number_of_philosophers)
		pthread_detach(philo_data.philosopher_threads[i].thread);
	i = -1;
	while (++i < philo_data.number_of_philosophers)
		pthread_mutex_destroy(&philo_data.philosopher_threads[i].left_fork);
	return (0);
}
