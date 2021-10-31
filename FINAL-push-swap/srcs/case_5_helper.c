/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_5_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontaut <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 16:34:03 by amontaut          #+#    #+#             */
/*   Updated: 2021/10/14 16:34:33 by amontaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** For arg == 5, decides if its quicker to move the smallest nb in 
** in list a with ra or rra
*/
void	ra_or_rra(t_list_a *list_a, t_list_b *list_b, int position, \
int length_a)
{
	int	count;

	if (position <= length_a / 2)
	{
		while (position)
		{
			rotate_a(list_a);
			write(1, "ra\n", 3);
			position--;
		}
	}
	else
	{
		count = length_a - position;
		while (count)
		{
			reverse_rotate_a(list_a);
			write(1, "rra\n", 4);
			count--;
		}
	}
	push_b(list_a, list_b);
	write(1, "pb\n", 3);
}

/*
** Will launch fct is arg == 5
*/
void	arg_is_5(t_list_a *list_a, t_list_b *list_b, int smallest, int position)
{
	t_elem_b	*current;

	smallest = find_smallest_a(list_a);
	position = find_pos_small_a(list_a, smallest);
	position--;
	ra_or_rra(list_a, list_b, position, find_len_a(list_a));
	arg_is_3(list_a);
	current = list_b->first;
	if (current->value < current->next->value)
	{
		rotate_b(list_b);
		write(1, "rb\n", 3);
	}
	push_a(list_a, list_b);
	write(1, "pa\n", 3);
}
