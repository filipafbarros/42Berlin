/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fibarros <fibarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 10:03:00 by fibarros          #+#    #+#             */
/*   Updated: 2024/05/23 17:54:57 by fibarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_args(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (!is_num(av[i]) || ft_atoi(av[i]) <= 0)
			return (0);
		i++;
	}
	if (ac == 6)
	{
		if (ft_atoi(av[5]) < 1)
			return (0);
	}
	return (1);
}

int	is_num(char *av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (!is_digit(av[i]))
			return (0);
		i++;
	}
	return (1);
}
