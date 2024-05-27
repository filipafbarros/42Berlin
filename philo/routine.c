/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fibarros <fibarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 10:09:08 by fibarros          #+#    #+#             */
/*   Updated: 2024/05/27 17:32:42 by fibarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_status(char *status, t_philo *philo, int id)
{
	int	time;

	pthread_mutex_lock(&philo->data->write_lock);
	time = get_timestamp() - philo->data->t_start;
	if (!philo->data->is_dead)
		printf("%zu %d %s\n", time, id, status);
	pthread_mutex_unlock(&philo->data->write_lock);
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
	pthread_mutex_lock(&philo->r_fork);
	print_status("has picked up right fork", philo, philo->id);
	if (philo->data->num_philos == 1)
	{
		ft_usleep(philo->data->t_die);
		pthread_mutex_unlock(&philo->r_fork);
		return ;
	}
	pthread_mutex_lock(&philo->l_fork);
	print_status("has picked up left fork", philo, philo->id);
	philo->is_eating = 1;
	print_status("is eating", philo, philo->id);
	pthread_mutex_lock(&philo->data->meal_lock);
	philo->last_meal == get_timestamp();
	philo->meals_eaten++;
	ft_usleep(philo->data->t_eat);
	pthread_mutex_unlock(&philo->data->meal_lock);
	philo->is_eating = 0;
	pthread_mutex_unlock(&philo->r_fork);
	pthread_mutex_unlock(&philo->l_fork);
}

void	*routine(void *pointer)
{
	
}