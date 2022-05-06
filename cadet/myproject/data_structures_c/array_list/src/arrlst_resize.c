/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrlst_resize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 14:36:31 by sungjpar          #+#    #+#             */
/*   Updated: 2022/04/18 14:44:47 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "array_list.h"

ssize_t	arrlst_resize(t_arrlist **lst, ssize_t size)
{
	t_arrlist	*new_lst;

	if (size < ((*lst)->size))
		return (-1);
	else if (size == (*lst)->size)
		return (size);
	else
	{
		new_lst = arrlst_new_list(size);
		if (new_lst == NULL)
			return (-1);
		arrlst_push_back(new_lst, arrlst_pop_front(*lst));
		free((*lst)->items);
		free(*lst);
		*lst = new_lst;
	}
	return ((*lst)->max_size);
}
