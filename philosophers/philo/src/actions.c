#include "../includes/philo.h"

static int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(char *)s1 - *(char *)s2);
}

void	messages(char *str, t_philo *philo)
{
	u_int64_t	time;

	pthread_mutex_lock(&philo->args->write);
	time = get_time() - philo->args->start_time;
	if (ft_strcmp(DIED, str) == 0 && philo->args->dead_accured == 0)
	{
		printf("%llu %d %s\n", time, philo->id, str);
		philo->args->dead_accured = 1;
	}
	if (!philo->args->dead_accured)
		printf("%llu %d %s\n", time, philo->id, str);
	pthread_mutex_unlock(&philo->args->write);
}

void	take_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	messages(TAKE_FORKS, philo);
	pthread_mutex_lock(philo->l_fork);
	messages(TAKE_FORKS, philo);
}

void	drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
	messages(SLEEPING, philo);
	ft_usleep(philo->args->time2sleep);
}

void	eat(t_philo *philo)
{
	take_forks(philo);
	pthread_mutex_lock(&philo->lock);
	philo->eating = 1;
	philo->time_to_die = get_time() + philo->args->time2die;
	messages(EATING, philo);
	philo->eat_cont++;
	ft_usleep(philo->args->time2eat);
	philo->eating = 0;
	pthread_mutex_unlock(&philo->lock);
	drop_forks(philo);
}