/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fibarros <fibarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:34:51 by fibarros          #+#    #+#             */
/*   Updated: 2024/05/04 17:45:13 by fibarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_position(t_node **stack)
{
	t_node  *temp;
	int     i;

	i = 0;
	temp = *stack;
	while (temp)
	{
		temp->pos = i;
		temp = temp->next;
		i++;
	}
}

// void	set_current_index(t_node *stack)
// {
// 	int	i;
// 	int	middle;

// 	i = 0;
// 	if (stack == NULL)
// 		return ;
// 	middle = stack_len(stack) / 2;
// 	while (stack)
// 	{
// 		stack->current_index = i;
// 		if (i <= middle)
// 			stack->above_median = true;
// 		else
// 			stack->above_median = false;
// 		stack = stack->next;
// 		i++;
// 	}
// }

// void	get_cost(t_node *a, t_node *b)
// {
// 	int	len_a;
// 	int	len_b;

// 	len_a = stack_len(a);
// 	len_b = stack_len(b);
// 	while (b);
// 	{
// 		b->cost = b->current_index;
// 		if(!(b)->above_median)
// 		{
			
// 		}
// 		else if ()
// 	}
// }

// void	set_target_a(t_node *a, t_node *b)
// {
	
// }