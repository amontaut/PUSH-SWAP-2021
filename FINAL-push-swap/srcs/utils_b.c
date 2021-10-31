/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontaut <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 16:32:34 by amontaut          #+#    #+#             */
/*   Updated: 2021/10/14 16:32:42 by amontaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** returns length of list b
*/
int	find_len_b(t_list_b *list_b)
{
	t_elem_b	*current;
	int			length;

	length = 0;
	current = list_b->first;
	while (current != NULL)
	{
		length++;
		current = current->next;
	}
	return (length);
}

/*
** find the biggest number in list b
*/
int	find_biggest_b(t_list_b *list_b)
{
	t_elem_b	*current;
	int			biggest;

	biggest = list_b->first->value;
	current = list_b->first;
	while (current != NULL)
	{
		if (current->value > biggest)
			biggest = current->value;
		current = current->next;
	}
	return (biggest);
}

/*
** find the smallest number in list b
*/
int	find_smallest_b(t_list_b *list_b)
{
	t_elem_b	*current;
	int			smallest;

	smallest = list_b->first->value;
	current = list_b->first;
	while (current != NULL)
	{
		if (current->value < smallest)
			smallest = current->value;
		current = current->next;
	}
	return (smallest);
}

/*
** find the biggest number's position in list b
*/
int	find_pos_big_b(t_list_b *list_b, int biggest)
{
	t_elem_b	*current;
	int			position;

	position = 1;
	current = list_b->first;
	while (current->value != biggest)
	{
		position++;
		current = current->next;
	}
	return (position);
}

/*
** find the smallest number's position in list b
*/
int	find_pos_small_b(t_list_b *list_b, int smallest)
{
	t_elem_b	*current;
	int			position;

	position = 1;
	current = list_b->first;
	while (current->value != smallest)
	{
		position++;
		current = current->next;
	}
	return (position);
}
