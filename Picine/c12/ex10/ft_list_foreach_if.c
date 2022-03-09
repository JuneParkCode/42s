/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach_if.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 17:28:29 by sungjpar          #+#    #+#             */
/*   Updated: 2022/02/23 17:30:16 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_foreach_if(t_list *begin_list, void (*f)(void *), \
		void *data_ref, int (*cmp)())
{
	t_list	*cur;

	cur = begin_list;
	while (cur)
	{
		if (!cmp(cur -> data, data_ref))
			f(cur -> data);
		cur = cur -> next;
	}
}
