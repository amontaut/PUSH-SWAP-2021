/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_in_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontaut <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 16:29:41 by amontaut          #+#    #+#             */
/*   Updated: 2021/10/14 16:29:46 by amontaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
 ** insert element at the begining of the list
 */
int	pushfront_a(t_list_a *list_a, int number)
{
	t_elem_a	*current;

	current = malloc(sizeof(t_elem_a));
	if (!current)
		exit(0);
	current->value = number;
	current->next = list_a->first;
	current->prev = NULL;
	if (list_a->first)
		list_a->first->prev = current;
	else
		list_a->last = current;
	list_a->first = current;
	return (1);
}

/*
 ** insert element at the end of the list
 */
int	pushback_a(t_list_a *list_a, int number)
{
	t_elem_a	*current;

	current = malloc(sizeof(t_elem_a));
	if (!current)
		exit(0);
	current->value = number;
	current->prev = list_a->last;
	current->next = NULL;
	if (list_a->last)
		list_a->last->next = current;
	else
		list_a->first = current;
	list_a->last = current;
	return (1);
}

/*
 ** insert element at the begining of the list
 */
int	pushfront_b(t_list_b *list_b, int number)
{
	t_elem_b	*current;

	current = malloc(sizeof(t_elem_b));
	if (!current)
		exit(0);
	current->value = number;
	current->next = list_b->first;
	current->prev = NULL;
	if (list_b->first)
		list_b->first->prev = current;
	else
		list_b->last = current;
	list_b->first = current;
	return (1);
}
