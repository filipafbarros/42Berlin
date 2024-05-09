/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fibarros <fibarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 09:53:48 by fibarros          #+#    #+#             */
/*   Updated: 2024/05/07 17:20:03 by fibarros         ###   ########.fr       */
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
	int		i;
	t_node	*temp;

	i = 0;
	temp = stack;
	while (temp != NULL)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

t_node	*find_big_indx_node(t_node *stack)
{
	int			max_index;
	t_node		*max_node;

	if (stack == NULL)
		return (0);
	max_index = INT_MIN;
	while (stack)
	{
		if (stack->index > max_index)
		{
			max_index = stack->index;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}

t_node	*find_small_indx_node(t_node *stack)
{
	int		min_index;
	t_node	*min_node;

	min_index = INT_MAX;
	while (stack)
	{
		if (stack->index < min_index)
		{
			min_index = stack->index;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}

bool	is_sorted(t_node **a)
{
	t_node	*temp;

	temp = *a;
	if (a == NULL)
		return (1);
	while (temp->next)
	{
		if (temp->value > temp->next->value)
			return (false);
		temp = temp->next;
	}
	return (true);
}
