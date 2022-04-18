/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrlst_pop_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 14:41:07 by sungjpar          #+#    #+#             */
/*   Updated: 2022/04/18 14:41:11 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array_list.h"

/*  if lst is empty -> undefined */
t_item	arrlst_pop_back(t_arrlist *lst)
{
	t_item	item;
	ssize_t	pos;

	item = lst -> items[lst -> rear];
	pos = lst -> rear - 1;
	if (pos < 0)
		pos = lst -> max_size + pos;
	lst -> rear = pos;
	--(lst -> size);
	return (item);
}
