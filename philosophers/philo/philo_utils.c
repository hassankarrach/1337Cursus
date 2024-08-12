#include "philo.h"

static int	is_number(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
		{
			if (str[i] == '-' && !str[i + 1])
				return (0);
			else if (str[i] == '+' && !str[i + 1])
				return (0);
			else if (str[i] == '+' && str[i + 1] >= '0' && str[i + 1] <= '9')
				return (1);
			else if (str[i] == '-' && str[i + 1] >= '0' && str[i + 1] <= '9')
				return (0);
			return (0);
		}
		i++;
	}
	return (1);
}
static int	check_arg(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0') // if string is empty
		return (0);
	while (str[i])
	{
		if (!is_number(&str[i])) // each character must be a number
			return (0);
		i++;
	}
	return (1);
}
int	is_args_valid(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac > 6 || ac < 5) // must have 4 or 5 arguments
		return (0);
	while (i < ac)
	{
		if ((check_arg(av[i]) != 1) || ft_atoi(av[i]) < 1) // each argument must be a number and greater than 0
			return (0);
		i++;
	}
	return (1);
}
int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	num;

	i = 0;
	sign = 1;
	num = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num * sign);
}

void	print_status(t_program *prog, int id, char *str) // print status of philosopher
{
	pthread_mutex_lock(&prog->write);
	printf("%lld %d %s", ft_time() - prog->start, id + 1, str);
	pthread_mutex_unlock(&prog->write);
}
