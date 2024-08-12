#include "philo.h"

// wait for threads to finish
void join_threads(t_prog *args)
{
    int i;
    int ret;

    i = 0;
    while (i < args->number_of_philosophers)
    {
        ret = pthread_join(args->philosopher_threads[i].thread, NULL);
        if (ret != 0)
        {
            printf("Error joining thread %d: \n", i);
        }
        i++;
    }
}