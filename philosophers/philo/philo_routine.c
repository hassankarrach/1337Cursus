#include"philo.h"

void	ft_sleep(int x) // a function that sleeps for x milliseconds, it takes x as an argument (time in milliseconds)
{
	long	i;

	i = ft_time(); // get current time in milliseconds
	while (ft_time() - i < x) // while current time - start time is less than x
		usleep(100); // sleep for 100 microseconds
}

void	philo_activities(t_philosopher *philo) // a function that simulates philosopher activities
{
	pthread_mutex_lock(&philo->prog->forks[philo->left]); // lock left fork
	print_status(philo->prog, philo->pid, "has taken a fork\n"); // print message
	pthread_mutex_lock(&philo->prog->forks[philo->right]); // lock right fork
	print_status(philo->prog, philo->pid, "has taken a fork\n"); // print message
	philo->last_eat_time = ft_time(); // get last eat time
	print_status(philo->prog, philo->pid, "is eating\n"); // print message
	philo->is_eating = 1; // mark philosopher as eating
	ft_sleep(philo->prog->time_to_eat); // sleep for time to eat
	philo->meals_count += 1; // increment meals count
	pthread_mutex_unlock(&philo->prog->forks[philo->right]); // unlock right fork
	pthread_mutex_unlock(&philo->prog->forks[philo->left]); // unlock left fork
	if (philo->meals_count != philo->prog->max_meals) // if philosopher didn't eat enough
	{
		print_status(philo->prog, philo->pid, "is sleeping\n"); // sleep, if philosopher didn't eat enough
		ft_sleep(philo->prog->time_to_sleep);
		print_status(philo->prog, philo->pid, "is thinking\n"); // think, until philo goes to eat again
	}
	philo->is_eating = 0; // mark philosopher as not eating
}

void	*start_routine(void *data)
{
	t_philosopher	*philo;
	int		i;

	philo = (t_philosopher *)data;
	i = 0;
	while (i < philo->prog->max_meals || philo->prog->death == 1)// while philosopher is alive
	{
		philo_activities(philo); // simulate philosopher activities
		if (philo->meals_count == philo->prog->max_meals) // if philosopher ate enough
			philo->prog->death = 0; 
		i++;
	}
	return (NULL);
}
