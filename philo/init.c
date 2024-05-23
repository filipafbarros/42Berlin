/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fibarros <fibarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 09:26:49 by fibarros          #+#    #+#             */
/*   Updated: 2024/05/23 17:02:54 by fibarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_input(t_data *data, int ac, char **av)
{
	data->num_philos = ft_atoi(av[1]);
	data->t_die = ft_atoi(av[2]);
	data->t_eat = ft_atoi(av[3]);
	data->t_sleep = ft_atoi(av[4]);
	data->num_meals = -1;
	if (ac == 6)
		data->num_meals = ft_atoi(av[5]);
	return (0);
}

int	init_forks(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philos)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
	data->philos[0].l_fork = &data->forks[0];
	data->philos[0].r_fork = &data->forks[data->num_philos - 1];
	i = 0;
	while (i < data->num_philos)
	{
		data->philos[i].l_fork = &data->forks[i];
		data->philos[i].r_fork = &data->forks[i - 1];
		i++;
	}
	return (0);
}

int	init_philos(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philos)
	{
		data->philos[i].id = i + 1;
		data->philos[i].meals_eaten = 0;
		data->philos[i].is_eating = 0;
		data->philos[i].data = data;
		i++;
	}
	return (0);
}

void	init_all(t_data *data, int ac, char **av)
{
	init_input(data, ac, av);
	data->philos = malloc(sizeof(t_philo) * data->num_philos);
	if (data->philos == NULL)
		return (1);
	init_philos(data);
	init_forks(data);
	data->t_start = get_timestamp();
	pthread_mutex_init(&(data->write_lock), NULL);
	pthread_mutex_init(&(data->meal_lock), NULL);
	pthread_mutex_init(&(data->dead_lock), NULL);
	return (0);
}
