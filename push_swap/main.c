/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fibarros <fibarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 10:38:05 by fibarros          #+#    #+#             */
/*   Updated: 2024/05/04 16:55:54 by fibarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_node		*a;
	t_node		*b;

	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
	if (ac == 2)
		av = ft_split(av[1], ' ');
	if (!check_args(ac, av))
		exit_error(NULL, NULL);
	b = NULL;
	a = NULL;
	init_stack_a(&a, ac, av);
	push_swap(&a, &b);
}

void	push_swap(t_node **a, t_node **b)
{
	int	len;

	len = stack_len(*a);
	if (len == 2 && !is_sorted(a))
		sa(a);
	else if (len == 3)
		sort_small(a);
	else if (len > 3 && !is_sorted(a))
		sort_big(a, b);
}
