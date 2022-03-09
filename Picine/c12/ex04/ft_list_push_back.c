/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 23:57:18 by sungjpar          #+#    #+#             */
/*   Updated: 2022/02/23 00:24:44 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_last(t_list *begin_list)
{
	t_list	*cur;

	cur = begin_list;
	while (cur && cur -> next)
		cur = cur -> next;
	return (cur);
}

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*new_list;
	t_list	*last_list;
	t_list	*head;

	new_list = ft_create_elem(data);
	head = *begin_list;
	if (!head)
	{
		*begin_list = new_list;
		return ;
	}
	last_list = ft_list_last(head);
	last_list -> next = new_list;
}
