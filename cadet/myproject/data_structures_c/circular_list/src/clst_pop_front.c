/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clst_pop_front.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 14:36:57 by sungjpar          #+#    #+#             */
/*   Updated: 2022/04/18 14:57:29 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "circular_list.h"

t_dnode	*clst_pop_front(t_clist *lst)
{
	t_dnode	*node;
	t_dnode	*last_node;

	node = lst -> head;
	last_node = clst_last(lst);
	if (clst_check_alone(lst))
	{
		lst -> head = NULL;
	}
	else
	{
		lst -> head = lst -> head -> next;
		lst -> head -> prev = last_node;
		last_node -> next = lst -> head;
	}
	return (node);
}
