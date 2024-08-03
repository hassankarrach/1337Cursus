#ifndef PHILO_H
#define PHILO_H

// includes ====================================================================
#include <pthread.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <stdint.h>
#include <sys/time.h>
// ============================================================================


// defines =====================================================================
//	alloc_err
# define ALLOC_ERR_1 "ERROR WHILE ALLOCATING THREADS IDs"
# define ALLOC_ERR_3 "ERROR WHILE ALLOCATING PHILOS"
# define ALLOC_ERR_2 "ERROR WHILE ALLOCATING FORKS"
//	input_err
# define ERR_IN_1 "INVALID INPUT CHARACTER"
# define ERR_IN_2 "INVALID INPUT VALUES"
//	pthread_err
# define TH_ERR "ERROR WHILE CREATING THREADS"
# define JOIN_ERR "ERROR WHILE JOINING THREADS"
# define INIT_ERR_1 "ERROR WHILE INIT FORKS"
//	time_err
# define TIME_ERR "UNABLE TO RETRIVE UTC"
//	philo_msg
# define TAKE_FORKS "has taken a fork"
# define THINKING "is thinking"
# define SLEEPING "is sleeping"
# define EATING "is eating"
# define DIED "died"
// ============================================================================


// structs =====================================================================
struct	s_args;
typedef struct s_philo
{
	struct s_args	*args;
	pthread_t		t1;
	int				id;
	int				eat_cont;
	int				status;
	int				eating;
	uint64_t		time_to_die;
	pthread_mutex_t	lock;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
}	t_philo;

typedef struct s_args{
	pthread_t		*tid;
	int				number_of_philosophers;
	int				max_meals;
	int				dead_accured;
	int				finished;
	t_philo			*philos;
	u_int64_t		time2die;
	u_int64_t		time2eat;
	u_int64_t		time2sleep;
	u_int64_t		start_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	lock;
	pthread_mutex_t	write;
}   t_args;
// ============================================================================

// prototypes =================================================================
	// parsing.c
	void		parse_args(int ac, char **av, t_args *args);

	// utils
	long		ft_atoi(const char *str);
	u_int64_t	get_time(void);
	int			ft_usleep(useconds_t time);
	void		ft_exit(t_args *data);
	int			error(char *str, t_args *data);

	// init
	int			init(t_args *args);

	// actions
	void		messages(char *str, t_philo *philo);
	void		take_forks(t_philo *philo);
	void		drop_forks(t_philo *philo);
	void		eat(t_philo *philo);

	void		clear_data(t_args	*args);

	// threads
	void		*monitor(void *philo_ptr);
	void		*supervisor(void *philo_ptr);
	void		*routine(void *philo_ptr);
	int			thread_init(t_args *args);
// ============================================================================

#endif
