/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 21:10:12 by sungjpar          #+#    #+#             */
/*   Updated: 2022/02/23 21:13:51 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_list	*ft_list_detach(t_list **begin_list, t_list *current)
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

t_list	*ft_list_last(t_list *begin_list)
{
	t_list	*cur;

	cur = begin_list;
	while (cur && cur -> next)
		cur = cur -> next;
	return (cur);
}

void ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list	*tail;

	tail = ft_list_last(*begin_list);
	tail -> next = begin_list2;
}
