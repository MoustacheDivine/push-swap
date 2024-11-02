/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbruscan <gbruscan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 23:26:18 by gbruscan          #+#    #+#             */
/*   Updated: 2024/10/29 02:59:23 by gbruscan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	stack->top = NULL;
	stack->size = 0;
	stack->max = -2147483648;
	stack->min = 2147483647;
	return (stack);
}

void	fill_stack(t_stack *stack, int value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node->value = value;
	new_node->next = stack->top;
	stack->top = new_node;
	stack->size++;
}

void	handle_short_list(t_stack *a, t_stack *b, int argc)
{
	t_node	*check;

	check = a->top;
	while (check && check->next && check->value < check->next->value)
		check = check->next;
	if (check->next == NULL)
		return ;
	if (argc == 3)
	{
		if (a->top->value > a->top->next->value)
			sa(a);
		return ;
	}
	if (argc == 4)
		sort_last_three(a);
	else
	{
		pb(a, b);
		b->max = b->top->value;
		b->min = b->top->value;
		sort_last_three(a);
		final_step(a, b);
	}
	return ;
}

void	free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*next_node;

	current = stack->top;
	while (current != NULL)
	{
		next_node = current->next;
		free(current);
		current = next_node;
	}
	free(stack);
}

t_move	calc_cost(t_node *current, t_stack *a, t_stack *b, int pos_a)
{
	t_move	move;
	int		pos_b;

	ft_memset(&move, 0, sizeof(t_move));
	pos_b = find_pos_b(current, b);
	set_a_moves(&move, a, pos_a);
	set_b_moves(&move, b, pos_b);
	set_common_moves(&move);
	move.cost = move.ra + move.rb + move.rra + move.rrb + move.rr + move.rrr;
	return (move);
}
