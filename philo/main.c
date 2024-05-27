/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fibarros <fibarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 08:42:49 by fibarros          #+#    #+#             */
/*   Updated: 2024/05/27 16:10:24 by fibarros         ###   ########.fr       */
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
		free(data->philos);
		free(data);
		error_handler("memory allocation failed");
	}
	free(data->philos);
	free(data);
}

// check args
// init vars

// void print_philosophers(t_philo *philos, int num_philos) {
//     for (int i = 0; i < num_philos; i++) {
//         printf("Philosopher %d:\n", i);
//         printf("Thread ID: %lu\n", philos[i].thread);
//         printf("ID: %d\n", philos[i].id);
//         printf("Meals eaten: %d\n", philos[i].meals_eaten);
//         printf("Is eating: %s\n", philos[i].is_eating ? "true" : "false");
//         printf("Last meal: %zu\n", philos[i].last_meal);
//         printf("Data pointer: %p\n", (void *)philos[i].data);
//         printf("Left fork: %p\n", (void *)philos[i].l_fork);
//         printf("Right fork: %p\n", (void *)philos[i].r_fork);
//     }
// }