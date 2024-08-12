#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h> 
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philosopher
{
	pthread_mutex_t		eating; // mutex for eating
	struct s_program	*prog;	// pointer to the program
	pthread_t			thd_philo; // thread for philosopher
	pthread_t			alive; // thread for checking if philosopher is alive
	int					pid; // philosopher id
	int					left; // left fork
	int					right;	// right fork
	int					meals_count; // number of times philosopher ate
	long long			last_eat_time; // last time philosopher ate
	int					is_eating; // is philosopher eating
}				t_philosopher;

typedef struct s_program
{
	pthread_mutex_t	*forks; // forks
	t_philosopher	**philosopher; // philosophers
	pthread_mutex_t	write; // mutex for writing
	long long		start; // start time
	int				nb_philo; // number of philosophers
	int				death; // is philosopher dead
	int				time_to_die; // time to die
	int				time_to_eat; // time to eat
	int				time_to_sleep; // time to sleep
	int				time_to_think; // time to think
	int				max_meals; // number of times each philosopher must eat
}				t_program;

void			*start_routine(void *data);
void			print_status(t_program *table, int id, char *str);
int				ft_atoi(char *str);
int				is_args_valid(int ac, char **av);
long long		ft_time(void);
t_philosopher	**init_philo(t_program *table);
pthread_mutex_t	*init_fork(t_program *table);

#endif