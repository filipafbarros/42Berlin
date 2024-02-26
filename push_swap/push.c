/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fibarros <fibarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:12:23 by fibarros          #+#    #+#             */
/*   Updated: 2024/02/09 11:02:58 by fibarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Push a node to the top of src to dest*/

/*push*/
void	push(t_stack_node **dest, t_stack_node **src)
{
	t_stack_node	*pushed_node;

	if (*src == NULL)
		return ;
	pushed_node = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	pushed_node->prev = NULL;
	if (*dest == NULL)
	{
		*dest = pushed_node;
		pushed_node->next = NULL;
	}
	else
	{
		pushed_node->next = *dest;
		pushed_node->next->prev = pushed_node;
		*dest = pushed_node;
	}
}

void	pa(t_stack_node **a, t_stack_node **b)
{
	push(a, b);
	ft_printf("pa\n");
}

void	pb(t_stack_node **b, t_stack_node **a)
{
	push(b, a);
	ft_printf("pb\n");
}