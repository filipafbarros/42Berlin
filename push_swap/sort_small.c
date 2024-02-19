/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fibarros <fibarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:51:05 by fibarros          #+#    #+#             */
/*   Updated: 2024/02/12 12:04:32 by fibarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_small(t_stack_node **a)
{
	t_stack_node	*highest_node;

	highest_node = find_max(*a);
	if ((*a)->value == highest_node->value)
		ra(a);
	else if ((*a)->next->value == highest_node->value)
		rra(a);
	if ((*a)->value > (*a)->next->value)
		sa(a);
}
