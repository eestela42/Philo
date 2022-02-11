/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lockers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestela <eestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 19:48:00 by eestela           #+#    #+#             */
/*   Updated: 2022/02/11 19:49:42 by eestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	locker(pthread_mutex_t *mutex, int check)
{
	if (check)
		return (0);
	pthread_mutex_lock(mutex);
	return (1);
}

int	unlocker(pthread_mutex_t *mutex, int check)
{
	if (check)
		return (0);
	pthread_mutex_unlock(mutex);
	return (1);
}
