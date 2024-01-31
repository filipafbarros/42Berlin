/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fibarros <fibarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:59:27 by fibarros          #+#    #+#             */
/*   Updated: 2024/01/31 15:20:14 by fibarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./printf/ft_printf.h"
# include <stdbool.h>
# include <limits.h>
# include <unistd.h>

/*Add cost related ints and bools, as well as a target node*/
typedef struct s_stack_node
{
	int					value;
	int					index;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

/*Operations*/
int			main(int argc, char **argv);
/* Handle errors*/
void		free_stack(t_stack_node **stack);
void		exit_error(t_stack_node **stack_a, t_stack_node **stack_b);
int			error_repetion(t_stack_node *a, int n);

/* Utils*/

// Free functions

/* initialization*/
void		init_stack_a(t_stack_node **a, char **argv);
void		append_node(t_stack_node **stack, int n);
long		ft_atol(const char *str);

/*Algorithm*/


#endif