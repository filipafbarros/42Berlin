/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filipa <filipa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 10:38:05 by fibarros          #+#    #+#             */
/*   Updated: 2024/03/20 11:32:22 by filipa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	// int				i;

	a = NULL;
	// i = 0;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (0);
	// if (!input_valid(argv))
	// 	exit_error();
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	init_stack_a(&a, argv);

	while (!is_sorted(&a))
	{
		if (stack_len(a) == 2)
			sa(&a);
		else if (stack_len(a) == 3)
			sort_small(&a);
		else
			sort_big(&a, &b);
	}
	// free_stack(&a);
	// free_stack(&b);
}
