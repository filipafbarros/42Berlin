/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fibarros <fibarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:59:27 by fibarros          #+#    #+#             */
/*   Updated: 2024/05/09 15:33:33 by fibarros         ###   ########.fr       */
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
	int					above_median;
	int					is_cheapest;
	struct s_node		*target_node;
	struct s_node		*next;
	struct s_node		*prev;
}	t_node;

/*Operations*/
int				main(int argc, char **argv);
void			push(t_node **dest, t_node **src);
void			swap(t_node **stack);
void			rotate(t_node **stack);
void			reverse_rotate(t_node **stack);

/* Handle errors*/
void			free_stack(t_node **stack);
void			exit_error(t_node **stack_a, t_node **stack_b);

/* Movements*/
void			pa(t_node **a, t_node **b);
void			pb(t_node **a, t_node **b);
void			sa(t_node **a);
void			sb(t_node **b);
void			ss(t_node **a, t_node **b);
void			ra(t_node **a);
void			rb(t_node **b);
void			rr(t_node **a, t_node **b);
void			rra(t_node **a);
void			rrb(t_node **b);
void			rrr(t_node **a, t_node **b);

// Utils
void			print_stack(t_node *stack);
t_node			*get_last_node(t_node *stack);
int				stack_len(t_node *stack);
t_node			*find_big_indx_node(t_node *stack);
t_node			*find_small_indx_node(t_node *stack);
bool			is_sorted(t_node **a);

// Argument Handling
int				nbr_strcmp(const char *s1, const char *s2);
int				check_args(int ac, char **av);
int				is_number(char *str);
int				is_sign(char c);
int				is_zero(char *str);
int				is_duplicate(char **av);
void			free_args(char **av);

/* initialization*/
void			init_stack_a(t_node **a, int ac, char **av);
void			append_node(t_node **stack, int n);
long			ft_atol(const char *str);
void			assign_index(t_node *stack_a, int stack_len);

/*Algorithm*/
void			push_swap(t_node **a, t_node **b);
void			sort_small(t_node **a);
void			sort_big(t_node **a, t_node **b);

/*Algorithm utils*/
void			set_position(t_node **stack);
void			prep_nodes_a(t_node **a, t_node **b);
void			prep_nodes_b(t_node **a, t_node **b);
void			find_target_a(t_node *a, t_node *b);
void			find_target_b(t_node *a, t_node *b);

/* Cost*/
void			calculate_cost(t_node **a, t_node **b);
void			set_cheapest(t_node *stack);
t_node			*find_cheapest(t_node *stack);

/* Moves */
void			make_moves_ab(t_node **a, t_node **b);
void			rotate_both(t_node **a, t_node **b, t_node *cheapest_node);
void			rev_rot_both(t_node **a, t_node **b, t_node *cheapest_node);
void			rotate_a(t_node **a, t_node	*cheapest_node);
void			rotate_b(t_node **b, t_node *cheapest_node);
void			final_sort(t_node **a);

#endif