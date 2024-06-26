/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fibarros <fibarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 16:58:09 by fibarros          #+#    #+#             */
/*   Updated: 2024/06/14 11:31:32 by fibarros         ###   ########.fr       */
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
		i++;
	}
	i = 0;
	while (i < data->num_philos)
	{
		if (pthread_join(data->philos[i].thread, NULL) != 0)
			destroy_all(data, "Thread join error: philo thread");
		i++;
	}
	if (pthread_join(monitor_thread, NULL) != 0)
		destroy_all(data, "Thread join error: monitor thread");
	return (0);
}

void	print_status(char *status, t_philo *philo)
{
	size_t	time;

	if (pthread_mutex_lock(&philo->data->write_lock) != 0)
		printf("Debug: failed to lock write_lock");
	time = get_timestamp() - philo->data->t_start;
	if (!death_check(philo->data))
		printf("%zu %d %s\n", time, philo->id, status);
	if (pthread_mutex_unlock(&philo->data->write_lock) != 0)
		printf("Debug: failed to unlock write_lock");
}
