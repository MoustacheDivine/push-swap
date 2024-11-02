/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbruscan <gbruscan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 00:49:21 by gbruscan          #+#    #+#             */
/*   Updated: 2024/10/29 04:18:14 by gbruscan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	start(t_stack *a, t_stack *b)
{
	t_node	*check;

	check = a->top;
	while (check && check->next && check->value < check->next->value)
		check = check->next;
	if (check->next == NULL)
		return (0);
	pb(a, b);
	b->max = b->top->value;
	b->min = b->top->value;
	pb(a, b);
	if (b->max < b->top->value)
		b->max = b->top->value;
	else
		b->min = b->top->value;
	return (1);
}

t_move	find_cheapest(t_stack *first, t_stack *second)
{
	t_node	*current;
	t_move	move;
	t_move	cheapest;
	int		min_cost;
	int		index;

	current = first->top;
	min_cost = INT_MAX;
	index = 0;
	while (current)
	{
		move = calc_cost(current, first, second, index);
		if (move.cost < min_cost)
		{
			min_cost = move.cost;
			cheapest = move;
			cheapest.value = current->value;
		}
		current = current->next;
		index++;
	}
	return (cheapest);
}

void	sort_last_three(t_stack *a)
{
	t_node	*tmp;

	tmp = a->top;
	a->min = a->top->value;
	a->max = a->top->value;
	while (tmp)
	{
		if (tmp->value < a->min)
			a->min = tmp->value;
		if (tmp->value > a->max)
			a->max = tmp->value;
		tmp = tmp->next;
	}
	if (a->top->value == a->max)
		ra(a);
	if ((a->top->value != a->min) && (a->top->next->value == a->min))
		sa(a);
	if ((a->top->value != a->min) && (a->top->next->value == a->max))
		rra(a);
	if ((a->top->value == a->min) && (a->top->next->value == a->max))
	{
		rra(a);
		sa(a);
	}
}

void	final_step(t_stack *a, t_stack *b)
{
	int		pos_a;
	t_node	*tmp;
	t_move	move;

	while (b->size)
	{
		tmp = b->top;
		pos_a = find_pos_a(tmp, a);
		ft_memset(&move, 0, sizeof(t_move));
		set_a_moves(&move, a, pos_a);
		exec_moves2(move, a, b);
	}
	tmp = a->top;
	ft_memset(&move, 0, sizeof(t_move));
	while (tmp->value != a->min)
	{
		move.ra++;
		tmp = tmp->next;
	}
	if (move.ra > a->size / 2)
	{
		move.rra = a->size - move.ra;
		move.ra = 0;
	}
	exec_moves2(move, a, b);
}

int	sort_list(t_stack *a, t_stack *b)
{
	t_move	cheapest;

	if (!start(a, b))
		return (0);
	while (a->size > 3)
	{
		cheapest = find_cheapest(a, b);
		exec_moves(cheapest, a, b);
	}
	sort_last_three(a);
	final_step(a, b);
	return (1);
}
