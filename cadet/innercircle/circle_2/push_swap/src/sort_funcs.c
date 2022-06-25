/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.k       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 19:24:34 by sungjpar          #+#    #+#             */
/*   Updated: 2022/06/26 05:01:48 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	up(t_deque *a, t_deque *b, const int size)
{
	int	n;

	n = size;
	while (n--)
	{
		command_pa(a, b);
	}
}

void	merge(t_deque *a, t_deque *b, int start, int mid, int end)
{
	const int	size = end - start + 1;
	int 		n;
	int			pivot;
	int			a_searched = 0;
	int			b_searched = 0;

	pivot = mid - start + 1;
	if (b->current_size > start)
	{
		n = 0;
		while(b->current_size > start + pivot)
		{
			command_pa(a, b);
			command_ra(a);
			++n;
		}
		while (n--)
			command_rra(a);
	}
	else
	{
		n = pivot;
		while (n--)
			command_pb(a, b);
	}
	n = size;
	while (n--)
	{
		if (a_searched == (size - pivot))
		{
			command_rb(b);
		}
		else if (b_searched == pivot)
		{
			command_pb(a, b);
			command_rb(b);
		}
		else
		{
			if (a->get_back(a) > b->get_back(b))
			{
				command_pb(a, b);
				command_rb(b);
				++a_searched;
			}
			else
			{
				command_rb(b);
				++b_searched;
			}
		}
	};
	n = size;
	while (n--)
		command_rrb(b);
}


void	sort(t_deque *a, t_deque *b, const int start, const int end)
{
	int			mid;

	if (start < end)
	{
		mid = (start + end) / 2;
		sort(a, b, start, mid);
		sort(a, b, mid + 1, end);
		merge(a, b, start, mid, end);
	}
}
