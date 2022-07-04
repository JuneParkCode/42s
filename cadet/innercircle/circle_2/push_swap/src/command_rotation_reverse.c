/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_rotation_reverse.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 18:03:45 by sungjpar          #+#    #+#             */
/*   Updated: 2022/07/04 17:16:17 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

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
	ft_putstr_fd("rra\n", FD_STDIN);
}

void	command_rrb(t_deque *b)
{
	command_rotation_reverse(b);
	ft_putstr_fd("rrb\n", FD_STDIN);
}

void	command_rrr(t_deque *a, t_deque *b)
{
	command_rotation_reverse(a);
	command_rotation_reverse(b);
	ft_putstr_fd("rrr\n", FD_STDIN);
}
