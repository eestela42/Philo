/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 14:18:15 by user42            #+#    #+#             */
/*   Updated: 2022/02/11 15:57:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *check_death(void *data)
{
	t_philo *philo;
	int 	philo_full;

	philo_full = 0;
	philo = (t_philo *)data;
	while (!philo->main->a_death)
	{
		pthread_mutex_lock(&philo->philock);
		if (philo->name == 1)
			philo_full = 0;
		if (philo->eaten == philo->main->nbr_eat)
			philo_full++;
		if (((philo->main->tt_die < (get_time() - philo->l_eat))
			&& (philo->eaten != philo->main->nbr_eat))
			|| (philo_full == philo->main->nbr_philo))
		{
			pthread_mutex_lock(&philo->main->lock_death);
			philo->main->a_death = 1;
			pthread_mutex_unlock(&philo->main->lock_death);
			if (philo_full != philo->main->nbr_philo)
				say("died", philo, get_time() - philo->start, -1);
		}
		pthread_mutex_unlock(&philo->philock);
		if (!philo->main->a_death)
			philo = philo->next;
	}
	//printf("check is ended\n");
	return (NULL);
}

void *routine(void *data)
{
	t_philo *philo;

	philo = (t_philo *)data;
	while (!philo->is_ended && philo->eaten != philo->main->nbr_eat)
	{
		if (philo->main->nbr_philo == 1)
		{
			say("has taken a fork", philo, get_time() - philo->start, -1);
			philo->is_ended = 1;
		}
		locker(philo->first, philo->is_ended);
		say("has taken a fork", philo, get_time() - philo->start, 1);
		locker(philo->second, philo->is_ended);
		say("has taken a fork", philo, get_time() - philo->start, 2);
		say("is eating", philo, get_time() - philo->start, 2);
		locker(&philo->philock, philo->is_ended);
		if (!philo->is_ended)
		{
			philo->l_eat = get_time();
			philo->eaten++;
		}
		unlocker(&philo->philock, philo->is_ended);
		usleep(philo->main->tt_eat * 1000);
		unlocker(philo->first, philo->is_ended);
		unlocker(philo->second, philo->is_ended);
		say("is sleeping", philo, get_time() - philo->start, 0);
		usleep(philo->main->tt_sleep * 1000);
		say("is thinking", philo, get_time() - philo->start, 0);
		usleep(2000);
	}
	//printf("%i has eaten %i times \n", philo->name, philo->eaten);
	return (NULL);
}