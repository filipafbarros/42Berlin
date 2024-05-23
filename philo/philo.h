/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fibarros <fibarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 08:42:53 by fibarros          #+#    #+#             */
/*   Updated: 2024/05/23 17:04:13 by fibarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>
# include <stdbool.h>

typedef struct s_philo
{
	pthread_t			thread;
	int					id;
	int					meals_eaten;
	bool				is_eating;
	t_data				*data;
	pthread_mutex_t		*l_fork;
	pthread_mutex_t		*r_fork;
}	t_philo;


typedef struct s_data
{
	int					t_die;
	int					t_sleep;
	int					t_eat;
	int					num_philos;
	int					num_meals;
	t_philo				*philos;
	size_t				t_start;
	pthread_mutex_t		write_lock;
	pthread_mutex_t		dead_lock;
	pthread_mutex_t		meal_lock;
	pthread_mutex_t		*forks;
}	t_data;

/* Utils */
int			ft_atoi(char *str);
void		error_handler(char *error);
int			is_digit(char c);

/* Argument handling */
int			check_args(int ac, char **av);
int			is_num(char *av);


#endif