/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fibarros <fibarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:34:51 by fibarros          #+#    #+#             */
/*   Updated: 2024/05/08 17:20:35 by fibarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_position(t_node **stack)
{
	t_node	*temp;
	int		i;
	int		median;

	i = 0;
	median = stack_len(*stack) / 2;
	temp = *stack;
	while (temp)
	{
		temp->pos = i;
		if (i <= median)
			temp->above_median = 1;
		else
			temp->above_median = 0;
		temp = temp->next;
		i++;
	}
}

void	find_target_a(t_node *a, t_node *b)
{
	t_node		*tmp_a;
	t_node		*tmp_b;
	t_node		*target_node;
	int			trgt;

	tmp_a = a;
	while (tmp_a)
	{
		trgt = INT_MIN;
		tmp_b = b;
		while (tmp_b)
		{
			if (tmp_b->index < tmp_a->index && tmp_b->index > trgt)
			{
				trgt = tmp_b->index;
				target_node = tmp_b;
			}
			tmp_b = tmp_b->next;
		}
		if (trgt == INT_MIN)
			target_node = find_big_indx_node(b);
		tmp_a->target_node = target_node;
		tmp_a = tmp_a->next;
	}
}

void	find_target_b(t_node *a, t_node *b)
{
	t_node		*tmp_a;
	t_node		*tmp_b;
	t_node		*target_node;
	int			trgt;

	tmp_b = b;
	while (tmp_b)
	{
		trgt = INT_MAX;
		tmp_a = a;
		while (tmp_a)
		{
			if (tmp_a->index > tmp_b->index && tmp_a->index < trgt)
			{
				trgt = tmp_a->index;
				target_node = tmp_a;
			}
			tmp_a = tmp_a->next;
		}
		if (trgt == INT_MAX)
			target_node = find_small_indx_node(a);
		tmp_b->target_node = target_node;
		tmp_b = tmp_b->next;
	}
}

void	prep_nodes_a(t_node **a, t_node **b)
{
	set_position(a);
	set_position(b);
	find_target_a(*a, *b);
	calculate_cost(a, b);
	set_cheapest(*a);
}

void	prep_nodes_b(t_node **a, t_node **b)
{
	set_position(a);
	set_position(b);
	find_target_b(*a, *b);
}
