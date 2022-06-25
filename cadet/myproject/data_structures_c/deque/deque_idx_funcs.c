/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_idx_funcs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.k       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 17:06:06 by sungjpar          #+#    #+#             */
/*   Updated: 2022/06/25 17:06:30 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"

int	f_dq_get_next_front_idx(t_deque *self)
{
	int	front_idx;

	front_idx = self->front_idx - 1;
	if (front_idx < 0)
		front_idx += self->max_size;
	return (front_idx);
}

int f_dq_get_next_back_idx(t_deque *self)
{
	int	back_idx;

	back_idx = (self->back_idx + 1) % (self->max_size);
	return (back_idx);
}

int	f_dq_get_prev_front_idx(t_deque *self)
{
	int	front_idx;

	front_idx = (self->front_idx + 1) % (self->max_size);
	return (front_idx);
}

int	f_dq_get_prev_back_idx(t_deque *self)
{
	int	back_idx;

	back_idx = self->back_idx - 1;
	if (back_idx < 0)
		back_idx += self->max_size;
	return (back_idx);
}
