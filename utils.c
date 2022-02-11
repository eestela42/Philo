/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestela <eestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 13:53:00 by user42            #+#    #+#             */
/*   Updated: 2022/02/11 19:49:05 by eestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long int	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((long int)time.tv_sec * 1000 + (long int)time.tv_usec / 1000);
}

void	say(char *str, t_philo *philo, long int time, int forks)
{
	if (ft_end(philo, forks))
		return ;
	pthread_mutex_lock(&philo->main->to_write);
	printf("%li %i %s\n", time, philo->name, str);
	pthread_mutex_unlock(&philo->main->to_write);
}

int	ft_end(t_philo *philo, int forks)
{
	if (forks == -1)
		return (0);
	if (philo->is_ended)
		return (1);
	pthread_mutex_lock(&philo->main->lock_death);
	if (philo->main->a_death)
	{
		pthread_mutex_unlock(&philo->main->lock_death);
		if (forks == 1 || forks == 2)
			pthread_mutex_unlock(philo->first);
		if (forks == 2)
			pthread_mutex_unlock(philo->second);
		philo->is_ended = 1;
		return (1);
	}
	pthread_mutex_unlock(&philo->main->lock_death);
	return (0);
}

t_philo	*jump(t_philo *philo)
{
	int	i;

	i = 0;
	while (i != 2 && philo)
	{
		if (philo->next != philo->main->first)
			philo = philo->next;
		else
			return (NULL);
		i++;
	}
	return (philo);
}
