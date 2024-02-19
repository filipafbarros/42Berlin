/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fibarros <fibarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 09:59:56 by fibarros          #+#    #+#             */
/*   Updated: 2024/02/16 16:05:56 by fibarros         ###   ########.fr       */
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
		
	// }
}
