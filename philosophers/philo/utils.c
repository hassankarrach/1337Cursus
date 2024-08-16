/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarrach <hkarrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 08:07:43 by hkarrach          #+#    #+#             */
/*   Updated: 2024/08/14 08:30:14 by hkarrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_memset(void *ptr, int value, size_t len)
{
	unsigned char	*p;

	p = (unsigned char *)ptr;
	while (len > 0)
	{
		p[len - 1] = value;
		len--;
	}
	return (ptr);
}

long	ft_atol(const char *nptr)
{
	char	*str;
	long	result;

	str = (char *)nptr;
	result = 0;
	while (*str && *str == ' ')
		str++;
	if (*str && *str == '+')
		str++;
	while (*str && *str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result);
}

int	print_error(char *err_msg, int should_exit)
{
	write(2, "Error:\n", 7);
	printf("%s", err_msg);
	if (should_exit)
		exit(1);
	return (1);
}

long	get_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		return (print_error("gettimeofday() FAILURE\n", 0));
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	ft_usleep(long time, t_prog *args)
{
	long	start;

	start = get_time();
	while ((get_time() - start) < time && !simulation_should_end(args))
		usleep(50);
}
