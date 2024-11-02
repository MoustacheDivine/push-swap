/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbruscan <gbruscan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 01:54:00 by gbruscan          #+#    #+#             */
/*   Updated: 2024/10/29 00:46:16 by gbruscan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse(t_stack *stack)
{
	t_node	*prev_last;
	t_node	*last;
	t_node	*tmp;

	if (stack->size < 2)
		return ;
	tmp = stack->top;
	while (tmp->next)
		tmp = tmp->next;
	last = tmp;
	tmp = stack->top;
	while (tmp->next->next)
		tmp = tmp->next;
	prev_last = tmp;
	last->next = stack->top;
	prev_last->next = NULL;
	stack->top = last;
}

void	rra(t_stack *a)
{
	reverse(a);
	ft_putendl_fd("rra", 1);
}

void	rrb(t_stack *b)
{
	reverse(b);
	ft_putendl_fd("rrb", 1);
}

void	rrr(t_stack *a, t_stack *b)
{
	reverse(a);
	reverse(b);
	ft_putendl_fd("rrr", 1);
}
