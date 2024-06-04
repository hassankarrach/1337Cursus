#include "../../includes/philo.h"

void threads_wait(pthread_t *philosophers, int philosophers_count)
{
	int i = 0;
	while (i < philosophers_count)
	{
		pthread_join(philosophers[i], NULL);
		i++;
	}
}