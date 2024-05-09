/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fibarros <fibarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 10:38:05 by fibarros          #+#    #+#             */
/*   Updated: 2024/05/09 16:32:39 by fibarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_node		*a;
	t_node		*b;
	char		**argv;

	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (0);
	if (ac == 2)
		argv = ft_split(av[1], ' ');
	else
		argv = av;
	if (!check_args(ac, argv))
	{
		if (ac == 2)
			free_args(argv);
		exit_error(NULL, NULL);
	}
	b = NULL;
	a = NULL;
	init_stack_a(&a, ac, argv);
	push_swap(&a, &b);
	if (ac == 2)
		free_args(argv);
	free_stack(&a);
	free_stack(&b);
}

void	push_swap(t_node **a, t_node **b)
{
	int	len;

	len = stack_len(*a);
	if (is_sorted(a))
		return ;
	if (len == 2)
		sa(a);
	else if (len == 3)
		sort_small(a);
	else if (len > 3)
		sort_big(a, b);
}

void	final_sort(t_node **a)
{
	int		stack_size;

	stack_size = stack_len(*a);
	while ((*a)->pos != find_small_indx_node(*a)->pos)
	{
		if (find_small_indx_node(*a)->above_median)
			ra(a);
		else
			rra(a);
	}
}

void	free_args(char **av)
{
	int	i;

	i = 0;
	if (!av)
		return ;
	while (av[i])
	{
		free(av[i]);
		i++;
	}
	free(av);
}
