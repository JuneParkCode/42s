/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.k       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 15:45:56 by sungjpar          #+#    #+#             */
/*   Updated: 2022/07/02 16:25:29 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/push_swap.h"

static int	get_pattern(t_deque *a)
{
	const int	arr[] = {
		a->get_back(a),
		a->datas[a->front_idx + 1],
		a->get_front(a)
	};
	const int	patterns[6][3] = {
	{0, 1, 2}, {0, 2, 1},
	{1, 0, 2}, {1, 2, 0},
	{2, 0, 1}, {2, 1, 0}
	};
	int			pattern_idx;

	pattern_idx = 0;
	while (pattern_idx < 6)
	{
		if (ft_memcmp(arr, patterns[pattern_idx], sizeof(int) * 3) == 0)
			return (pattern_idx);
		++pattern_idx;
	}
	return (-1);
}

void	sort_three(t_deque *a)
{
	const int	pattern = get_pattern(a);

	if (pattern == 0)
		return ;
	else if (pattern == 1)
	{
		command_sa(a);
		command_ra(a);
	}
	else if (pattern == 2)
		command_sa(a);
	else if (pattern == 3)
		command_rra(a);
	else if (pattern == 4)
		command_ra(a);
	else if (pattern == 5)
	{
		command_sa(a);
		command_rra(a);
	}
	else
		return ;
}
