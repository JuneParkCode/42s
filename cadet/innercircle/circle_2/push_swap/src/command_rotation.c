/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_rotation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 18:01:45 by sungjpar          #+#    #+#             */
/*   Updated: 2022/07/06 09:52:29 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

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
	ft_putstr_fd("ra\n", FD_STDERR);
}

void	command_rb(t_deque *b)
{
	command_rotation(b);
	ft_putstr_fd("rb\n", FD_STDERR);
}

void	command_rr(t_deque *a, t_deque *b)
{
	command_rotation(a);
	command_rotation(b);
	ft_putstr_fd("rr\n", FD_STDERR);
}
