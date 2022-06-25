/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_push_funcs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.k       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 13:53:05 by sungjpar          #+#    #+#             */
/*   Updated: 2022/06/25 17:32:53 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/deque.h"

void	f_dq_push_back(t_deque *self, t_item item)
{
	if (self->is_full_deque(self))
		return ;
	self->datas[self->back_idx] = item;
	if (self->front_idx == self->back_idx && self->current_size == 0)
		self->front_idx = self->get_next_front_idx(self);
	self->back_idx = self->get_next_back_idx(self);
	++(self->current_size);
}

void	f_dq_push_front(t_deque *self, t_item item)
{
	if (self->is_full_deque(self))
		return ;
	self->datas[self->front_idx] = item;
	if (self->front_idx == self->back_idx && self->current_size == 0)
		self->back_idx = self->get_next_back_idx(self);
	self->front_idx = self->get_next_front_idx(self);
	++(self->current_size);
}
