/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fibarros <fibarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:51:52 by fibarros          #+#    #+#             */
/*   Updated: 2024/05/30 17:37:39 by fibarros         ###   ########.fr       */
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

void	*monitor(void *pointer)
{
	int		i;
	t_data	*data;
	int		done_eating;

	data = (t_data *)pointer;
	done_eating = 0;
	i = -1;
	while (i++ < data->num_philos)
	{
		while (!data->is_dead)
		{
			pthread_mutex_lock(&data->dead_lock);
			if (get_timestamp() - (data->philos[i].last_meal) > data->t_die && (!data->philos[i].is_eating))
			{
				print_status("died", &data->philos[i]);
				data->is_dead = true;
			}
			pthread_mutex_unlock(&data->dead_lock);
			if (data->num_meals != -1 && data->philos[i].meals_eaten >= data->num_meals)
				done_eating++;
			all_philos_done_eating(data, done_eating);
		}
	}
	return (NULL);
}

void	all_philos_done_eating(t_data *data, int done_eating)
{
	pthread_mutex_lock(&data->dead_lock);
	if (done_eating == data->num_philos)
		data->is_dead = true;
	pthread_mutex_unlock(&data->dead_lock);
}


// void	*monitor(void *pointer)
// {
// 	int		i;
// 	t_data	*data;

// 	data = (t_data *)pointer;
// 	while (1)
// 	{
// 		i = -1;
// 		while (i++ < data->num_philos)
// 		{
// 			pthread_mutex_lock(&data->meal_lock);
// 			if (get_timestamp() - (data->philos[i].last_meal) > data->t_die)
// 			{
// 				print_status("has died", &data->philos[i], data->philos[i].id);
// 				data->is_dead = true;
// 				pthread_mutex_unlock(&data->meal_lock);
// 				return (NULL);
// 			}
// 			pthread_mutex_unlock(&data->meal_lock);
// 		}FATAL: ThreadSanitizer: unexpected memory mapping 0x768bfe8ae000-0x768bfed00000
// 		if (all_philos_done_eating(data) == 1)
// 			return (NULL);
// 	}
// 	return (NULL);
// }
