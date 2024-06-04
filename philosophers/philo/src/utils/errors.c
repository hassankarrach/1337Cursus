#include "../../includes/philo.h"

void	print_error(char *err_msg, int should_exit)
{
	write(2, "Error:\n", 7);
	printf("%s", err_msg);
	if (should_exit)
		exit (1);
}