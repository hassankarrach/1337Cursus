#include "../../includes/philo.h"

int		print_error(char *err_msg, int should_exit)
{
	write(2, "Error:\n", 7);
	printf("%s", err_msg);
	if (should_exit)
		exit (1);
	return (1);
}
