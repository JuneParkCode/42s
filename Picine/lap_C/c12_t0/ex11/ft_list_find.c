/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 17:49:12 by sungjpar          #+#    #+#             */
/*   Updated: 2022/02/23 17:50:53 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)());
{
	t_list	*cur;
	
	cur = begin_list;
	while (cur)
	{
		if (cmp(cur -> data, data_ref) == 0)
			return (cur);
		cur = cur -> next;
	}
	return (0);
}
