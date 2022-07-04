/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_duplicate_number.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 10:07:03 by sungjpar          #+#    #+#             */
/*   Updated: 2022/07/04 17:07:02 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

/* INPUT DEQUE MUST CURRENT SIZE == MAX_SIZE */

t_bool	has_duplicate_number(t_deque *dq)
{
	int	idx;
	int	inner_idx;

	idx = 0;
	while (idx < dq->max_size)
	{
		inner_idx = 0;
		while (inner_idx < idx)
		{
			if (dq->datas[inner_idx] == dq->datas[idx])
				return (TRUE);
			++inner_idx;
		}
		idx++;
	}
	return (FALSE);
}
