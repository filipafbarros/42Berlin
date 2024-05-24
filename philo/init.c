/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fibarros <fibarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 09:26:49 by fibarros          #+#    #+#             */
/*   Updated: 2024/05/24 11:02:02 by fibarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_input(t_data *data, int ac, char **av)
{
	data->num_philos = ft_atoi(av[1]);
	data->t_die = ft_atoi(av[2]);
	data->t_eat = ft_atoi(av[3]);
	data->t_sleep = ft_atoi(av[4]);
	data->num_meals = -1;
	if (ac == 6)
		data->num_meals = ft_atoi(av[5]);
}

void	init_forks(t_data *data)
{
	int	i;

	i = 0;
	data->forks = malloc(sizeof(pthread_mutex_t) * data->num_philos);
	if (data->forks == NULL)
		error_handler("Failed to allocate memory for forks");
	while (i < data->num_philos)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
}

void	init_philos(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philos)
	{
		data->philos[i].id = i + 1;
		data->philos[i].meals_eaten = 0;
		data->philos[i].is_eating = false;
		data->philos[i].data = data;
		data->philos[i].last_meal = get_timestamp();
		data->philos[i].l_fork = &data->forks[i];
		data->philos[i].r_fork = &data->forks[(i + 1) % data->num_philos];
		i++;
	}
}

int	init_all(t_data *data, int ac, char **av)
{
	init_input(data, ac, av);
	data->philos = malloc(sizeof(t_philo) * data->num_philos);
	if (data->philos == NULL)
		return (1);
	init_forks(data);
	init_philos(data);
	data->t_start = get_timestamp();
	pthread_mutex_init(&(data->write_lock), NULL);
	pthread_mutex_init(&(data->meal_lock), NULL);
	pthread_mutex_init(&(data->dead_lock), NULL);
	return (0);
}
