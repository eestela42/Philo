#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <pthread.h>

typedef struct	s_philo
{
	int	name;
	int	eaten;
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;

	int	tt_die;
	int	tt_eat;
	int	tt_sleep;
	int	nbr_eat;
	struct s_philo	*next;
}				t_philo;

typedef struct	s_main
{
	int	nbr_philo;
	int	tt_die;
	int	tt_eat;
	int	tt_sleep;
	int	nbr_eat;
	pthread_mutex_t **tab;
	struct s_philo	*first;
}				t_main;

int		ft_parsing(int ac, char **av, t_main *main);
int		ft_init_mutex(t_main *main);
int		ft_init_philo(t_main *main);





#endif
