/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fibarros <fibarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 08:42:49 by fibarros          #+#    #+#             */
/*   Updated: 2024/05/23 15:59:00 by fibarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	if (ac < 5 || ac > 6)
		error_handler("invalid argument number");
	if (!check_args(ac, av))
		error_handler("invalid input in args");
}

// check args
// init vars
