/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.k       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 13:52:53 by sungjpar          #+#    #+#             */
/*   Updated: 2022/06/25 17:34:20 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../include/deque.h"

t_deque	*make_deque(const unsigned int size)
{
	t_deque	*dq;

	dq = (t_deque *)malloc(sizeof(t_deque));
	if (dq == NULL)
		return (NULL);
	dq->datas = (t_item *)malloc(sizeof(t_item));
	if (dq->datas == NULL)
		return (NULL);
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
	return (dq);
}

void	delete_deque(t_deque *dq)
{
	free(dq->datas);
	free(dq);
}

int	f_dq_is_full_deque(t_deque *self)
{
	return (self->current_size == self->max_size);
}

int	f_dq_is_empty_deque(t_deque *self)
{
	return (self->current_size == 0);
}
