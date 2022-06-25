/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_push_funcs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.k       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 13:53:05 by sungjpar          #+#    #+#             */
/*   Updated: 2022/06/26 04:14:27 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/deque.h"

void	f_dq_push_back(t_deque *self, t_item item)
{
	if (self->is_full_deque(self))
		return ;
	if (self->back_idx == self->front_idx && self->current_size == 0)
	{
		self->datas[self->back_idx] = item;
	}
	else
	{
		self->back_idx = self->get_next_back_idx(self);
		self->datas[self->back_idx] = item;	
	}
	++(self->current_size);
}

void	f_dq_push_front(t_deque *self, t_item item)
{
	if (self->is_full_deque(self))
		return ;
	if (self->back_idx == self->front_idx && self->current_size == 0)
	{
		self->datas[self->front_idx] = item;
	}
	else
	{
		self->front_idx = self->get_next_front_idx(self);
		self->datas[self->front_idx] = item;	
	}
	++(self->current_size);
}
