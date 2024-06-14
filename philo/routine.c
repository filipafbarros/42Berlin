/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fibarros <fibarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 10:09:08 by fibarros          #+#    #+#             */
/*   Updated: 2024/06/14 13:03:22 by fibarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	is_sleeping(t_philo *philo)
{
	print_status("is sleeping", philo);
	ft_usleep(philo->data->t_sleep);
}

void	is_thinking(t_philo *philo)
{
	size_t	time;

	print_status("is thinking", philo);
	time = philo->data->t_die - philo->data->t_eat - philo->data->t_sleep;
	if (!death_check(philo->data))
	{
		if ((philo->data->num_philos % 2) == 0)
			usleep(10);
		else
		{
			if (time <= 0)
				usleep(900);
			else
				usleep(time * 900);
		}
	}
}

int	grab_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
		pthread_mutex_lock(philo->l_fork);
	else
		pthread_mutex_lock(philo->r_fork);
	print_status("has taken a fork", philo);
	if (philo->data->num_philos == 1)
	{
		ft_usleep(philo->data->t_die);
		pthread_mutex_unlock(philo->r_fork);
		return (0);
	}
	if (philo->id % 2 == 0)
		pthread_mutex_lock(philo->r_fork);
	else
		pthread_mutex_lock(philo->l_fork);
	print_status("has taken a fork", philo);
	return (1);
}

void	is_eating(t_philo *philo)
{
	if (!death_check(philo->data) && grab_forks(philo))
	{
		print_status("is eating", philo);
		pthread_mutex_lock(&philo->data->meal_lock);
		philo->last_meal = get_timestamp();
		philo->meals_eaten += 1;
		philo->is_eating = true;
		pthread_mutex_unlock(&philo->data->meal_lock);
		ft_usleep(philo->data->t_eat);
		pthread_mutex_lock(&philo->data->meal_lock);
		philo->is_eating = false;
		if (philo->data->num_meals != -1 && philo->meals_eaten >= \
		philo->data->num_meals)
			philo->done_eating = true;
		pthread_mutex_unlock(&philo->data->meal_lock);
		pthread_mutex_unlock(philo->r_fork);
		pthread_mutex_unlock(philo->l_fork);
	}
}

void	*routine(void *pointer)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)pointer;
	data = philo->data;
	if (philo->id % 2 == 0)
		ft_usleep(1);
	while (!death_check(data))
	{
		is_eating(philo);
		is_sleeping(philo);
		is_thinking(philo);
	}
	return (pointer);
}
