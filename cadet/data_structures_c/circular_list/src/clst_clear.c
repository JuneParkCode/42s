/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clst_clear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 14:36:43 by sungjpar          #+#    #+#             */
/*   Updated: 2022/04/18 14:54:13 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "circular_list.h"

void	clst_clear(t_clist *lst, void (*f_del)(void *))
{
	t_dnode	*last_node;
	t_dnode	*node;
	t_dnode	*next_node;

	last_node = clst_last(lst);
	node = lst -> head;
	if (last_node == node)
	{
		clst_del_node(node, f_del);
		lst -> head = NULL;
		return ;
	}
	while (node -> next != lst -> head)
	{
		next_node = node -> next;
		clst_del_node(node, f_del);
		node = next_node;
	}
	lst -> head = NULL;
}
