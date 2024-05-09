/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fibarros <fibarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:51:05 by fibarros          #+#    #+#             */
/*   Updated: 2024/05/08 14:14:13 by fibarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_small(t_node **a)
{
	t_node	*biggest_node;

	biggest_node = find_big_indx_node(*a);
	if ((*a)->index == biggest_node->index)
		ra(a);
	else if ((*a)->next->index == biggest_node->index)
		rra(a);
	if ((*a)->index > (*a)->next->index)
		sa(a);
}
