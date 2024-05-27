/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fibarros <fibarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:51:52 by fibarros          #+#    #+#             */
/*   Updated: 2024/05/27 17:30:18 by fibarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*monitor(t_data	*data)
{
	int		i;

	while (!data->is_dead)
	{
		i = -1;
		while (i++ < data->num_philos)
		{
			if (get_timestamp() - (data->philos[i].last_meal) > data->t_die)
			{
				pthread_mutex_lock(&data->write_lock);
				print_status("has died", &data->philos[i], data->philos[i].id);
				pthread_mutex_unlock(&data->write_lock);
				data->is_dead = true;
				break ;
			}
			if (data->philos[i].meals_eaten == data->num_meals)
			{
				if (all_philos_done_eating(data))
				{
					data->is_dead = true;
					break ;
				}
			}
		}
		usleep(1000);
	}
}

bool	all_philos_done_eating(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philos)
	{
		if (data->philos[i].meals_eaten < data->num_meals)
			return (false);
		i++;
	}
	return (true);
}
