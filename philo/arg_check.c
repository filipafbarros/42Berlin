/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filipa <filipa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 10:03:00 by filipa            #+#    #+#             */
/*   Updated: 2024/05/17 09:54:54 by filipa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_args(int ac, char **av)
{

}

/*
	- av[1] - num of philosophers
	- av[2] -time it takes for a philo to die if they dont eat
	- av[3] -time it takes for philo to eat
	- av[4] -time it takes for a philo to sleep
	- av[5] - OPTIONAL:number of times a philo has to eat before terminating the program

	check if input is just numbers
	they should all be bigger than 0 (except num of meals philo has to eat)
	set the limit to 200 philos
*/
