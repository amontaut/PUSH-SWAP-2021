/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontaut <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 16:25:03 by amontaut          #+#    #+#             */
/*   Updated: 2021/10/14 16:25:10 by amontaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* 
 ** swap the first 2 elements at the top of stack a. 
 ** Do nothing if there is only one or no elements. 
 */
void	swap_a(t_list_a *list_a)
{
	t_elem_a	*current;
	int			tmp;

	current = list_a->first;
	if (list_a->first != NULL || current->next != NULL)
	{
		tmp = current->value;
		current->value = current->next->value;
		current->next->value = tmp;
	}
}

/* 
 ** take the first element at the top of b and put it at the top of a.
 ** Do nothing if b is empty. 
 */
void	push_a(t_list_a *list_a, t_list_b *list_b)
{
	t_elem_b	*current;

	if (list_b->first != NULL)
	{
		current = list_b->first;
		pushfront_a(list_a, current->value);
		list_b->first = current->next;
		free(current);
	}
}

/* 
 ** shift up all elements of stack a by 1. 
 ** The first element becomes the last one. 
 */
void	rotate_a(t_list_a *list_a)
{
	t_elem_a	*current;
	int			tmp;

	current = list_a->first;
	if (list_a->first != NULL || current->next != NULL)
	{
		if (current->next->next == NULL)
			swap_a(list_a);
		else
		{
			tmp = current->value;
			while (current->next != list_a->last)
			{
				current->value = current->next->value;
				current = current->next;
				current->value = current->next->value;
			}
			current = current->next;
			current->value = tmp;
		}
	}
}

/* 
 ** shift down all elements of stack a by 1. 
 ** The last element becomes the first one. 
 */
void	reverse_rotate_a(t_list_a *list_a)
{
	t_elem_a	*current;
	int			tmp;

	current = list_a->last;
	if (list_a->first != NULL || current->prev != NULL)
	{
		if (current->prev->prev == NULL)
			swap_a(list_a);
		else
		{
			tmp = current->value;
			while (current->prev != list_a->first)
			{
				current->value = current->prev->value;
				current = current->prev;
				current->value = current->prev->value;
			}
			current = list_a->first;
			current->value = tmp;
		}
	}
}
