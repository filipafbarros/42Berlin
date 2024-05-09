/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fibarros <fibarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 10:44:33 by fibarros          #+#    #+#             */
/*   Updated: 2024/05/08 17:42:36 by fibarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_moves_ab(t_node **a, t_node **b)
{
	t_node	*cheapest_node;

	cheapest_node = find_cheapest(*a);
	if (cheapest_node->above_median && cheapest_node->target_node->above_median)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_median) && \
		!(cheapest_node->target_node->above_median))
		rev_rot_both(a, b, cheapest_node);
	rotate_a(a, cheapest_node);
	rotate_b(b, cheapest_node->target_node);
	pb(a, b);
}

void	rotate_both(t_node **a, t_node **b, t_node *cheapest_node)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
		rr(a, b);
	set_position(a);
	set_position(b);
}

void	rev_rot_both(t_node **a, t_node **b, t_node *cheapest_node)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
		rrr(a, b);
	set_position(a);
	set_position(b);
}

void	rotate_a(t_node **a, t_node	*cheapest_node)
{
	while (cheapest_node->pos != 0)
	{
		if (cheapest_node->above_median)
			ra(a);
		else
			rra(a);
		set_position(a);
	}
}

void	rotate_b(t_node **b, t_node *cheapest_node)
{
	while (cheapest_node->pos != 0)
	{
		if (cheapest_node->above_median)
			rb(b);
		else
			rrb(b);
		set_position(b);
	}
}
