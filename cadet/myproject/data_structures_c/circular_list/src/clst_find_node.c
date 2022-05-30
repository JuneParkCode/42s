/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clst_find_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 14:36:48 by sungjpar          #+#    #+#             */
/*   Updated: 2022/05/30 10:37:48 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "circular_list.h"

t_dnode	*clst_find_node(t_clist *lst, void *content, \
		int (*f_cmp)(void *, void *))
{
	t_dnode	*node;

	node = lst -> head;
	if (f_cmp(content, node -> content) == 0)
		return (node);
	while (node -> next != lst -> head)
	{
		node = node -> next;
		if (f_cmp(content, node -> content) == 0)
			return (node);
	}
	return (NULL);
}
