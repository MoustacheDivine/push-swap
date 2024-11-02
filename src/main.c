/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbruscan <gbruscan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 02:30:39 by gbruscan          #+#    #+#             */
/*   Updated: 2024/10/29 04:34:23 by gbruscan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		return (free(tab), ft_putendl_fd("Error", 2), 0);
	a = init_stack();
	b = init_stack();
	while (index--)
		fill_stack(a, tab[index]);
	free(tab);
	if (argc == 3 || argc == 4 || argc == 5)
		handle_short_list(a, b, argc);
	else
		sort_list(a, b);
	free_stack(a);
	free_stack(b);
	return (0);
}
