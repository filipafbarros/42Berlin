/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fibarros <fibarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 10:20:22 by fibarros          #+#    #+#             */
/*   Updated: 2024/05/28 14:31:57 by fibarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(char *str)
{
	int	i;
	int	result;

	result = 0;
	i = 0;
	while (is_digit(str[i]))
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

int	ft_usleep(size_t miliseconds)
{
	uint64_t	start;

	start = get_timestamp();
	while (get_timestamp() - start < miliseconds)
		usleep(500);
	return (0);
}
