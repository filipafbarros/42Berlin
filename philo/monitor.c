/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fibarros <fibarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:51:52 by fibarros          #+#    #+#             */
/*   Updated: 2024/06/14 12:58:30 by fibarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	death_check(t_data *data)
{
	pthread_mutex_lock(&data->dead_lock);
	if (data->is_dead)
	{
		pthread_mutex_unlock(&data->dead_lock);
		return (1);
	}
	pthread_mutex_unlock(&data->dead_lock);
	return (0);
}

int	philo_died(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->meal_lock);
	if (get_timestamp() - philo->last_meal >= philo->data->t_die \
	&& !philo->is_eating)
	{
		pthread_mutex_unlock(&philo->data->meal_lock);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->meal_lock);
	return (0);
}

void	*monitor(void *pointer)
{
	int		i;
	t_data	*data;

	data = (t_data *)pointer;
	while (!death_check(data))
	{
		i = -1;
		while (++i < data->num_philos)
		{
			if (philo_died(&data->philos[i]))
			{
				print_status("died", &data->philos[i]);
				turn_dead(data);
			}
			all_philos_done_eating(data);
		}
	}
	return (pointer);
}

void	turn_dead(t_data *data)
{
	pthread_mutex_lock(&data->dead_lock);
	data->is_dead = true;
	pthread_mutex_unlock(&data->dead_lock);
}

int	all_philos_done_eating(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philos)
	{
		pthread_mutex_lock(&data->meal_lock);
		if (!data->philos[i].done_eating)
		{
			pthread_mutex_unlock(&data->meal_lock);
			return (0);
		}
		pthread_mutex_unlock(&data->meal_lock);
		i++;
	}
	turn_dead(data);
	return (1);
}
