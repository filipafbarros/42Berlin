/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fibarros <fibarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:12:23 by fibarros          #+#    #+#             */
/*   Updated: 2024/05/08 16:43:06 by fibarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_node **dest, t_node **src)
{
	t_node	*pushed_node;

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

void	pa(t_node **a, t_node **b)
{
	push(a, b);
	ft_printf("pa\n");
}

void	pb(t_node **a, t_node **b)
{
	push(b, a);
	ft_printf("pb\n");
}
