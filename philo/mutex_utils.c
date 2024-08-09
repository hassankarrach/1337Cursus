#include "philo.h"

// Getters
bool get_bool(pthread_mutex_t *mutex, bool *value)
{
	bool res;

	pthread_mutex_lock(mutex);
	res = *value;
	pthread_mutex_unlock(mutex);
	return (res);
}
long get_long(pthread_mutex_t *mutex, long *value)
{
	long res;

	pthread_mutex_lock(mutex);
	res = *value;
	pthread_mutex_unlock(mutex);
	return (res);
}

// Setters
void set_bool(pthread_mutex_t *mutex, bool *value, bool new_value)
{
	pthread_mutex_lock(mutex);
	*value = new_value;
	pthread_mutex_unlock(mutex);
}
void set_long(pthread_mutex_t *mutex, long *value, long new_value)
{
	pthread_mutex_lock(mutex);
	*value = new_value;
	pthread_mutex_unlock(mutex);
}
