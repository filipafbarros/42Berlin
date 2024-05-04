/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fibarros <fibarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 09:53:48 by fibarros          #+#    #+#             */
/*   Updated: 2024/05/03 18:01:44 by fibarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_node *stack)
{
	while (stack != NULL)
	{
		ft_printf("%d", stack->value);
		stack = stack->next;
		ft_printf("\n");
	}
}

int	stack_len(t_node *stack)
{
	int	i;

	i = 0;
	while (stack != NULL)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

int	find_max_index(t_node *stack)
{
	int			index;

	if (stack == NULL)
		return (0);
	index = stack->index;
	while (stack)
	{
		if (stack->index > index)
			index = stack->index;
		stack = stack->next;
	}
	return (index);
}

int	find_min_index(t_node *stack)
{
	int			index;

	if (stack == NULL)
		return (0);
	index = stack->index;
	while (stack)
	{
		if (stack->index < index)
			index = stack->index;
		stack = stack->next;
	}
	return (index);
}

bool	is_sorted(t_node **a)
{
	if (a == NULL)
		return (1);
	while ((*a)->next)
	{
		if ((*a)->value > (*a)->next->value)
			return (false);
		*a = (*a)->next;
	}
	return (true);
}
