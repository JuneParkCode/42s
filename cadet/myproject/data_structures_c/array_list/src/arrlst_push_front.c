/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrlst_push_front.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 14:42:12 by sungjpar          #+#    #+#             */
/*   Updated: 2022/04/18 14:42:13 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array_list.h"

int	arrlst_push_front(t_arrlist *lst, t_item item)
{
	ssize_t	pos;

	if (arrlst_is_full(lst))
		return (FUNC_ERR);
	if (arrlst_is_empty(lst))
	{
		if (lst -> front == -1)
			pos = 0;
		else
			pos = lst -> front;
		lst -> front = pos;
		lst -> rear = pos;
	}
	else
	{
		pos = lst -> front - 1;
		if (pos < 0)
			pos = lst -> max_size + pos;
		lst -> front = pos;
	}
	lst -> items[pos] = item;
	++(lst -> size);
	return (SUCCESS);
}
