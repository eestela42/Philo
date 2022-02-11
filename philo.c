/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestela <eestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 17:32:19 by user42            #+#    #+#             */
/*   Updated: 2022/02/11 19:55:45 by eestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_destroy2(t_main *main)
{
	int		i;
	t_philo	*tmp;
	t_philo	*next;

	if (main->philock)
	{
		i = 0;
		while (i < main->nbr_philo)
			pthread_mutex_destroy(&main->philock[i++]);
		free(main->philock);
		if (main->first)
		{
			tmp = main->first->next;
			while (tmp != main->first)
			{
				next = tmp->next;
				free(tmp);
				tmp = next;
			}
			free(main->first);
		}
	}
}

int	free_destroy(t_main *main, int secu)
{
	int		i;

	if (main)
	{
		if (secu != -9 && main->forks)
		{
			i = 0;
			while (i < main->nbr_philo)
				pthread_mutex_destroy(&main->forks[i++]);
			free_destroy2(main);
			pthread_mutex_destroy(&main->to_write);
			free(main->forks);
		}
		free(main);
	}
	return (11);
}

int	main(int ac, char **av)
{
	int		secu;
	t_main	*main;

	main = NULL;
	if (ac != 5 && ac != 6)
		return (1);
	main = malloc(sizeof(t_main));
	if (!main)
		return (1);
	secu = 0;
	secu = ft_parsing(ac, av, main);
	if (!secu)
		secu = ft_init_mutex(main);
	if (!secu)
		secu = ft_init_philo(main);
	if (!secu)
		secu = ft_create_threads(main);
	free_destroy(main, secu);
	return (0);
}
