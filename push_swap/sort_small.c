/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fibarros <fibarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:51:05 by fibarros          #+#    #+#             */
/*   Updated: 2024/05/03 18:25:48 by fibarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_small(t_node **a)
{
	static int		highest_index;

	highest_index = find_max_index(*a);
	if ((*a)->index == highest_index)
		ra(a);
	else if ((*a)->next->index == highest_index)
		rra(a);
	if ((*a)->index > (*a)->next->index)
		sa(a);
}
