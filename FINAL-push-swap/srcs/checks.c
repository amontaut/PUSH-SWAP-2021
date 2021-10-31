/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontaut <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 16:23:21 by amontaut          #+#    #+#             */
/*   Updated: 2021/10/14 16:23:27 by amontaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** check all numbers are incl between int max and int min 
** int max = 2147483647
** int min = -2147483648
*/
void	check_int(long long res, int neg)
{
	if ((res >= 2147483648 && neg == 1) || (res > 2147483648 && neg == -1))
	{
		write(1, "Error\n", 6);
		exit(0);
	}
}

/*
 ** check is the list is sorted at the begining. 
 ** Exits if its the case
 */
void	check_sorted(t_list_a *list_a)
{
	t_elem_a	*current;
	int			sorted;

	current = list_a->first;
	sorted = 1;
	while (current != list_a->last)
	{
		if (current->value > current->next->value)
			sorted = 0;
		current = current->next;
	}
	if (sorted == 1)
	{
		free_list_a(list_a);
		exit(0);
	}
}

/*
** check if there are only numbers in the args
** and assigns them into the chained list
*/
void	check_char_assign(t_list_a *list_a, char **av, int ac, int i)
{
	int	j;
	int	c;

	j = 1;
	while (j < ac)
	{
		c = 0;
		while (av[i + 1][c])
		{
			if ((av[i + 1][c] == 45 && (!(av[i + 1][c + 1] > 47 && av[i + 1] \
			[c + 1] < 58))) || ((av[i + 1][c] == 43 && (!(av[i + 1][c + 1] > 47 \
			&& av[i + 1][c + 1] < 58)))) || (((av[i + 1][c] < 43) || (av[i + 1] \
			[c] == 44) || (av[i + 1][c] == 46 || av[i + 1][c] == 47)) \
			|| ((av[i + 1][c] > 57))))
			{
				write(1, "Error\n", 6);
				free_list_a(list_a);
				exit(0);
			}
			c++;
		}
		pushback_a(list_a, ft_atoi(av[i + 1]));
		i++;
		j++;
	}
}

/*
** puts all args in a table to check if there is a 
** duplicate
*/
int	*put_in_table(int ac, char **av)
{
	int	*table;
	int	i;

	i = 0;
	table = malloc(sizeof(int) * (ac - 1));
	if (!table)
		exit(0);
	i = 0;
	while (i < (ac - 1))
	{
		table[i] = ft_atoi(av[i + 1]);
		i++;
	}
	return (table);
}

/*
** check if there is a duplicate in all args
*/
void	check_duplicate(int ac, char **av)
{
	int	i;
	int	*table;
	int	j;

	table = put_in_table(ac, av);
	i = 0;
	j = 1;
	while (i < (ac - 1))
	{
		j = i + 1;
		while (j < (ac - 1))
		{
			if (table[i] == table[j])
			{
				free(table);
				write(1, "Error\n", 6);
				exit(0);
			}
			j++;
		}
		i++;
	}
	free(table);
}
