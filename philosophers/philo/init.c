/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarrach <hkarrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 08:07:26 by hkarrach          #+#    #+#             */
/*   Updated: 2024/08/14 08:13:22 by hkarrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_forks(t_prog *args)
{
	int	i;

	i = 0;
	args->forks = malloc(sizeof(pthread_mutex_t)
			* args->number_of_philosophers);
	if (!args->forks)
		print_error("malloc failed.", 1);
	while (i < args->number_of_philosophers)
	{
		pthread_mutex_init(&args->forks[i], NULL);
		i++;
	}
}

static void	assign_forks(t_prog *args, t_philo *philo, int i)
{
	philo->left_fork = &args->forks[(i + 1) % args->number_of_philosophers];
	philo->right_fork = &args->forks[i];
	if (philo->id % 2 == 0)
	{
		philo->left_fork = &args->forks[i];
		philo->right_fork = &args->forks[(i + 1)
			% args->number_of_philosophers];
	}
}

void	init_philos(t_prog *args)
{
	int	i;

	i = 0;
	pthread_mutex_init(&args->print_lock, NULL);
	args->death_alert = 0;
	args->evrybody_full = 0;
	args->finished_philos = 0;
	args->philos_are_ready = false;
	args->philosopher_threads = malloc(sizeof(t_philo)
			* args->number_of_philosophers);
	if (!args->philosopher_threads)
		print_error("malloc failed.", 1);
	while (i < args->number_of_philosophers)
	{
		args->philosopher_threads[i].id = i + 1;
		args->philosopher_threads[i].last_meal_time = get_time();
		args->philosopher_threads[i].meals_count = 0;
		args->philosopher_threads[i].args = args;
		assign_forks(args, &args->philosopher_threads[i], i);
		i++;
	}
}
