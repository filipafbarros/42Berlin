/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filipa <filipa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 09:59:56 by fibarros          #+#    #+#             */
/*   Updated: 2024/03/20 11:34:57 by filipa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_big(t_stack_node **a, t_stack_node **b)
{
	int	stack_size_a;

	stack_size_a = stack_len(*a);
	// ft_printf("stack size: %d\n", stack_size_a);
	while (stack_size_a-- > 3)
		pb(b, a);
	sort_small(a);
	// while (*b)
	// {
			// get target position
			// get cost
			// do cheapest move
	// }

}
