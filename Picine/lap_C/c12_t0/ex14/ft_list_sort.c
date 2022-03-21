/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 21:14:34 by sungjpar          #+#    #+#             */
/*   Updated: 2022/02/24 17:30:08 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdio.h>
t_list	show_list(t_list **begin_list);

void	ft_list_swap(t_list **begin_list, t_list *node_1, t_list *node_2)
{
	t_list	*prev_1;
	t_list	*prev_2;
	t_list	tmp;

	prev_1 = *begin_list;
	prev_2 = *begin_list;
	while (prev_1 && prev_1 -> next != node_1)
		prev_1 = prev_1 -> next;
	while (prev_2 && prev_2 -> next != node_2)
		prev_2 = prev_2 -> next;
	prev_1 -> next = &tmp;
	tmp.next = node_1 -> next;
	prev_2 -> next = node_1;
	node_1 -> next = node_2 -> next;
	prev_1 -> next = node_2;
	node_2 -> next = tmp.next;
}

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*cur;
	t_list	*target;
	t_list	*next;
	t_list	*tmp;

	tmp = *begin_list;
	while (tmp)
	{
		cur = tmp -> next;
		target = tmp;
		while (cur)
		{
			if (cur && cmp(tmp -> data, cur -> data) > 0)
				target = cur;
			cur = cur -> next;
		}
		if (target != tmp)
		{
			ft_list_swap(begin_list, tmp, target);
			show_list(begin_list);
			printf("SWAP! %s <-> %s\n", target -> data, tmp -> data);
			printf("a b! %p -> %p  %p -> %p \n", target, target -> next, tmp, tmp -> next);

			tmp = target -> next;
		}
		else
			tmp = tmp -> next;
	}
}
