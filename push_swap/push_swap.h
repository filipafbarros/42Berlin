/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fibarros <fibarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:59:27 by fibarros          #+#    #+#             */
/*   Updated: 2024/05/04 18:03:36 by fibarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <stdbool.h>
# include <limits.h>
# include <unistd.h>

typedef struct s_node
{
	int					value;
	int					index;
	int					cost;
	int					pos;
	bool				cheapest;
	struct s_node		*target_node;
	struct s_node		*next;
	struct s_node		*prev;
}	t_node;

/*Operations*/
int					main(int argc, char **argv);
void				push(t_node **dest, t_node **src);
void				swap(t_node **stack);
void				rotate(t_node **stack);
void				reverse_rotate(t_node **stack);

/* Handle errors*/
void				free_stack(t_node **stack);
void				exit_error(t_node **stack_a, t_node **stack_b);

/* Movements*/
void				pa(t_node **a, t_node **b);
void				pb(t_node **b, t_node **a);
void				sa(t_node **a);
void				sb(t_node **b);
void				ss(t_node **a, t_node **b);
void				ra(t_node **a);
void				rb(t_node **b);
void				rr(t_node **a, t_node **b);
void				rra(t_node **a);
void				rrb(t_node **b);
void				rrr(t_node **a, t_node **b);
// Utils
void				print_stack(t_node *stack);
t_node				*get_last_node(t_node *stack);
int					stack_len(t_node *stack);
int					find_max_index(t_node *stack);
int					find_min_index(t_node *stack);
bool				is_sorted(t_node **a);

// Argument Handling
int					nbr_strcmp(const char *s1, const char *s2);
int					check_args(int ac, char **av);
int					is_number(char *str);
int					is_sign(char c);
int					is_zero(char *str);
int					is_duplicate(char **av);

/* initialization*/
void				init_stack_a(t_node **a, int ac, char **av);
void				append_node(t_node **stack, int n);
long				ft_atol(const char *str);
void				assign_index(t_node *stack_a, int stack_len);

/*Algorithm*/
void				push_swap(t_node **a, t_node **b);
void				sort_small(t_node **a);
void				sort_big(t_node **a, t_node **b);

/*Algorithm utils*/
void				set_current_index(t_node *stack);
void				set_position(t_node **stack);

#endif