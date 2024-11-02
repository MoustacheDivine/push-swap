/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbruscan <gbruscan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 00:06:52 by gbruscan          #+#    #+#             */
/*   Updated: 2024/10/28 05:07:00 by gbruscan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	push(t_stack *stack1, t_stack *stack2)
{
	t_node	*tmp;

	if (!stack1->top)
		return ;
	tmp = stack2->top;
	stack2->top = stack1->top;
	stack1->top = stack1->top->next;
	stack2->top->next = tmp;
	stack1->size--;
	stack2->size++;
}

void	pa(t_stack *a, t_stack *b)
{
	push(b, a);
}

void	pb(t_stack *a, t_stack *b)
{
	push(a, b);
}