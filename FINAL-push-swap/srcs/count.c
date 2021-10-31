/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontaut <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 16:24:08 by amontaut          #+#    #+#             */
/*   Updated: 2021/10/14 16:24:14 by amontaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
 ** I count how many numbers are under med (for 100) or under q1 (for 500)
 ** to know how many times I have to launch the fct process moves
*/
int	count_first(t_list_a *list_a, int max)
{
	t_elem_a	*current;
	int			count;

	count = 0;
	current = list_a->first;
	while (current != NULL)
	{
		if (current->value <= max)
			count++;
		current = current->next;
	}
	return (count);
}

/*
 ** I count how many numbers are between q1 and med and med and q3 (for 500)
 ** to know how many times I have to push numbers from a to b
 */
int	count_mid(t_list_a *list_a, int mid_1, int mid_2)
{
	t_elem_a	*current;
	int			count;

	count = 0;
	current = list_a->first;
	while (current != NULL)
	{
		if (current->value > mid_1 && current->value <= mid_2)
			count++;
		current = current->next;
	}
	return (count);
}

/*
 ** I count how many numbers are above med (for 100) or above q3 (for 500)
 ** to know how many times I have to push numbers from a to b
 */
int	count_last(t_list_a *list_a, int last)
{
	t_elem_a	*current;
	int			count;

	current = list_a->first;
	count = 0;
	while (current != NULL)
	{
		if (current->value > last)
			count++;
		current = current->next;
	}
	return (count);
}
