#include "philo.h"

void *ft_memset(void *ptr, int value, size_t len)
{
	unsigned char *p;

	p = (unsigned char *)ptr;
	while (len > 0)
	{
		p[len - 1] = value;
		len--;
	}
	return (ptr);
}
long ft_atol(const char *ptr)
{
	char *str;
	long result;

	str = (char *)ptr;
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
int print_error(char *err_msg, int should_exit)
{
	write(2, "Error:\n", 7);
	printf("%s", err_msg);
	if (should_exit)
		exit(1);
	return (1);
}
void is_only_numbers(char **av)
{
	int i;
	int j;

	i = 0;
	av++;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] == ' ')
			{
				j++;
				continue;
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
size_t get_time(void)
{
	struct timeval tv;
	/*
		tv.tv_sec => number of seconds since the unix epoch (1970)
		tv.tv_usec=> additional microseconds for precision (in micro-seconds)

		res => would be in milliseconds, so we convert the seconds to milli by *1000
			   then, adding the aditional microseconds (but first, convert them to milli by /1000)

			   1sec = 1000 milli-sec
			   1milli-sec = 1000 micro-sec
	*/

	if (gettimeofday(&tv, NULL))
		return (print_error("gettimeofday() FAILURE\n", 0));
	return ((tv.tv_sec * (uint64_t)1000) + (tv.tv_usec / 1000));
}
int ft_usleep(__useconds_t time)
{
	uint64_t start;

	start = get_time();
	while ((get_time() - start) < time) // keep check. also add flag later to stop the loop if simulaiton is ended.
		usleep(time / 10);				// sleap 10%/time to reduce CPU usage.
	return (0);
}