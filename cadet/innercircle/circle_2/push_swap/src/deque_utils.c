/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 13:52:53 by sungjpar          #+#    #+#             */
/*   Updated: 2022/07/02 14:08:46 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../include/deque.h"

t_deque	*make_deque(const int size)
{
	t_deque	*dq;

	if (size <= 0)
		return (NULL);
	dq = (t_deque *)malloc(sizeof(t_deque));
	dq->datas = (t_item *)malloc(sizeof(t_item) * size);
	dq->current_size = 0;
	dq->max_size = size;
	dq->front_idx = 0;
	dq->back_idx = 0;
	dq->push_back = f_dq_push_back;
	dq->push_front = f_dq_push_front;
	dq->pop_back = f_dq_pop_back;
	dq->pop_front = f_dq_pop_front;
	dq->get_back = f_dq_get_back;
	dq->get_front = f_dq_get_front;
	dq->is_full_deque = f_dq_is_full_deque;
	dq->is_empty_deque = f_dq_is_empty_deque;
	dq->get_next_back_idx = f_dq_get_next_back_idx;
	dq->get_prev_back_idx = f_dq_get_prev_back_idx;
	dq->get_next_front_idx = f_dq_get_next_front_idx;
	dq->get_prev_front_idx = f_dq_get_prev_front_idx;
	dq->resize_deque = f_dq_resize_deque;
	return (dq);
}

void	delete_deque(t_deque *dq)
{
	free(dq->datas);
	free(dq);
}

void	f_dq_resize_deque(t_deque *self, const int size)
{
	t_deque	*tmp_deque;

	tmp_deque = make_deque(self->max_size);
	while (!(self->is_empty_deque(self)))
	{
		tmp_deque->push_front(tmp_deque, self->get_front(self));
		self->pop_front(self);
	}
	self->max_size = size;
	free(self->datas);
	self->datas = (t_item *)malloc(sizeof(t_item) * size);
	self->front_idx = 0;
	self->back_idx = 0;
	while (!(tmp_deque->is_empty_deque(tmp_deque)))
	{
		self->push_front(self, tmp_deque->get_front(tmp_deque));
		tmp_deque->pop_front(tmp_deque);
	}
	delete_deque(tmp_deque);
}

int	f_dq_is_full_deque(t_deque *self)
{
	return (self->current_size == self->max_size);
}

int	f_dq_is_empty_deque(t_deque *self)
{
	return (self->current_size == 0);
}
