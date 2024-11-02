/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbruscan <gbruscan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 04:18:54 by gbruscan          #+#    #+#             */
/*   Updated: 2024/10/29 00:17:42 by gbruscan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	exec_line(char *line, t_stack *a, t_stack *b)
{
	if (ft_strcmp(line, "ra\n") == 0)
		ra(a);
	else if (ft_strcmp(line, "rb\n") == 0)
		rb(b);
	else if (ft_strcmp(line, "rra\n") == 0)
		rra(a);
	else if (ft_strcmp(line, "rrb\n") == 0)
		rrb(b);
	else if (ft_strcmp(line, "rr\n") == 0)
		rr(a, b);
	else if (ft_strcmp(line, "rrr\n") == 0)
		rrr(a, b);
	else if (ft_strcmp(line, "sa\n") == 0)
		sa(a);
	else if (ft_strcmp(line, "sb\n") == 0)
		sb(b);
	else if (ft_strcmp(line, "ss\n") == 0)
		ss(a, b);
	else if (ft_strcmp(line, "pa\n") == 0)
		pa(a, b);
	else if (ft_strcmp(line, "pb\n") == 0)
		pb(a, b);
	else
		return (0);
	return (1);
}

int	is_sort(t_stack *a, t_stack *b)
{
	t_node	*check;

	check = a->top;
	while (check && check->next && check->value < check->next->value)
		check = check->next;
	if (check->next == NULL && b->size == 0)
		return (1);
	return (0);
}

void	read_terminal(t_stack *a, t_stack *b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (!exec_line(line, a, b))
		{
			ft_putendl_fd("Error", 2);
			free(line);
			free_stack(a);
			free_stack(b);
			exit(EXIT_FAILURE);
		}
		free(line);
		line = get_next_line(0);
	}
	if (is_sort(a, b))
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
}

/*void    print_list(t_stack *stack)
{
    t_node    *current;

    current = stack->top;
    while (current != NULL)
    {
        ft_printf("%d -> ", current->value);
        current = current->next;
    }
    ft_printf("NULL\n");
}*/

int	main(int argc, char **argv)
{
	int		*tab;
	int		index;
	t_stack	*a;
	t_stack	*b;

	if (argc == 1)
		return (0);
	tab = malloc((argc - 1) * sizeof(int));
	index = parse_args(argc, argv, tab);
	if (index == 0 || !checktab(tab, index))
	{
		free(tab);
		return (ft_putendl_fd("Error", 2), 0);
	}
	a = init_stack();
	b = init_stack();
	while (index--)
		fill_stack(a, tab[index]);
	free(tab);
	read_terminal(a, b);
	free_stack(a);
	free_stack(b);
	return (0);
}
