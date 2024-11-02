/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbruscan <gbruscan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 07:41:00 by gbruscan          #+#    #+#             */
/*   Updated: 2024/10/28 23:36:05 by gbruscan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_a_moves(t_move *move, t_stack *a, int pos_a)
{
	if (pos_a <= a->size / 2)
		move->ra = pos_a;
	else
		move->rra = a->size - pos_a;
}

void	set_b_moves(t_move *move, t_stack *b, int pos_b)
{
	if (pos_b <= b->size / 2)
		move->rb = pos_b;
	else
		move->rrb = b->size - pos_b;
}

void	set_common_moves(t_move *move)
{
	while (move->ra > 0 && move->rb > 0)
	{
		move->rr++;
		move->ra--;
		move->rb--;
	}
	while (move->rra > 0 && move->rrb > 0)
	{
		move->rrr++;
		move->rra--;
		move->rrb--;
	}
}

void	exec_moves(t_move move, t_stack *a, t_stack *b)
{
	while (move.ra--)
		ra(a);
	while (move.rra--)
		rra(a);
	while (move.rb--)
		rb(b);
	while (move.rrb--)
		rrb(b);
	while (move.rr--)
		rr(a, b);
	while (move.rrr--)
		rrr(a, b);
	pb(a, b);
	if (b->max < b->top->value)
		b->max = b->top->value;
	if (b->min > b->top->value)
		b->min = b->top->value;
}

void	exec_moves2(t_move move, t_stack *a, t_stack *b)
{
	while (move.ra--)
		ra(a);
	while (move.rra--)
		rra(a);
	while (move.rb--)
		rb(b);
	while (move.rrb--)
		rrb(b);
	while (move.rr--)
		rr(a, b);
	while (move.rrr--)
		rrr(a, b);
	pa(a, b);
	if (a->max < a->top->value)
		a->max = a->top->value;
	if (a->min > a->top->value)
		a->min = a->top->value;
}
