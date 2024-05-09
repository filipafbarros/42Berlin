/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fibarros <fibarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 17:30:15 by fibarros          #+#    #+#             */
/*   Updated: 2024/05/08 16:42:24 by fibarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calculate_cost(t_node **a, t_node **b)
{
	t_node	*temp_a;
	int		len_a;
	int		len_b;
	int		cost;

	temp_a = *a;
	len_a = stack_len(*a);
	len_b = stack_len(*b);
	while (temp_a)
	{
		cost = temp_a->pos;
		if (!(temp_a->above_median))
			cost = len_a - (temp_a->pos);
		if (temp_a->target_node->above_median)
			cost += temp_a->target_node->pos;
		else
			cost += len_b - (temp_a->target_node->pos);
		temp_a->cost = cost;
		temp_a = temp_a->next;
	}
}

void	set_cheapest(t_node *stack)
{
	t_node	*cheapest_node;
	t_node	*temp;
	int		cheapest_cost;

	cheapest_cost = INT_MAX;
	temp = stack;
	while (temp)
	{
		if (temp->cost < cheapest_cost)
		{
			cheapest_cost = temp->cost;
			cheapest_node = temp;
		}
		temp = temp->next;
	}
	cheapest_node->is_cheapest = true;
}

t_node	*find_cheapest(t_node *stack)
{
	t_node	*temp;

	temp = stack;
	while (temp)
	{
		if (temp->is_cheapest)
			return (temp);
		temp = temp->next;
	}
	return (NULL);
}
