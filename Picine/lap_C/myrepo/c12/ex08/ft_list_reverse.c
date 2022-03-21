/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 16:49:23 by sungjpar          #+#    #+#             */
/*   Updated: 2022/02/23 17:26:58 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_get_tail(t_list **begin_list)
{
	t_list	*cur;
	t_list	*head;

	head = *begin_list;
	cur = head;
	if (!cur)
		return (0);
	while (cur -> next)
		cur = cur -> next;
	return (cur);
}

t_list	*ft_list_detach_list(t_list **begin_list, t_list *current)
{
	t_list	*cur;

	cur = *begin_list;
	if (*begin_list == current)
		*begin_list = 0;
	while (cur -> next == current)
		cur = cur -> next;
	cur -> next = current -> next;
	current -> next = 0;
	return (current);
}

void	ft_list_push_back(t_list **begin_list, t_list *current)
{
	t_list	*cur;
	t_list	*tail;

	tail = ft_get_tail(begin_list);
	if (*begin_list == 0)
		*begin_list = current;
	tail -> next = current;
}

void	ft_list_reverse(t_list **begin_list)
{
	t_list	*tail;
	t_list	*cur;
	t_list	*temp;

	cur = *begin_list;
	tail = ft_get_tail(begin_list);
	while (cur != tail)
	{
		temp = cur -> next;
		ft_list_detach_list(begin_list, cur);
		ft_list_push_back(begin_list, cur);
		cur = temp;
	}
}
