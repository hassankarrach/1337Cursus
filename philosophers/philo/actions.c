/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarrach <hkarrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 08:07:21 by hkarrach          #+#    #+#             */
/*   Updated: 2024/08/16 03:45:28 by hkarrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	take_forks(t_philo *philo)
{
	if (simulation_should_end(philo->args))
		return (0);
	pthread_mutex_lock(philo->left_fork);
	if (simulation_should_end(philo->args))
	{
		pthread_mutex_unlock(philo->left_fork);
		return (0);
	}
	put_message(philo, "has taken a fork");
	if (philo->args->number_of_philosophers == 1)
	{
		ft_usleep(philo->args->time_2_die, philo->args);
		pthread_mutex_unlock(philo->left_fork);
		return (0);
	}
	pthread_mutex_lock(philo->right_fork);
	if (simulation_should_end(philo->args))
	{
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		return (0);
	}
	put_message(philo, "has taken a fork");
	return (1);
}

void	drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

int	eat(t_philo *philo)
{
	if (simulation_should_end(philo->args))
		return (0);
	put_message(philo, "is eating");
	philo->last_meal_time = get_time();
	ft_usleep(philo->args->time_2_eat, philo->args);
	philo->meals_count++;
	if (philo->args->max_meals != -1
		&& philo->meals_count >= (size_t)philo->args->max_meals)
		philo->args->finished_philos++;
	return (1);
}

int	sleap(t_philo *philo)
{
	if (simulation_should_end(philo->args))
		return (0);
	put_message(philo, "is sleeping");
	ft_usleep(philo->args->time_2_sleap, philo->args);
	return (1);
}

int think(t_philo *philo)
{
    long t_think;

    if (simulation_should_end(philo->args))
	{
		return (0);
	}
	put_message(philo, THINKING);
	if (philo->args->number_of_philosophers % 2 == 0)
        return (1);
    else
    {
        if (philo->args->time_2_sleap > philo->args->time_2_eat)
            t_think = 0;
        else
            t_think = (philo->args->time_2_eat * 2) - philo->args->time_2_sleap;
        ft_usleep(t_think / 2, philo->args);
    }
    return (1);
}
//./philo 20 180 60 60 7 | grep "7 is eating" | wc -l
//./philo 200 180 60 60