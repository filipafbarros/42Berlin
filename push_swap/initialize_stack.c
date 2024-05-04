/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fibarros <fibarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 09:49:46 by fibarros          #+#    #+#             */
/*   Updated: 2024/05/04 16:54:31 by fibarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack_a(t_node **a, int ac, char **av)
{
	long		nbr;
	int			i;
	int			len;		

	i = 1;
	if (ac == 2)
		i = 0;
	while (av[i])
	{
		nbr = ft_atol(av[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			exit_error(a, NULL);
		append_node(a, (int)nbr);
		i++;
	}
	len = stack_len(*a) + 1;
	assign_index(*a, len);
}

void	append_node(t_node **stack, int n)
{
	t_node	*node;
	t_node	*last_node;

	if (stack == NULL)
		return ;
	node = malloc(sizeof(t_node));
	if (node == NULL)
		return ;
	node->value = n;
	node->index = 0;
	node->next = NULL;
	if (*stack == NULL)
	{
		*stack = node;
		node->prev = NULL;
		return ;
	}
	last_node = *stack;
	while (last_node->next != NULL)
		last_node = last_node->next;
	last_node->next = node;
	node->prev = last_node;
}

long	ft_atol(const char *str)
{
	long	nbr;
	int		sign;
	int		i;

	nbr = 0;
	i = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = (str[i] - '0') + (nbr * 10);
		i++;
	}
	return (nbr * sign);
}

void	assign_index(t_node *stack_a, int stack_len)
{
	t_node		*node;
	t_node		*highest_node;
	int			value;

	while (--stack_len > 0)
	{
		node = stack_a;
		value = INT_MIN;
		highest_node = NULL;
		while (node)
		{
			if (node->value == INT_MIN && node->index == 0)
				node->index = 1;
			if (node->value > value && node->index == 0)
			{
				value = node->value;
				highest_node = node;
				node = stack_a;
			}
			node = node->next;
		}
		if (highest_node != NULL)
			highest_node->index = stack_len;
	}
}
