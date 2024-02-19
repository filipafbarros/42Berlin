/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fibarros <fibarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 09:53:48 by fibarros          #+#    #+#             */
/*   Updated: 2024/02/12 13:46:34 by fibarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack_node *stack)
{
	while (stack != NULL)
	{
		ft_printf("%d", stack->value);
		stack = stack->next;
		ft_printf("\n");
	}
}

int	stack_len(t_stack_node *stack)
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

t_stack_node	*find_max(t_stack_node *stack)
{
	int				i;
	t_stack_node	*highest_node;

	i = INT_MIN;
	if (stack == NULL)
		return (NULL);
	while (stack)
	{
		if (stack->value > i)
		{
			i = stack->value;
			highest_node = stack;
		}
		stack = stack->next;
	}
	return (highest_node);
}

t_stack_node	*find_min(t_stack_node *stack)
{
	int				i;
	t_stack_node	*smallest_node;

	i = INT_MIN;
	if (stack == NULL)
		return (NULL);
	while (stack)
	{
		if (stack->value < i)
		{
			i = stack->value;
			smallest_node = stack;
		}
		stack = stack->next;
	}
	return (smallest_node);
}

bool	is_sorted(t_stack_node **a)
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
