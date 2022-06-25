/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_rotation_reverse.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.k       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 18:03:45 by sungjpar          #+#    #+#             */
/*   Updated: 2022/06/25 18:15:52 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	command_rotation_reverse(t_deque *dq)
{
	t_item	bottom_item;

	bottom_item = dq->get_front(dq);
	dq->pop_front(dq);
	dq->push_back(dq, bottom_item);
}

void	command_rra(t_deque *a)
{
	command_rotation_reverse(a);
	ft_printf("rra\n");
}

void	command_rrb(t_deque *b)
{
	command_rotation_reverse(b);
	ft_printf("rrb\n");
}

void	command_rrr(t_deque *a, t_deque *b)
{
	command_rotation_reverse(a);
	command_rotation_reverse(b);
	ft_printf("rrr\n");
}
