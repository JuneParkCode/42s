/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_pop_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.k       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 13:53:03 by sungjpar          #+#    #+#             */
/*   Updated: 2022/06/26 03:56:35 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"

void  f_dq_pop_front(t_deque *self)
{
	if (self->is_empty_deque(self))
		return ;
	self->front_idx = self->get_prev_front_idx(self);
	--(self->current_size);
}

void  f_dq_pop_back(t_deque *self)
{
	if (self->is_empty_deque(self))
		return ;
	self->back_idx = self->get_prev_back_idx(self);
	--(self->current_size);
}
