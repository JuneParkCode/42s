/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.k       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 16:48:48 by sungjpar          #+#    #+#             */
/*   Updated: 2022/06/27 19:43:47 by sungjpar         ###   ########.fr       */
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

static int	get_negative_element_idx(t_deque *dq)
{
	int	idx;

	idx = dq->back_idx;
	while (dq->datas[idx] >= 0)
		idx = get_next_idx(dq, idx);
	return (idx);
}

static int	is_sorted(t_deque *dq)
{
	int	idx;
	int	n;
	int	cur;
	int	next;

	if (dq->get_front(dq) < 0)
		idx = get_negative_element_idx(dq);
	else
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

static void	move_all_elements_of_b_to_a(t_deque *a, t_deque *b)
{
	while (b->current_size != 0)
		command_pa(a, b);
}

static void	sort_negatives(t_deque *a)
{
	while (a->get_front(a) < 0)
		command_rra(a);
}

static void	split(t_deque *a, t_deque *b, const int place, const int size)
{
	int	n;
	int	target_value;

	n = 0;
	while (n != size)
	{
		target_value = a->get_back(a);
		if (((target_value >> place) & 1) == 0)
			command_pb(a, b);
		else
			command_ra(a);
		++n;
	}
}

void	radix_sort(t_deque *a, t_deque *b, const int size)
{
	const int	max_len = sizeof(t_item) * 8;
	int			place;

	place = 0;
	while ((max_len - place) && !is_sorted((a)))
	{
		split(a, b, place, size);
		move_all_elements_of_b_to_a(a, b);
		++place;
	}
	if (a->get_front(a) < a->get_back(a))
		sort_negatives(a);
}
