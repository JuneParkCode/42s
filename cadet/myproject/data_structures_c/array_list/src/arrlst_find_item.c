/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrlst_find_item.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 14:36:13 by sungjpar          #+#    #+#             */
/*   Updated: 2022/04/18 14:43:32 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array_list.h"

ssize_t	arrlst_find_item(t_arrlist *lst, t_item item, \
		int (*cmp)(t_item, t_item))
{
	ssize_t	pos;

	if (arrlst_is_empty(lst))
		return (NOT_FOUND);
	if (cmp((lst -> items)[lst -> rear], item) == 0)
		return (lst -> rear);
	pos = lst -> front;
	while (pos != lst -> rear)
	{
		if (cmp((lst -> items)[pos], item) == 0)
			return (pos);
		pos = pos + 1;
		if (pos >= lst -> max_size)
			pos = pos - lst -> max_size;
	}
	return (NOT_FOUND);
}
