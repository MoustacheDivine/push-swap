/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_position.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbruscan <gbruscan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 22:28:41 by gbruscan          #+#    #+#             */
/*   Updated: 2024/10/28 02:47:14 by gbruscan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	greater_than_max2(t_stack *a, t_node *tmp)
{
	int	pos_a;

	pos_a = 0;
	if (a->top->value == a->min)
		return (0);
	while (tmp && tmp->next && tmp->value != a->min)
	{
		pos_a++;
		tmp = tmp->next;
	}
	return (pos_a);
}

int	lower_than_min2(t_stack *a, t_node *tmp)
{
	int	pos_a;

	pos_a = 0;
	if (a->top->value == a->min)
		return (0);
	while (tmp && tmp->next && tmp->value != a->min)
	{
		pos_a++;
		tmp = tmp->next;
	}
	return (pos_a);
}

int	in_between2(t_node *current, t_node *tmp)
{
	int	pos_a;

	pos_a = 0;
	while (tmp && tmp->next)
	{
		if ((current->value > tmp->value)
			&& (current->value < tmp->next->value))
			break ;
		pos_a++;
		tmp = tmp->next;
	}
	return (pos_a + 1);
}

int	find_pos_a(t_node *current, t_stack *a)
{
	t_node	*tmp;

	tmp = a->top;
	while (tmp && tmp->next)
		tmp = tmp->next;
	if ((current->value < a->top->value) && (current->value > tmp->value))
		return (0);
	tmp = a->top;
	if (current->value > a->max)
		return (greater_than_max2(a, tmp));
	if (current->value < a->min)
		return (lower_than_min2(a, tmp));
	return (in_between2(current, tmp));
}
