/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_100.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontaut <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 16:17:39 by amontaut          #+#    #+#             */
/*   Updated: 2021/10/14 16:22:21 by amontaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
 ** For arg <= 100 the function pushes the numbers bellow 
 ** med from list a to list b, then it sorts the list b and 
 ** pushes back to list a
 */
void	push_bellow_med(t_list_a *list_a, t_list_b *list_b, \
t_quarts *quartiles, int ac)
{
	t_elem_a	*current;
	int			i;

	current = list_a->first;
	i = 0;
	while (i < (ac - 1))
	{
		current = list_a->first;
		if (current->value <= quartiles->med)
		{
			push_b(list_a, list_b);
			write(1, "pb\n", 3);
		}
		else
		{
			rotate_a(list_a);
			write(1, "ra\n", 3);
		}
		i++;
	}
	sort_a_b(list_a, list_b, quartiles->med, quartiles->bellow_med);
	rotate_a(list_a);
	rotate_a(list_a);
	write(1, "ra\nra\n", 6);
}

/*
 ** For arg <= 100 the function pushes the numbers above 
 ** med from list a to list b, then it sorts the list b and 
 ** pushes back to list a
 */
void	push_above_med(t_list_a *list_a, t_list_b *list_b, t_quarts *quartiles, \
int ac)
{
	t_elem_a	*current;
	int			i;
	int			smallest;

	current = list_a->first;
	i = 0;
	while (i < (ac - 1))
	{
		current = list_a->first;
		if (current->value > quartiles->med)
		{
			push_b(list_a, list_b);
			write(1, "pb\n", 3);
		}
		else
		{
			rotate_a(list_a);
			write(1, "ra\n", 3);
		}
		i++;
	}
	smallest = find_smallest_a(list_a);
	sort_a_b(list_a, list_b, smallest, quartiles->above_med);
}
