/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 17:32:19 by user42            #+#    #+#             */
/*   Updated: 2022/01/23 18:40:44 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	int		secu;
	t_main	*main;

	main = malloc(sizeof(t_main));
	if (!main || (ac != 5 && ac != 6))
		return (-1);
	secu = 0;
	secu = ft_parsing(ac, av, main);
	secu = ft_init_mutex(main);
	secu = ft_init_philo(main);
	
	int	i;
	t_philo	*tmp;
	tmp = main->first;
	i = 0;
	while (!secu && i <= main->nbr_philo)
	{
		printf("Philo %i \n", tmp->name);
		tmp = tmp->next;
		i++;
	}
	printf("secu = %i\n", secu);
	return(1);
}