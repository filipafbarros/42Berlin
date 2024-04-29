/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atof.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fibarros <fibarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 10:41:10 by fibarros          #+#    #+#             */
/*   Updated: 2024/04/22 16:34:03 by fibarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	space_sign(char *str, int *is_neg)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			*is_neg *= -1;
		i++;
	}
	return (i);
}

double	ft_atof(char *str)
{
	double	result;
	int		i;
	double	div;
	int		sign;

	result = 0;
	div = 0.1;
	sign = 1;
	i = space_sign(str, &sign);
	while (str[i] && str[i] >= '0' && str[i] <= '9' && str[i] != '.')
	{
		result = result * 10.0 + (str[i] - '0');
		i++;
	}
	if (str[i] == '.')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		result = result + ((str[i] - '0') * div);
		div *= 0.1;
		i++;
	}
	return (result * sign);
}
