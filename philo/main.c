/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fibarros <fibarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 08:42:49 by fibarros          #+#    #+#             */
/*   Updated: 2024/05/28 16:52:08 by fibarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data	*data;

	data = NULL;
	if (ac < 5 || ac > 6)
		error_handler("invalid argument number");
	if (!check_args(ac, av))
		error_handler("invalid input in args");
	data = malloc(sizeof(t_data));
	if (data == NULL)
		error_handler("memory allocation failed");
	if (init_all(data, ac, av) == 1)
	{
		destroy_all(data, "error with initializing");
		free(data);
		return (1);
	}
	simulation(data);
	destroy_all(data, NULL);
	free(data);
	return (0);
}

void	destroy_all(t_data *data, char *error_message)
{
	int	i;

	i = 0;
	while (i < data->num_philos)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&data->dead_lock);
	pthread_mutex_destroy(&data->write_lock);
	pthread_mutex_destroy(&data->meal_lock);
	free(data->forks);
	free(data->philos);
	if (error_message)
		error_handler(error_message);
}
