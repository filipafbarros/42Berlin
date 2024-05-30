/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fibarros <fibarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 16:58:09 by fibarros          #+#    #+#             */
/*   Updated: 2024/05/30 15:54:16 by fibarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	*simulation(t_data *data)
{
	int			i;
	pthread_t	monitor_thread;

	i = 0;
	data->t_start = get_timestamp();
	if (pthread_create(&monitor_thread, NULL, &monitor, (void *)data) != 0)
		destroy_all(data, "Thread creation error: monitor thread");
	while (i < data->num_philos)
	{
		if (pthread_create(&data->philos[i].thread, NULL, routine, \
		&data->philos[i]) != 0)
			destroy_all(data, "Thread creation error: Philo thread");
		//ft_usleep(1);
		i++;
	}
	i = 0;
	if (pthread_join(monitor_thread, NULL) != 0)
		destroy_all(data, "Thread join error: monitor thread");
	while (i < data->num_philos)
	{
		if (pthread_join(data->philos[i].thread, NULL) != 0)
			destroy_all(data, "Thread join error: philo thread");
		i++;
	}
	return (0);
}
