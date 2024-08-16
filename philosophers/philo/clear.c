/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarrach <hkarrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 08:07:24 by hkarrach          #+#    #+#             */
/*   Updated: 2024/08/14 08:11:08 by hkarrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	join_thread(t_prog *args)
{
	int	i;
	int	res;

	i = 0;
	while (i < args->number_of_philosophers)
	{
		res = pthread_join(args->philosopher_threads[i].thread, NULL);
		if (res != 0)
			printf("Error joining thread %d: \n", i);
		i++;
	}
}

static void	destroy_mutexs(t_prog *args)
{
	int	i;

	i = 0;
	while (i < args->number_of_philosophers)
	{
		pthread_mutex_destroy(&args->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&args->table_lock);
	pthread_mutex_destroy(&args->print_lock);
}

static void	free_memory(t_prog *args)
{
	free(args->philosopher_threads);
	free(args->forks);
}

void	exit_simulation(t_prog *args)
{
	join_thread(args);
	destroy_mutexs(args);
	free_memory(args);
}
