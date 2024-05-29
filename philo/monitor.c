/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fibarros <fibarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:51:52 by fibarros          #+#    #+#             */
/*   Updated: 2024/05/29 18:11:14 by fibarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*monitor(void *pointer)
{
	int		i;
	t_data	*data;

	data = (t_data *)pointer;
	while (1)
	{
		i = -1;
		while (i++ < data->num_philos)
		{
			pthread_mutex_lock(&data->meal_lock);
			if (get_timestamp() - (data->philos[i].last_meal) > data->t_die)
			{
				print_status("has died", &data->philos[i], data->philos[i].id);
				data->is_dead = true;
				pthread_mutex_unlock(&data->meal_lock);
				return (NULL);
			}
			pthread_mutex_unlock(&data->meal_lock);
		}
		if (all_philos_done_eating(data) == 1)
			return (NULL);
	}
	return (NULL);
}

int	all_philos_done_eating(t_data *data)
{
	int	i;
	int	done_eating;

	i = 0;
	done_eating = 0;
	if (data->num_meals == -1)
		return (0);
	while (i < data->num_philos)
	{
		pthread_mutex_lock(&data->meal_lock);
		if (data->philos[i].meals_eaten >= data->num_meals)
			done_eating++;
		pthread_mutex_unlock(&data->meal_lock);
		i++;
	}
	if (done_eating == data->num_philos)
	{
		pthread_mutex_lock(&data->dead_lock);
		data->is_dead = true;
		pthread_mutex_unlock(&data->dead_lock);
		return (1);
	}
	return (0);
}
