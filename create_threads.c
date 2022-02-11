/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 21:25:58 by user42            #+#    #+#             */
/*   Updated: 2022/02/11 02:24:47 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


int	ft_create_threads(t_main *main)
{
	t_philo	*tmp;
	long int	start;
	
	tmp = main->first->next;
	start = get_time();
	while (tmp)
	{
		tmp->start = start;
		tmp->l_eat = start;
		pthread_create(&tmp->id, NULL, routine, (void*)tmp);
		tmp = jump(tmp);
	}
	usleep(2000);
	if (main->nbr_philo > 1)
		tmp = main->first;
	while (tmp)
	{
		tmp->start = start;
		tmp->l_eat = start;
		pthread_create(&tmp->id, NULL, routine, (void*)tmp);
		tmp = jump(tmp);
	}
	pthread_create(&main->id_check, NULL, check_death, (void*)main->first);
	tmp = main->first;
	while (tmp)
	{
		pthread_join(tmp->id, NULL);
		if (tmp->name != main->nbr_philo)
			tmp = tmp->next;
		else
			break ;
	}
	pthread_join(main->id_check, NULL);
	return(0);
}