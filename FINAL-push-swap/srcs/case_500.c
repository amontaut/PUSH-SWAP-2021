/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_500.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontaut <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 16:18:25 by amontaut          #+#    #+#             */
/*   Updated: 2021/10/14 16:22:32 by amontaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
 ** For arg <= 500 the function pushes the numbers bellow 
 ** q1 from list a to list b, then it sorts the list b and 
 ** pushes back to list a
 */
void	push_bellow_q1(t_list_a *list_a, t_list_b *list_b, t_quarts *quartiles, \
int ac)
{
	t_elem_a	*current;
	int			i;

	current = list_a->first;
	i = 0;
	while (i < (ac - 1))
	{
		current = list_a->first;
		if (current->value <= quartiles->q1)
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
	sort_a_b(list_a, list_b, quartiles->q1, quartiles->bellow_q1);
	rotate_a(list_a);
	rotate_a(list_a);
	write(1, "ra\nra\n", 6);
}

/*
 ** For arg <= 500 the function pushes the numbers between q1 and 
 ** med from list a to list b, then it sorts the list b and 
 ** pushes back to list a
 */
void	push_q1_med(t_list_a *list_a, t_list_b *list_b, t_quarts *quartiles, \
int ac)
{
	t_elem_a	*current;
	int			i;

	current = list_a->first;
	i = 0;
	while (i < (ac - 1))
	{
		current = list_a->first;
		if (current->value > quartiles->q1 \
		&& current->value <= quartiles->med)
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
	write(1, "ra\n", 3);
}

/*
 ** For arg <= 500 the function pushes the numbers between med and 
 ** q3 from list a to list b, then it sorts the list b and 
 ** pushes back to list a
 */
void	push_med_q3(t_list_a *list_a, t_list_b *list_b, t_quarts *quartiles, \
int ac)
{
	t_elem_a	*current;
	int			i;

	current = list_a->first;
	i = 0;
	while (i < (ac - 1))
	{
		current = list_a->first;
		if (current->value > quartiles->med && current->value \
		<= quartiles->q3)
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
	sort_a_b(list_a, list_b, quartiles->q3, quartiles->bellow_q3);
	rotate_a(list_a);
	write(1, "ra\n", 3);
}

/*
 ** For arg <= 500 the function pushes the numbers above q3 til the end 
 ** med from list a to list b, then it sorts the list b and 
 ** pushes back to list a
 */
void	push_above_q3(t_list_a *list_a, t_list_b *list_b, t_quarts *quartiles, \
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
		if (current->value > quartiles->q3)
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
	sort_a_b(list_a, list_b, smallest, quartiles->bellow_end);
}
