/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clst_pop_back.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 14:36:55 by sungjpar          #+#    #+#             */
/*   Updated: 2022/04/18 14:36:56 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "circular_list.h"

t_dnode	*clst_pop_back(t_clist *lst)
{
	t_dnode	*node;
	t_dnode	*last_node;

	node = clst_last(lst);
	last_node = node -> prev;
	if (clst_check_alone(lst))
	{
		lst -> head = NULL;
	}
	else
	{
		lst -> head -> prev = last_node;
		last_node -> next = lst -> head;
	}
	return (node);
}
