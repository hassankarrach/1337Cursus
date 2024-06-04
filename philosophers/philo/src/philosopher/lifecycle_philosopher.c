#include "../../includes/philo.h"

static void eat(t_philosopher_thread *philosopher) {
    printf("Philosopher #%d is eating\n", philosopher->id);
	//sleep to eat.
    philosopher->state = EATING;
}

static void think(t_philosopher_thread *philosopher) {
    printf("Philosopher #%d is thinking\n", philosopher->id);
    philosopher->state = THINKING;
}

static void sleep_philo(t_philosopher_thread *philosopher) {
    printf("Philosopher #%d is sleeping\n", philosopher->id);
    philosopher->state = SLEEPING;
}

void *philosopher_life(void *data)
{
	t_philosopher_thread *philosopher;

	philosopher = (t_philosopher_thread *)data;

	printf("a philosopher #%d say hello!\n", philosopher->id);
	return (NULL);
}