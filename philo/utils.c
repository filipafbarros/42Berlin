/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fibarros <fibarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 10:20:22 by fibarros          #+#    #+#             */
/*   Updated: 2024/05/23 17:15:37 by fibarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
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

int	is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

void	error_handler(char *error)
{
	printf("%s \n", error);
	exit(EXIT_FAILURE);
}

size_t	get_timestamp(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (((size_t)time.tv_sec * 1000) + time.tv_usec / 1000);
}
