/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 16:52:20 by user42            #+#    #+#             */
/*   Updated: 2022/01/23 18:20:33 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	long int nbr;
	int i;
	int sign;

	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' ||
		str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	sign = 1;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	nbr = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (sign == -1)
			nbr = nbr * 10 - (str[i] - 48);
		if (sign == 1)
			nbr = nbr * 10 + (str[i] - 48);
		i++;
	}
	if (nbr < -2147483648 || nbr > 2147483647)
		return(0);
	return (nbr);
}

int	check_is_num(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	while (str[i] && str[i] == ' ')
		i++;
	if (str[i])
		return(0);
	i = 0;
	if (!ft_atoi(str) || ft_atoi(str) < 0)
	{
		while (str[i])
		{
			if (str[i] != '0' && str[i] != ' ' && str[i] != '+'
				&& str[i] != '-')
				return (0);
			i++;
		}
	}
	return (1);
}

int	ft_parsing(int ac, char **av, t_main *main)
{
	int	tab[5];
	int	i;

	i = 1;
	while (i < ac)
	{
		if (!check_is_num(av[i]))
			return(-1);
		tab[i - 1] = ft_atoi(av[i]);
		i++;
	}
	if ( ac == 5)
		tab[4] = -1;
	i = 0;
	main->nbr_philo = tab[0];
	main->tt_die = tab[1];
	main->tt_eat = tab[2];
	main->tt_sleep = tab[3];
	main->nbr_eat = tab[4];
	if (main->nbr_philo == 0)
		return(-1);
	return(0);
}