/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontaut <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 16:16:31 by amontaut          #+#    #+#             */
/*   Updated: 2021/10/14 16:16:46 by amontaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <limits.h>

typedef struct s_elem_a
{
	int				value;
	struct s_elem_a	*prev;
	struct s_elem_a	*next;
}	t_elem_a;

typedef struct s_elem_b
{
	int				value;
	struct s_elem_b	*prev;
	struct s_elem_b	*next;
}	t_elem_b;

typedef struct s_list_a
{
	t_elem_a	*first;
	t_elem_a	*last;
}	t_list_a;

typedef struct s_list_b
{
	t_elem_b	*first;
	t_elem_b	*last;
}	t_list_b;

typedef struct s_count_moves
{
	int	big_rb;
	int	big_rrb;
	int	small_rb;
	int	small_rrb;
}	t_count_moves;

typedef struct s_quarts
{
	int	med;
	int	q1;
	int	q3;
	int	bellow_q1;
	int	bellow_med;
	int	bellow_q3;
	int	bellow_end;
	int	above_med;
}	t_quarts;

void	init_lists(t_list_a *list_a, t_list_b *list_b);
void	free_list_a(t_list_a *list_a);
void	free_list_b(t_list_b *list_b);
void	swap_a(t_list_a *list_a);
void	push_a(t_list_a *list_a, t_list_b *list_b);
void	rotate_a(t_list_a *list_a);
void	reverse_rotate_a(t_list_a *list_a);
void	swap_b(t_list_b *list_b);
void	push_b(t_list_a *list_a, t_list_b *list_b);
void	rotate_b(t_list_b *list_b);
void	reverse_rotate_b(t_list_b *list_b);
int		find_len_a(t_list_a *list_a);
int		find_biggest_a(t_list_a *list_a);
int		find_smallest_a(t_list_a *list_a);
int		find_pos_small_a(t_list_a *list_a, int smallest);
int		find_len_b(t_list_b *list_b);
int		find_biggest_b(t_list_b *list_b);
int		find_smallest_b(t_list_b *list_b);
int		find_pos_big_b(t_list_b *list_b, int biggest);
int		find_pos_small_b(t_list_b *list_b, int smallest);
int		pushfront_a(t_list_a *list_a, int number);
int		pushback_a(t_list_a *list_a, int number);
int		pushfront_b(t_list_b *list_b, int number);
void	push_bellow_q1(t_list_a *list_a, t_list_b *list_b, t_quarts *quartiles, \
int ac);
void	push_q1_med(t_list_a *list_a, t_list_b *list_b, t_quarts *quartiles, \
int ac);
void	push_med_q3(t_list_a *list_a, t_list_b *list_b, t_quarts *quartiles, \
int ac);
void	push_above_q3(t_list_a *list_a, t_list_b *list_b, t_quarts *quartiles, \
int ac);
void	push_bellow_med(t_list_a *list_a, t_list_b *list_b, \
t_quarts *quartiles, int ac);
void	push_above_med(t_list_a *list_a, t_list_b *list_b, t_quarts *quartiles, \
int ac);
void	check_int(long long res, int neg);
void	check_sorted(t_list_a *list_a);
void	check_char_assign(t_list_a *list_a, char **av, int ac, int i);
void	check_duplicate(int ac, char **av);
void	arg_is_2(t_list_a *list_a);
void	arg_is_3(t_list_a *list_a);
void	arg_is_5_4(t_list_a *list_a, t_list_b *list_b, int ac);
void	arg_is_5(t_list_a *list_a, t_list_b *list_b, int smallest, \
int position);
void	arg_is_100(t_list_a *list_a, t_list_b *list_b, int ac);
void	arg_is_500(t_list_a *list_a, t_list_b *list_b, int ac);
void	ra_or_rra(t_list_a *list_a, t_list_b *list_b, int position, \
int length_a);
void	find_med_q(t_list_a *list_a, t_quarts *quartiles, int ac);
int		count_first(t_list_a *list_a, int max);
int		count_mid(t_list_a *list_a, int mid_1, int mid_2);
int		count_last(t_list_a *list_a, int last);
void	sort_a_b(t_list_a *list_a, t_list_b *list_b, int pivot1, int pivot2);
int		ft_atoi(const char *str);
#endif
