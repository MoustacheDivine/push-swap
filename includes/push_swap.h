/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbruscan <gbruscan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 01:45:58 by gbruscan          #+#    #+#             */
/*   Updated: 2024/10/29 04:15:37 by gbruscan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "libft.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#define ERROR_VALUE 2147483648

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	struct s_node	*top;
	int				size;
	int				max;
	int				min;

}					t_stack;

typedef struct s_move
{
	int				ra;
	int				rb;
	int				rr;
	int				rrr;
	int				rra;
	int				rrb;
	int				cost;
	int				value;
}					t_move;

void				swap(t_stack *stack);
void				sa(t_stack *a);
void				sb(t_stack *b);
void				ss(t_stack *a, t_stack *b);
void				push(t_stack *stack1, t_stack *stack2);
void				pa(t_stack *a, t_stack *b);
void				pb(t_stack *a, t_stack *b);
void				rotate(t_stack *stack);
void				ra(t_stack *a);
void				rb(t_stack *b);
void				rr(t_stack *a, t_stack *b);
void				reverse(t_stack *stack);
void				rra(t_stack *a);
void				rrb(t_stack *b);
void				rrr(t_stack *a, t_stack *b);
void				exec_moves(t_move move, t_stack *a, t_stack *b);
void				exec_moves2(t_move move, t_stack *a, t_stack *b);
void				handle_short_list(t_stack *a, t_stack *b, int argc);
void				sort_last_three(t_stack *a);
void				final_step(t_stack *a, t_stack *b);
void				set_a_moves(t_move *move, t_stack *a, int pos_a);
void				set_b_moves(t_move *move, t_stack *b, int pos_b);
void				set_common_moves(t_move *move);
void				fill_stack(t_stack *stack, int value);
void				free_stack(t_stack *stack);
void				read_terminal(t_stack *a, t_stack *b);
long				ft_atol_scam(const char *str);
int					checktab(int *tab, int end);
int					parse_args(int argc, char **argv, int *tab);
int					len_check(char *str);
int					sort_list(t_stack *a, t_stack *b);
int					start(t_stack *a, t_stack *b);
int					find_pos_b(t_node *current, t_stack *b);
int					in_between(t_node *current, t_node *tmp);
int					lower_than_min(t_stack *b, t_node *tmp);
int					greater_than_max(t_stack *b, t_node *tmp);
int					find_pos_a(t_node *current, t_stack *a);
int					in_between2(t_node *current, t_node *tmp);
int					lower_than_min2(t_stack *a, t_node *tmp);
int					greater_than_max2(t_stack *a, t_node *tmp);
int					is_sort(t_stack *a, t_stack *b);
int					exec_line(char *line, t_stack *a, t_stack *b);
t_stack				*init_stack(void);
t_move				calc_cost(t_node *current, t_stack *a, t_stack *b,
						int pos_a);
