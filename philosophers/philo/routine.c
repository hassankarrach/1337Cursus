/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarrach <hkarrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 08:07:33 by hkarrach          #+#    #+#             */
/*   Updated: 2024/08/15 01:08:10 by hkarrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	put_message(t_philo *philo, char *msg)
{
	pthread_mutex_lock(&philo->args->print_lock);
	if (msg[0] == 'd' || !simulation_should_end(philo->args))
		printf("%ld %d %s\n",
			get_time() - philo->args->start_time, philo->id, msg);
	pthread_mutex_unlock(&philo->args->print_lock);
}

static void	sync_philos(t_philo *philo)
{
	if (philo->args->number_of_philosophers % 2 == 0)
	{
		if (philo->id % 2 == 0)
			ft_usleep(30, philo->args);
	}
}

void	*routine(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	while (!philo->args->philos_are_ready)
		;
	if (philo->args->max_meals == 0)
		return (NULL);
	sync_philos(philo);
	while (!simulation_should_end(philo->args))
	{
		if (!take_forks(philo))
			break ;
		if (!eat(philo))
			break ;
		drop_forks(philo);
		if (!sleap(philo))
			break ;
		if (!think(philo))
			break ;
	}
	return (NULL);
}
