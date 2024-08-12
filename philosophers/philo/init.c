#include "philo.h"

void init_forks(t_prog *args)
{
    int i;

    i = 0;
    args->forks = malloc(sizeof(pthread_mutex_t) * args->number_of_philosophers);
    if (!args->forks)
        print_error("malloc failed.", 1);
    while (i < args->number_of_philosophers)
    {
        pthread_mutex_init(&args->forks[i], NULL);
        i++;
    }
}

void init_philos(t_prog *args)
{
    int i;

    i = 0;
    args->philos_are_ready = 0;
    pthread_mutex_init(&args->print_lock, NULL);
    pthread_mutex_init(&args->death_lock, NULL);
    pthread_mutex_init(&args->meals_lock, NULL);
    pthread_mutex_init(&args->table_lock, NULL);
    
    args->philosopher_threads = malloc(sizeof(t_philo) * args->number_of_philosophers);
    if (!args->philosopher_threads)
        print_error("malloc failed.", 1);
    while (i < args->number_of_philosophers)
    {
        pthread_mutex_init(&args->philosopher_threads[i].philo_mutex, NULL);
        args->philosopher_threads[i].id = i + 1;
        args->philosopher_threads[i].last_meal_time = get_time();
        args->philosopher_threads[i].meals_count = 0;
        args->philosopher_threads[i].args = args;
        // forks
        args->philosopher_threads[i].left_fork = &args->forks[i];
        args->philosopher_threads[i].right_fork = &args->forks[(i + 1) % args->number_of_philosophers];
        i++;
    }
}