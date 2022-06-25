/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_get_funcs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.k       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 13:52:30 by sungjpar          #+#    #+#             */
/*   Updated: 2022/06/26 03:32:22 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/deque.h"

t_item	f_dq_get_front(t_deque *self)
{
	return ((self->datas)[self->front_idx]);
}

t_item	f_dq_get_back(t_deque *self)
{
	return ((self->datas)[self->back_idx]);
}
