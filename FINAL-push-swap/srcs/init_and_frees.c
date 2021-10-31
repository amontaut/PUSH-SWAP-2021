/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_and_frees.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontaut <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 16:24:37 by amontaut          #+#    #+#             */
/*   Updated: 2021/10/14 16:24:44 by amontaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
 ** init firsts and lasts element to null
 */
void	init_lists(t_list_a *list_a, t_list_b *list_b)
{
	list_a->first = NULL;
	list_a->last = NULL;
	list_b->first = NULL;
	list_b->last = NULL;
}

/*
** free list a properly when needed
*/
void	free_list_a(t_list_a *list_a)
{
	t_elem_a	*current;
	t_elem_a	*delete;

	if (list_a->first != NULL)
	{
		current = list_a->first;
		while (current != NULL)
		{
			delete = current;
			current = current->next;
			free(delete);
		}
	}
}

/*
** free list b properly when needed
*/
void	free_list_b(t_list_b *list_b)
{
	t_elem_b	*current;
	t_elem_b	*delete;

	if (list_b->first != NULL)
	{
		current = list_b->first;
		while (current != NULL)
		{
			delete = current;
			current = current->next;
			free(delete);
		}
	}
}
