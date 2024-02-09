/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fibarros <fibarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:59:27 by fibarros          #+#    #+#             */
/*   Updated: 2024/02/09 11:22:08 by fibarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
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
int					main(int argc, char **argv);
void				push(t_stack_node **dest, t_stack_node **src);
void				swap(t_stack_node **stack);
void				rotate(t_stack_node **stack);
void				reverse_rotate(t_stack_node **stack);

/* Handle errors*/
void				free_stack(t_stack_node **stack);
void				exit_error(t_stack_node **stack_a, t_stack_node **stack_b);
int					error_repetion(t_stack_node *a, int n);

/* Movements*/
void				pa(t_stack_node **a, t_stack_node **b);
void				pb(t_stack_node **b, t_stack_node **a);
void				sa(t_stack_node **a);
void				sb(t_stack_node **b);
void				ss(t_stack_node **a, t_stack_node **b);
void				ra(t_stack_node **a);
void				rb(t_stack_node **b);
void				rr(t_stack_node **a, t_stack_node **b);
void				rra(t_stack_node **a);
void				rrb(t_stack_node **b);
void				rrr(t_stack_node **a, t_stack_node **b);
// Utils
void				print_stack(t_stack_node *stack);
t_stack_node		*get_last_node(t_stack_node *stack);

/* initialization*/
void				init_stack_a(t_stack_node **a, char **argv);
void				append_node(t_stack_node **stack, int n);
long				ft_atol(const char *str);
/*Algorithm*/
#endif