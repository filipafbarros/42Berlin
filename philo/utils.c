/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filipa <filipa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 10:20:22 by filipa            #+#    #+#             */
/*   Updated: 2024/05/17 10:00:41 by filipa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
	atoi
	get timestamp
	improved usleep
*/

/* Add sign? Add spaces? Add for '- and +' ?*/
int	ft_atoi(char *str)
{
	int	i;
	int	result;

	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result);
}
