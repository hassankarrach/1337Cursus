/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarrach <hkarrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 08:07:29 by hkarrach          #+#    #+#             */
/*   Updated: 2024/08/15 05:06:45 by hkarrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int is_philo_dead_starving(t_philo *philo)
{
	long curr_time;

	if (philo->args->death_alert)
		return (1);
	curr_time = get_time();
	if (curr_time - philo->last_meal_time > philo->args->time_2_die)
	{
		philo->args->death_alert = 1;
		put_message(philo, "died");
		return (1);
	}
	return (0);
}

int all_philos_full(t_prog *args)
{
	if (args->max_meals != -1 && args->finished_philos == args->number_of_philosophers)
	{
		args->evrybody_full = 1;
		return (1);
	}
	return (0);
}

int simulation_should_end(t_prog *args)
{
	return (args->death_alert || args->evrybody_full);
}

void monitor_simulation(t_prog *args)
{
	int philo_id;

	philo_id = 0;
	if (args->max_meals == 0)
		return;
	while (philo_id < args->number_of_philosophers)
	{
		if (is_philo_dead_starving(&args->philosopher_threads[philo_id]) || all_philos_full(args))
			break;
		philo_id++;
		if (philo_id == args->number_of_philosophers)
			philo_id = 0;
	}
}
