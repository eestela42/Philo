/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_mutex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 17:32:22 by user42            #+#    #+#             */
/*   Updated: 2022/01/23 18:41:31 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_init_mutex(t_main *main)
{
	int	i;

	main->tab = malloc(sizeof(pthread_mutex_t *) * main->nbr_philo);
	if (!main->tab)
		return (-1);
	i = 0;
	while (i < main->nbr_philo)
		pthread_mutex_init(main->tab[i++], NULL);
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
	tmp->tt_die = main->tt_die;
	tmp->tt_eat = main->tt_eat;
	tmp->tt_sleep = main->tt_sleep;
	tmp->nbr_eat = main->nbr_eat;
	tmp->right = main->tab[name];
	if (main->nbr_philo > 1)
		tmp->left = main->tab[(name - 2) % main->nbr_philo];
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