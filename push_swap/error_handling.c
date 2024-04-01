/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filipa <filipa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 11:09:46 by fibarros          #+#    #+#             */
/*   Updated: 2024/03/20 11:09:01 by filipa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* error free */
void	free_stack(t_stack_node **stack)
{
	t_stack_node	*top;
	t_stack_node	*temp;

	top = *stack;
	while (top)
	{
		temp = top;
		top = top->next;
		free(temp);
	}
	free(stack);
	*stack = NULL;
}

/* exit error*/

void	exit_error(t_stack_node **stack_a, t_stack_node **stack_b)
{
	if (stack_a == NULL || *stack_a != NULL)
		free_stack(stack_a);
	if (stack_b == NULL || *stack_b != NULL)
		free_stack(stack_b);
	printf("Error \n");
	exit (1);
}

/* error repetition */

int	error_repetion(t_stack_node *a, int n)
{
	if (a == NULL)
		return (0);
	while (a)
	{
		if (a->value == n)
			return (1);
		a = a->next;
	}
	return (0);
}

bool	input_valid(char **argv)
{

}
