/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_mutex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 17:32:22 by user42            #+#    #+#             */
/*   Updated: 2022/01/26 03:06:44 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_init_mutex(t_main *main)
{
	int	i;

	main->forks = malloc(sizeof(pthread_mutex_t) * main->nbr_philo);
	if (!main->forks)
		return (-1);
	i = 0;
	while (i < main->nbr_philo)
		pthread_mutex_init(&main->forks[i++], NULL);
	main->philock = malloc(sizeof(pthread_mutex_t) * main->nbr_philo);
	if (!main->philock)
		return (-1);
	i = 0;
	while (i < main->nbr_philo)
		pthread_mutex_init(&main->philock[i++], NULL);
	pthread_mutex_init(&main->lock_death, NULL);
	main->a_death = 0;
	pthread_mutex_init(&main->to_write, NULL);
	return (0);
}

t_philo	*ft_initializer(t_main *main, int name)
{
	t_philo	*tmp;

	tmp = malloc(sizeof(t_philo));
	if (!tmp)
		return (NULL);
	tmp->name = name;
	tmp->eaten = 0;
	tmp->main = main;
	tmp->is_ended = 0;
	tmp->philock = main->philock[name - 1];
	if (!(name % 2))
	{
		tmp->first = &main->forks[(name - 1)];
		tmp->second = &main->forks[(name - 2)];
	}
	else if (name != 1)
	{
		tmp->second = &main->forks[(name - 1)];
		tmp->first = &main->forks[(name - 2)];
	}
	else if (name == 1)
	{
		tmp->first = &main->forks[main->nbr_philo - 1];
		tmp->second = &main->forks[0];
	}
	return (tmp);
}

int	ft_init_philo(t_main *main)
{
	int	i;
	t_philo	*tmp;

	i = 1;
	tmp = ft_initializer(main, 1);
	main->first = tmp;
	while (tmp && i++ < main->nbr_philo)
	{
		tmp->next = ft_initializer(main, i);
		tmp = tmp->next;
	}
	if (!tmp)
		return (-1);
	tmp->next = main->first;
	return (0);
}