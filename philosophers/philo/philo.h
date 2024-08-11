#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>


typedef struct s_arg
{
	int						total_philosophers;
	int						time2die;
	int						time2eat;
	int						time2sleep;
	int						max_eat;
	long int				start_time;
	pthread_mutex_t			write_mutex;
	pthread_mutex_t			dead_mutex;
	pthread_mutex_t			time_eat_mutex;
	pthread_mutex_t			finish_mutex;
	int						finished_philosophers;
	int						should_stop; // 0 if none philosopher is dead, 1 if a philosopher is dead, 2 if all philosophers ate m_eat times
}							t_arg;

typedef struct s_philo
{
	int						id;
	pthread_t				thread_id;
	pthread_t				thread_death_id; // id of the thread monitoring death
	pthread_mutex_t			*right_fork;
	pthread_mutex_t			left_fork;
	t_arg					*args;
	long int				last_eat;
	unsigned int			number_of_meals;
	int						finish; // 1 when a philosopher ate m_eat times, if not, 0
}							t_philo;

typedef	struct          s_pogram
{
	t_philo               *philos;              // structure for each philosopher
	t_arg                 args;                // structure with arguments, same for all philosophers
}					   t_program;

int				parse_args(int argc, char **argv, t_program *prog);
int				initialize(t_program *prog);
int				ft_exit(char *str);
void			write_status(char *str, t_philo *philo);
long int		actual_time(void);
void			ft_putstr_fd(char *s, int fd);
void			ft_usleep(long int time_in_ms);
int				threading(t_program *prog);
void			activity(t_philo *philo);
int				check_death(t_philo *philo, int i);
int				ft_strlen(char *str);

#endif