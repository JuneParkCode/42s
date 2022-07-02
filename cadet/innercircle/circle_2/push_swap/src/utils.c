/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.k       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 14:27:03 by sungjpar          #+#    #+#             */
/*   Updated: 2022/07/02 16:25:36 by sungjpar         ###   ########.fr       */
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

t_bool	is_sorted(t_deque *dq)
{
	int	idx;
	int	n;
	int	cur;
	int	next;

	idx = dq->back_idx;
	n = dq->max_size;
	while (--n)
	{
		cur = dq->datas[idx];
		idx = get_next_idx(dq, idx);
		next = dq->datas[idx];
		if (cur > next)
			return (FALSE);
	}
	return (TRUE);
}
