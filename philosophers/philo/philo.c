/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarrach <hkarrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 08:07:31 by hkarrach          #+#    #+#             */
/*   Updated: 2024/08/15 00:49:08 by hkarrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	is_only_numbers(char **av)
{
	int	i;
	int	j;

	i = 0;
	av++;
	while (av[i])
	{
		j = 0;
		if (av[i][j] == '+')
			j++;
		while (av[i][j])
		{
			if (av[i][j] == ' ')
			{
				j++;
				continue ;
			}
			if (av[i][j] < '0' || av[i][j] > '9')
			{
				print_error("invalid arg!", 1);
			}
			j++;
		}
		i++;
	}
}

static void	parser(int ac, char **av, t_prog *arg)
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
	if (ac == 6 && arg->max_meals < 0)
		print_error("invalid number of meals!", 1);
	if (arg->time_2_die < 0 || arg->time_2_eat < 0 || arg->time_2_sleap < 0
		|| arg->time_2_die > INT_MAX || arg->time_2_eat > INT_MAX
		|| arg->time_2_sleap > INT_MAX
		|| arg->max_meals > INT_MAX)
		print_error("invalid time!", 1);
}

int	main(int ac, char **av)
{
	t_prog	args;
	int		i;

	ft_memset(&args, 0, sizeof(t_prog));
	parser(ac, av, &args);
	init_forks(&args);
	init_philos(&args);
	i = 0;
	while (i < args.number_of_philosophers)
	{
		pthread_create(&args.philosopher_threads[i].thread,
			NULL, &routine, &args.philosopher_threads[i]);
		i++;
	}
	args.philos_are_ready = true;
	args.start_time = get_time();
	monitor_simulation(&args);
	exit_simulation(&args);
	return (0);
}
