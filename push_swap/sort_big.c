/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fibarros <fibarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 09:59:56 by fibarros          #+#    #+#             */
/*   Updated: 2024/05/08 16:40:43 by fibarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_big(t_node **a, t_node **b)
{
	int	stack_size_a;

	stack_size_a = stack_len(*a);
	if (stack_size_a-- > 3 && !is_sorted(a))
		pb(a, b);
	if (stack_size_a-- > 3 && !is_sorted(a))
		pb(a, b);
	while (stack_size_a-- > 3 && !is_sorted(a))
	{
		prep_nodes_a(a, b);
		make_moves_ab(a, b);
	}
	sort_small(a);
	while (*b)
	{
		prep_nodes_b(a, b);
		rotate_a(a, (*b)->target_node);
		pa(a, b);
	}
	set_position(a);
	final_sort(a);
}
