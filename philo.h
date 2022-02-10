#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct	s_philo
{
	int	name;
	int	eaten;
	int	is_ended;
	long int	l_eat;
	long int	start;
	pthread_mutex_t	*second;
	pthread_mutex_t	*first;
	pthread_mutex_t	philock;
	pthread_t		id;
	struct s_philo	*next;
	struct s_main	*main;
}				t_philo;

typedef struct	s_main
{
	int	nbr_philo;
	int	tt_die;
	int	tt_eat;
	int	tt_sleep;
	int	nbr_eat;
	int	a_death;
	pthread_mutex_t lock_death;
	pthread_mutex_t	to_write;
	pthread_mutex_t	*philock;
	pthread_mutex_t *forks;
	pthread_t		id_check;

	struct s_philo	*first;
}				t_main;

int				ft_parsing(int ac, char **av, t_main *main);
int				ft_init_mutex(t_main *main);
int				ft_init_philo(t_main *main);
int				ft_create_threads(t_main *main);
long int		get_time();
void			say(char *str, t_philo *philo, long int time, int second);
void			*routine(void *data);
void			*check_death(void *data);
int				ft_end(t_philo *philo, int second);
t_philo			*jump(t_philo *philo);
int				locker(pthread_mutex_t *mutex, int check);
int				unlocker(pthread_mutex_t *mutex, int check);







#endif
