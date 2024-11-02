/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_position.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbruscan <gbruscan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 05:10:12 by gbruscan          #+#    #+#             */
/*   Updated: 2024/10/28 02:47:38 by gbruscan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	greater_than_max(t_stack *b, t_node *tmp)
{
	int	pos_b;

	pos_b = 0;
	if (b->top->value == b->max)
		return (0);
	while (tmp && tmp->next && tmp->value != b->max)
	{
		pos_b++;
		tmp = tmp->next;
	}
	return (pos_b);
}

int	lower_than_min(t_stack *b, t_node *tmp)
{
	int	pos_b;

	pos_b = 0;
	if (b->top->value == b->max)
		return (0);
	while (tmp && tmp->next && tmp->value != b->max)
	{
		pos_b++;
		tmp = tmp->next;
	}
	return (pos_b);
}

int	in_between(t_node *current, t_node *tmp)
{
	int	pos_b;

	pos_b = 0;
	while (tmp && tmp->next)
	{
		if ((current->value < tmp->value)
			&& (current->value > tmp->next->value))
			break ;
		pos_b++;
		tmp = tmp->next;
	}
	return (pos_b + 1);
}

int	find_pos_b(t_node *current, t_stack *b)
{
	int		pos_b;
	t_node	*tmp;

	pos_b = 0;
	tmp = b->top;
	while (tmp && tmp->next)
		tmp = tmp->next;
	if ((current->value > b->top->value) && (current->value < tmp->value))
		return (0);
	tmp = b->top;
	if (current->value > b->max)
		return (greater_than_max(b, tmp));
	if (current->value < b->min)
		return (lower_than_min(b, tmp));
	return (in_between(current, tmp));
}
