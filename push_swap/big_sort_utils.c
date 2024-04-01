/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filipa <filipa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:34:51 by fibarros          #+#    #+#             */
/*   Updated: 2024/03/20 11:03:44 by filipa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_current_index(t_stack_node *stack)
{
	int	i;
	int	middle;

	i = 0;
	if (stack == NULL)
		return ;
	middle = stack_len(stack) / 2;
	while (stack)
	{
		stack->current_index = i;
		if (i <= middle)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		i++;
	}
}

void	get_cost(t_stack_node *a, t_stack_node *b)
{
	int				len_a;
	int				len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (b)
	{
		b->cost = b->current_index;
		if (!(b->above_median))
			b->cost = len_b - (b->current_index);
		if (b->target_node->above_median)
			b->cost += b->target_node->current_index;
		else
			b->cost += len_a - (b->target_node->current_index);
		b = b->next;
	}
}

void	set_target_a(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*temp_a;
	t_stack_node	*target;
	long			best_match_index;

	best_match_index = LONG_MAX;
	temp_a = a;
	while (temp_a)
	{
		if (temp_a->value > b->value && temp_a->value < best_match_index)
		{
			best_match_index = temp_a->value;
			target = temp_a;
		}
		temp_a = temp_a->next;
	}
	if (LONG_MAX == best_match_index)
		b->target_node = find_min(a);
	else
		b->target_node = target;
	b = b->next;
}

void	set_cheapest(t_stack_node *b)
{
	long			cheapest_value;
	t_stack_node	*cheapest_node;

	if (b == NULL)
		return (0);
	cheapest_value = LONG_MAX;
	while (b)
	{
		if (b->cost < cheapest_value)
		{
			cheapest_value = b->cost;
			cheapest_node = b;
		}
		b = b->next;
	}
	cheapest_node->cheapest = true;
}
