/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontaut <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 16:30:26 by amontaut          #+#    #+#             */
/*   Updated: 2021/10/14 16:32:29 by amontaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** returns length of list a
*/
int	find_len_a(t_list_a *list_a)
{
	t_elem_a	*current;
	int			length;

	length = 0;
	current = list_a->first;
	while (current != NULL)
	{
		length++;
		current = current->next;
	}
	return (length);
}

/*
** find the biggest number in list a
*/
int	find_biggest_a(t_list_a *list_a)
{
	t_elem_a	*current;
	int			biggest;

	biggest = list_a->first->value;
	current = list_a->first;
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
int	find_smallest_a(t_list_a *list_a)
{
	t_elem_a	*current;
	int			smallest;

	smallest = list_a->first->value;
	current = list_a->first;
	while (current != NULL)
	{
		if (current->value < smallest)
			smallest = current->value;
		current = current->next;
	}
	return (smallest);
}

/*
** find the smallest number's position in list a
*/
int	find_pos_small_a(t_list_a *list_a, int smallest)
{
	t_elem_a	*current;
	int			position;

	position = 1;
	current = list_a->first;
	while (current->value != smallest)
	{
		position++;
		current = current->next;
	}
	return (position);
}
