/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_pop_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.k       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 13:53:03 by sungjpar          #+#    #+#             */
/*   Updated: 2022/06/25 17:32:38 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/deque.h"

void	f_dq_pop_front(t_deque *self)
{
	if (self->is_empty_deque(self))
		return ;
	self->front_idx = self->get_prev_front_idx(self);
	--(self->current_size);
	if (self->current_size == 0)
		self->back_idx = self->front_idx;
}

void	f_dq_pop_back(t_deque *self)
{
	if (self->is_empty_deque(self))
		return ;
	self->back_idx = self->get_prev_back_idx(self);
	--(self->current_size);
	if (self->current_size == 0)
		self->front_idx = self->back_idx;
}
