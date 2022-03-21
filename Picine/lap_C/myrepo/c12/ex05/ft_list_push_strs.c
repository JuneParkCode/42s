/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 23:24:27 by sungjpar          #+#    #+#             */
/*   Updated: 2022/02/23 00:24:22 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdio.h>

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*new_list;
	t_list	*head;

	new_list = ft_create_elem(data);
	head = *begin_list;
	if (!head)
		*begin_list = new_list;
	else
	{
		new_list -> next = head;
		head -> next = head -> next;
		*begin_list = new_list;
	}
}

t_list	*ft_list_push_strs(int size, char **strs)
{
	t_list	*begin_list;
	int		idx_strs;

	if (size <= 0)
		return (0);
	begin_list = ft_create_elem(strs[0]);
	idx_strs = 1;
	while (idx_strs < size)
		ft_list_push_front(&begin_list, strs[idx_strs++]);
	return (begin_list);
}
