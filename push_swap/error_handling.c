/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fibarros <fibarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 11:09:46 by fibarros          #+#    #+#             */
/*   Updated: 2024/05/03 14:27:34 by fibarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* error free */
void	free_stack(t_node **stack)
{
	t_node	*temp;

	if (!stack || !(*stack))
		return ;
	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
	*stack = NULL;
}

/* exit error*/
void	exit_error(t_node **stack_a, t_node **stack_b)
{
	if (stack_a == NULL || *stack_a != NULL)
		free_stack(stack_a);
	if (stack_b == NULL || *stack_b != NULL)
		free_stack(stack_b);
	printf("Error \n");
	exit (1);
}

/* error repetition */
// int	error_repetion(t_node *a, int n)
// {
// 	if (a == NULL)
// 		return (0);
// 	while (a)
// 	{
// 		if (a->value == n)
// 			return (1);
// 		a = a->next;
// 	}
// 	return (0);
// }
