/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontaut <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 16:23:45 by amontaut          #+#    #+#             */
/*   Updated: 2021/10/14 16:23:51 by amontaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** Will launch fct if 100 < arg
*/
void	arg_is_500(t_list_a *list_a, t_list_b *list_b, int ac)
{
	t_quarts	quartiles;

	find_med_q(list_a, &quartiles, ac);
	quartiles.bellow_q1 = count_first(list_a, quartiles.q1);
	push_bellow_q1(list_a, list_b, &quartiles, ac);
	quartiles.bellow_med = count_mid(list_a, quartiles.q1, quartiles.med);
	push_q1_med(list_a, list_b, &quartiles, ac);
	quartiles.bellow_q3 = count_mid(list_a, quartiles.med, quartiles.q3);
	push_med_q3(list_a, list_b, &quartiles, ac);
	quartiles.bellow_end = count_last(list_a, quartiles.q3);
	push_above_q3(list_a, list_b, &quartiles, ac);
}

/*
** Will launch fct if 5 < arg <= 100
*/
void	arg_is_100(t_list_a *list_a, t_list_b *list_b, int ac)
{
	t_quarts	quartiles;

	find_med_q(list_a, &quartiles, ac);
	quartiles.bellow_med = count_first(list_a, quartiles.med);
	quartiles.above_med = count_last(list_a, quartiles.med);
	push_bellow_med(list_a, list_b, &quartiles, ac);
	push_above_med(list_a, list_b, &quartiles, ac);
}

/*
** Will launch fct is arg == 4 or 5
*/
void	arg_is_5_4(t_list_a *list_a, t_list_b *list_b, int ac)
{
	int	smallest;
	int	position;
	int	length_a;

	smallest = find_smallest_a(list_a);
	position = find_pos_small_a(list_a, smallest);
	position--;
	length_a = find_len_a(list_a);
	ra_or_rra(list_a, list_b, position, length_a);
	if ((ac - 1) == 5)
		arg_is_5(list_a, list_b, smallest, position);
	else
		arg_is_3(list_a);
	push_a(list_a, list_b);
	write(1, "pa\n", 3);
}

/*
** Will launch fct is arg == 3
*/
void	arg_is_3(t_list_a *list_a)
{
	t_elem_a	*current;
	int			biggest;

	current = list_a->first;
	biggest = find_biggest_a(list_a);
	current = list_a->first;
	if (biggest == current->value)
	{
		rotate_a(list_a);
		write(1, "ra\n", 3);
	}
	else if (biggest == current->next->value)
	{
		reverse_rotate_a(list_a);
		write(1, "rra\n", 4);
	}
	if (current->value > current->next->value)
	{
		swap_a(list_a);
		write(1, "sa\n", 3);
	}
}

/*
** Will launch fct is arg == 2
*/
void	arg_is_2(t_list_a *list_a)
{
	t_elem_a	*current;

	current = list_a->first;
	if (current->value > current->next->value)
	{
		swap_a(list_a);
		write(1, "sa\n", 3);
	}
}
