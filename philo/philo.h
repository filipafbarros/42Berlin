/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fibarros <fibarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 08:42:53 by fibarros          #+#    #+#             */
/*   Updated: 2024/05/24 11:12:06 by fibarros         ###   ########.fr       */
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

typedef struct s_data	t_data;

typedef struct s_philo
{
	pthread_t			thread;
	int					id;
	int					meals_eaten;
	bool				is_eating;
	size_t				last_meal;
	t_data				*data;
	pthread_mutex_t		*l_fork;
	pthread_mutex_t		*r_fork;
}	t_philo;


struct s_data
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
};

/* Utils */
int			ft_atoi(char *str);
void		error_handler(char *error);
int			is_digit(char c);
size_t		get_timestamp(void);

/* Argument handling */
int			check_args(int ac, char **av);
int			is_num(char *av);

/* Initialization */
void		init_input(t_data *data, int ac, char **av);
void		init_forks(t_data *data);
void		init_philos(t_data *data);
int			init_all(t_data *data, int ac, char **av);

/* testing */
// void 		print_philosophers(t_philo *philos, int num_philos);

#endif