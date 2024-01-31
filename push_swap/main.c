/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fibarros <fibarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 10:38:05 by fibarros          #+#    #+#             */
/*   Updated: 2024/01/31 17:10:21 by fibarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	// t_stack_node	*b;

	a = NULL;
	// b = NULL;
	if (argc == 1 || argc == 2 && !argv[1][0])
		return (0);
	else if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
	}
	init_stack_a(&a, argv + 1);
}
