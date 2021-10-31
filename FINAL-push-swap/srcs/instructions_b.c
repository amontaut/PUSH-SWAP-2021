/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontaut <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 16:28:39 by amontaut          #+#    #+#             */
/*   Updated: 2021/10/14 16:28:44 by amontaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* 
 ** swap the first 2 elements at the top of stack b. 
 ** Do nothing if there is only one or no elements). 
 */
void	swap_b(t_list_b *list_b)
{
	t_elem_b	*current;
	int			tmp;

	current = list_b->first;
	if (list_b->first != NULL || current->next != NULL)
	{
		tmp = current->value;
		current->value = current->next->value;
		current->next->value = tmp;
	}
}

/* 
 ** take the first element at the top of a and put it at the top of b 
 */
void	push_b(t_list_a *list_a, t_list_b *list_b)
{
	t_elem_a	*current;

	current = list_a->first;
	if (list_a->first != NULL)
	{
		pushfront_b(list_b, current->value);
		list_a->first = current->next;
		free(current);
	}
}

/* 
 ** shift up all elements of stack bb by 1. 
 ** The first element becomes the last one. 
 */
void	rotate_b(t_list_b *list_b)
{
	t_elem_b	*current;
	int			tmp;

	current = list_b->first;
	if (list_b->first != NULL || current->next != NULL)
	{
		if (current->next->next == NULL)
			swap_b(list_b);
		else
		{
			tmp = current->value;
			while (current->next != list_b->last)
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
 ** shift down all elements of stack b by 1. 
 ** The last element becomes the first one. 
 */
void	reverse_rotate_b(t_list_b *list_b)
{
	t_elem_b	*current;
	int			tmp;

	current = list_b->last;
	if (list_b->first != NULL || current->prev != NULL)
	{
		if (current->prev->prev == NULL)
			swap_b(list_b);
		else
		{
			tmp = current->value;
			while (current->prev != list_b->first)
			{
				current->value = current->prev->value;
				current = current->prev;
				current->value = current->prev->value;
			}
			current = list_b->first;
			current->value = tmp;
		}
	}
}
