/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fibarros <fibarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 10:09:08 by fibarros          #+#    #+#             */
/*   Updated: 2024/05/29 18:09:45 by fibarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_status(char *status, t_philo *philo, int id)
{
	size_t	time;

	if (pthread_mutex_lock(&philo->data->write_lock) != 0)
		printf("Debug: failed to lock write_lock");
	time = get_timestamp() - philo->data->t_start;
	if (!philo->data->is_dead)
		printf("%zu %d %s\n", time, id, status);
	if (pthread_mutex_unlock(&philo->data->write_lock) != 0)
		printf("Debug: failed to unlock write_lock");
}

void	is_sleeping(t_philo *philo)
{
	print_status("is sleeping", philo, philo->id);
	ft_usleep(philo->data->t_sleep);
}

void	is_thinking(t_philo *philo)
{
	print_status("is thinking", philo, philo->id);
}

void	is_eating(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	print_status("has picked up right fork", philo, philo->id);
	if (philo->data->num_philos == 1)
	{
		ft_usleep(philo->data->t_die);
		pthread_mutex_unlock(philo->r_fork);
		return ;
	}
	pthread_mutex_lock(philo->l_fork);
	print_status("has picked up left fork", philo, philo->id);
	pthread_mutex_lock(&philo->data->meal_lock);
	philo->is_eating = true;
	print_status("is eating", philo, philo->id);
	philo->last_meal = get_timestamp();
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->data->meal_lock);
	ft_usleep(philo->data->t_eat);
	philo->is_eating = false;
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}

void	*routine(void *pointer)
{
	t_philo	*philo;

	philo = (t_philo *)pointer;
	if (philo->id % 2 == 0)
		ft_usleep(1);
	while (death_loop(philo) != 1)
	{
		is_eating(philo);
		is_sleeping(philo);
		is_thinking(philo);
	}
	return (pointer);
}

// void	*routine(void *pointer)
// {
// 	t_philo	*philo;
// 	t_data	*data;

// 	philo = (t_philo *)pointer;
// 	data = philo->data;
// 	if (philo->id % 2 == 0)
// 		ft_usleep(1);
// 	while (!data->is_dead)
// 	{
// 		is_eating(philo);
// 		is_sleeping(philo);
// 		is_thinking(philo);
// 	}
// 	return (pointer);
// }


/*

void	is_eating(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	print_status("has picked up right fork", philo, philo->id);
	if (philo->data->num_philos == 1)
	{
		ft_usleep(philo->data->t_die);
		pthread_mutex_unlock(philo->r_fork);
		return ;
	}
	pthread_mutex_lock(philo->l_fork);
	print_status("has picked up left fork", philo, philo->id);
	philo->is_eating = true;
	pthread_mutex_lock(&philo->data->meal_lock);
	philo->last_meal = get_timestamp();
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->data->meal_lock);
	print_status("is eating", philo, philo->id);
	ft_usleep(philo->data->t_eat);
	philo->is_eating = false;
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
	print_status("is sleeping", philo, philo->id);
	ft_usleep(philo->data->t_sleep);
	print_status("is thinking", philo, philo->id);
}*/