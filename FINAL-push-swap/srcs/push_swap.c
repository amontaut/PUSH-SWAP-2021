/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontaut <amontaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 02:44:02 by amontaut          #+#    #+#             */
/*   Updated: 2021/10/31 15:56:18 by amontaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
 ** atoi and check all numbers are int
 */
int	ft_atoi(const char *str)
{
	int			i;
	int			neg;
	long long	res;

	neg = 1;
	i = 0;
	res = 0;
	while ((str[i] == 32) || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = neg * -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	check_int(res, neg);
	return (res * neg);
}

/*
** decides which fct to launch depending on the nb of args
*/
void	chose_path(t_list_a *list_a, t_list_b *list_b, int ac)
{
	if ((ac - 1) == 2)
		arg_is_2(list_a);
	else if ((ac - 1) == 3)
		arg_is_3(list_a);
	else if ((ac - 1) > 3 && (ac - 1) <= 5)
		arg_is_5_4(list_a, list_b, ac);
	else if ((ac - 1) > 5 && (ac - 1) <= 100)
		arg_is_100(list_a, list_b, ac);
	else
		arg_is_500(list_a, list_b, ac);
}

/*
** It all starts here
*/
int	main(int ac, char **av)
{
	t_list_a	list_a;
	t_list_b	list_b;
	int			i;

	i = 0;
	if (ac == 1)
		exit(0);
	init_lists(&list_a, &list_b);
	while (i < (ac - 1))
	{
		ft_atoi(av[i + 1]);
		i++;
	}
	check_duplicate(ac, av);
	i = 0;
	check_char_assign(&list_a, av, ac, i);
	check_sorted(&list_a);
	chose_path(&list_a, &list_b, ac);
	free_list_a(&list_a);
	free_list_b(&list_b);
	return (0);
}
