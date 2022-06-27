/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort_triple.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.k       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 16:48:48 by sungjpar          #+#    #+#             */
/*   Updated: 2022/06/27 21:25:41 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	get_next_idx(t_deque *dq, const int idx)
{
	int	result;

	result = idx - 1;
	if (result < 0)
		result += dq->max_size;
	return (result);
}

static void	move_all_elements_of_b_to_a(t_deque *a, t_deque *b, const int pivot)
{
	while (b->current_size != 0)
	{
		command_pa(a, b);
		if (b-> current_size < pivot)
			command_ra(a);
	}
}

static t_item	get_div(const int place)
{
	t_item	res;
	int			i;

	res = 1;
	i = 0;
	while (i < place)
	{
		res *= 3;
		++i;
	}
	return (res);
}
/*
static t_item	get_max(t_deque *dq)
{
	int		idx;
	int		n;
	t_item	res;
	t_item	target;

	idx = dq->back_idx;
	n = dq->max_size;
	res = dq->get_back(dq);
	while (n--)
	{
		target = dq->datas[idx];
		if (res < target)
			res = target;;
		idx = get_next_idx(dq, idx);
	}
	return (res);
}

static int	get_max_len(t_deque *dq)
{
	const t_item	max_value = get_max(dq);
	t_item			tmp;
	int				res;

	tmp = max_value;
	res = 0;
	while (tmp)
	{
		tmp /= 3;
		++res;
	}
	return (res);
}
*/

static int	split(t_deque *a, t_deque *b, const int place, const int size)
{
	const t_item	div = get_div(place);
	t_item			target_value;
	int				n;
	int				mod;
	int				pivot;

	n = 0;
	pivot = 0;
	while (n != size)
	{
		target_value = a->get_back(a);
		mod = (target_value / div) % 3;
		if (mod == 0)
			command_pb(a, b);
		else if (mod == 1)
			command_ra(a);
		else
		{
			command_pb(a, b);
			command_rb(b);
			++pivot;
		}
		++n;
	}
	return (pivot);
}

static int	is_sorted(t_deque *dq)
{
	int		idx;
	int		n;
	t_item	cur;
	t_item	next;

	idx = dq->back_idx;
	n = dq->max_size;
	while (--n)
	{
		cur = dq->datas[idx];
		idx = get_next_idx(dq, idx);
		next = dq->datas[idx];
		if (cur > next)
			return (0);
	}
	return (1);
}

void	radix_sort(t_deque *a, t_deque *b, const int size)
{
	int			place;
	int			pivot;

	place = 0;
	while (!is_sorted(a))
	{
		pivot = split(a, b, place, size);
		move_all_elements_of_b_to_a(a, b, pivot);
		++place;
	}
}
