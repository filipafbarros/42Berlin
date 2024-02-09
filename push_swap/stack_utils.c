/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fibarros <fibarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 09:53:48 by fibarros          #+#    #+#             */
/*   Updated: 2024/02/09 16:51:54 by fibarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack_node *stack)
{
	while (stack != NULL)
	{
		ft_printf("%d", stack->value);
		stack = stack->next;
		ft_printf("\n");
	}
}

int	stack_len(t_stack_node *stack)
{
	int	i;

	i = 0;
	while (stack != NULL)
	{
		stack = stack->next;
		i++;
	}
}

void    find_highest_node(t_stack_node *stack)
{
    
}