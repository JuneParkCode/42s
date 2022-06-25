/* ************************************************************************** */

/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_rotation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.k       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 18:01:45 by sungjpar          #+#    #+#             */
/*   Updated: 2022/06/25 18:03:27 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	command_rotation(t_deque *dq)
{
	t_item	top_item;

	top_item = dq->get_back(dq);
	dq->pop_back(dq);
	dq->push_front(dq, top_item);
}

void	command_ra(t_deque *a)
{
	command_rotation(a);
}

void	command_rb(t_deque *b)
{
	command_rotation(b);
}

void	command_rr(t_deque *a, t_deque *b)
{
	command_rotation(a);
	command_rotation(b);
}