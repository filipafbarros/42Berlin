/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fibarros <fibarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 09:59:56 by fibarros          #+#    #+#             */
/*   Updated: 2024/05/04 17:40:21 by fibarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_big(t_node **a, t_node **b)
{
	int	stack_size_a;

	stack_size_a = stack_len(*a);
	while (stack_size_a-- > 3)
		pb(b, a);
	sort_small(a);
	while ()
}



// void	push_b(t_node **a, t_node **b)
// {
// 	int	stack_size;
// 	int	pushed_nodes;
// 	int	i;

// 	stack_size = stack_len(*a);
// 	pushed_nodes = 0;
// 	i = 0;
// 	while ()
// }
