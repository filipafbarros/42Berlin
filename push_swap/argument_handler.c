/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fibarros <fibarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 10:17:32 by fibarros          #+#    #+#             */
/*   Updated: 2024/05/03 14:46:22 by fibarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_args(int ac, char **av)
{
	int	i;
	int	zero;

	i = 1;
	zero = 0;
	if (ac == 2)
		i = 0;
	while (av[i])
	{
		if (!is_number(av[i]))
			return (0);
		zero += is_zero(av[i]);
		i++;
	}
	if (zero > 1)
		return (0);
	if (is_duplicate(av))
		return (0);
	return (1);
}

int	is_number(char *str)
{
	int	i;

	i = 0;
	if (is_sign(str[i]) && (str[i + 1] != '\0'))
		i++;
	while (str[i] && ft_isdigit(str[i]))
		i++;
	if (str[i] != '\0' && !ft_isdigit(str[i]))
		return (0);
	return (1);
}

int	is_sign(char c)
{
	return (c == '+' || c == '-');
}

int	is_zero(char *str)
{
	int	i;

	i = 0;
	if (is_sign(str[i]) && str[i + 1] != '\0')
		i++;
	while (str[i] != '\0' && str[i] == '0')
		i++;
	if (str[i] == '\0')
		return (1);
	return (0);
}

int	is_duplicate(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[i])
	{
		j = 0;
		while (av[j])
		{
			if (j != i && nbr_strcmp(av[i], av[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
