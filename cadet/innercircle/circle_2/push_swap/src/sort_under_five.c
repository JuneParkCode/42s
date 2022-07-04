/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_under_five.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 14:24:54 by sungjpar          #+#    #+#             */
/*   Updated: 2022/07/04 17:27:10 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static int	get_next_top_idx(const int idx, const int size)
{
	int	result;

	result = idx - 1;
	if (result < 0)
		result += size;
	return (result);
}

static t_bool	has_over_pivot(t_deque *a, const int pivot)
{
	int	n;
	int	idx;

	n = a->max_size;
	idx = a->back_idx;
	while (n--)
	{
		if (a->datas[idx] >= pivot)
			return (TRUE);
		idx = get_next_top_idx(idx, a->max_size);
	}
	return (FALSE);
}

static void	pb_over_pivot(t_deque *a, t_deque *b, const int size)
{
	const int	pivot = size / 2;
	int			n;
	int			idx;
	int			top;

	n = a->max_size;
	idx = a->back_idx;
	while (n-- && has_over_pivot(a, pivot))
	{
		top = a->datas[idx];
		if (top <= pivot)
			command_ra(a);
		else
			command_pb(a, b);
		idx = get_next_top_idx(idx, size);
	}
}

void	sort_two(t_deque *a)
{
	if (a->get_back(a) > a->get_front(a))
		command_sa(a);
}

void	sort_under_five(t_deque *a, t_deque *b, const int size)
{
	int	top;
	int	top_next;

	pb_over_pivot(a, b, size);
	sort_three(a);
	top = b->get_back(b);
	top_next = b->datas[get_next_top_idx(b->back_idx, size)];
	if (top < top_next)
		command_sb(b);
	while (!(b->is_empty_deque(b)))
		command_pa(a, b);
	while (!is_sorted(a))
		command_ra(a);
}
