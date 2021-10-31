/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontaut <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 16:29:19 by amontaut          #+#    #+#             */
/*   Updated: 2021/10/14 16:29:25 by amontaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
 ** After counting and comparing how many moves are needed to move the biggest 
 ** number in list b to the top using rb VS using rrb VS the smallest number
 ** to the top using rb VS using rrb, I launch the operations accordingly.
 ** It will sort the list b. I then push what has been sorted in list a
 */
void	launch_moves(t_list_a *list_a, t_list_b *list_b, int count, int case_nb)
{
	if (case_nb == 1 || case_nb == 2)
		count--;
	else
		count = count - 2;
	while (count)
	{
		if (case_nb == 1 || case_nb == 3)
		{
			rotate_b(list_b);
			write(1, "rb\n", 3);
		}
		else if (case_nb == 2 || case_nb == 4)
		{
			reverse_rotate_b(list_b);
			write(1, "rrb\n", 4);
		}
		count--;
	}
	push_a(list_a, list_b);
	write(1, "pa\n", 3);
	if (case_nb == 3 || case_nb == 4)
	{
		rotate_a(list_a);
		write(1, "ra\n", 3);
	}
}

/*
 ** I count and compare how many moves are needed to move the biggest 
 ** number in list b to the top using rb VS using rrb VS the smallest number
 ** to the top using rb VS using rrb. Of course I will choose the one 
 ** quickest path and launch the instruction accordingly
 */
void	process_moves(t_list_a *list_a, t_list_b *list_b)
{
	int				pos_small;
	int				pos_big;
	int				len_b;
	t_count_moves	moves;

	pos_small = find_pos_small_b(list_b, find_smallest_b(list_b));
	pos_big = find_pos_big_b(list_b, find_biggest_b(list_b));
	len_b = find_len_b(list_b);
	moves.big_rb = pos_big - 1 + 1;
	moves.big_rrb = len_b - pos_big + 1 + 1;
	moves.small_rb = pos_small - 1 + 1 + 1;
	moves.small_rrb = len_b - pos_small + 1 + 1 + 1;
	if (moves.big_rb < moves.big_rrb && moves.big_rb < moves.small_rb \
	&& moves.big_rb < moves.small_rrb)
		launch_moves(list_a, list_b, moves.big_rb, 1);
	else if (moves.big_rrb <= moves.big_rb && moves.big_rrb <= moves.small_rb \
	&& moves.big_rrb <= moves.small_rrb)
		launch_moves(list_a, list_b, moves.big_rrb, 2);
	else if (moves.small_rb <= moves.big_rb && moves.small_rb <= moves.big_rrb \
	&& moves.small_rb <= moves.small_rrb)
		launch_moves(list_a, list_b, moves.small_rb, 3);
	else if (moves.small_rrb <= moves.big_rb && moves.small_rrb \
	<= moves.big_rrb && moves.small_rrb <= moves.small_rb)
		launch_moves(list_a, list_b, moves.small_rrb, 4);
}

/* 
 ** This function will sort the lists with the least amount of instruction
 */
void	sort_a_b(t_list_a *list_a, t_list_b *list_b, int pivot1, int pivot2)
{
	t_elem_a	*current;

	while (pivot2)
	{
		process_moves(list_a, list_b);
		pivot2--;
	}
	current = list_a->first;
	while (current->value != pivot1)
	{
		rotate_a(list_a);
		write(1, "ra\n", 3);
	}
}

/*
** Sorting the table to find the q1, median and q3
*/
void	sort_table(int *table, int ac)
{
	int	i;
	int	tmp;

	tmp = 0;
	i = 0;
	while (i < (ac - 2))
	{
		if (table[i] <= table[i + 1])
			i++;
		else
		{
			tmp = table[i];
			table[i] = table[i + 1];
			table[i + 1] = tmp;
			i = 0;
		}
	}
}

/*
 ** I put the list a in a table, sort it and find q1, median and q3
 */
void	find_med_q(t_list_a *list_a, t_quarts *quartiles, int ac)
{
	t_elem_a	*current;
	int			*table;
	int			length;
	int			i;

	current = list_a->first;
	table = malloc(sizeof(int) * (ac - 1));
	if (!table)
		exit(0);
	length = (ac - 1) / 4;
	i = 0;
	while (i < (ac - 1))
	{
		table[i] = current->value;
		current = current->next;
		i++;
	}
	sort_table(table, ac);
	quartiles->med = table[length * 2];
	quartiles->q1 = table[length];
	quartiles->q3 = table[length * 3];
	free(table);
}
