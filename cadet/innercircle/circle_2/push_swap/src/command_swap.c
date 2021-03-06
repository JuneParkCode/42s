/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 17:48:24 by sungjpar          #+#    #+#             */
/*   Updated: 2022/07/06 10:02:42 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	swap(t_item	*a, t_item *b)
{
	t_item	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	command_swap(t_deque *dq)
{
	int		back_idx;
	int		back_prev_idx;
	t_item	*top_item;
	t_item	*swap_target_item;

	back_idx = dq->back_idx;
	back_prev_idx = dq->get_prev_back_idx(dq);
	top_item = &(dq->datas[back_idx]);
	swap_target_item = &(dq->datas[back_prev_idx]);
	swap(top_item, swap_target_item);
}

void	command_sa(t_deque *a)
{
	command_swap(a);
	ft_putstr_fd("sa\n", FD_STDOUT);
}

void	command_sb(t_deque *b)
{
	command_swap(b);
	ft_putstr_fd("sb\n", FD_STDOUT);
}

void	command_ss(t_deque *a, t_deque *b)
{
	command_swap(a);
	command_swap(b);
	ft_putstr_fd("ss\n", FD_STDOUT);
}
