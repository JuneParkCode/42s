/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clst_swap_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 17:29:58 by sungjpar          #+#    #+#             */
/*   Updated: 2022/04/15 18:10:07 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "circular_list.h"

void	clst_swap_node(t_clist *lst, t_dnode *node_a, t_dnode *node_b)
{
	t_dnode	tmp;
	t_dnode	*temp;

	temp = &tmp;
	if (node_a == NULL || node_b == NULL || node_a == node_b)
		return ;
	node_a -> prev -> next = temp;
	node_a -> next -> prev = temp;
	temp -> prev = node_a -> prev;
	temp -> next = node_a -> next;
	node_a -> prev = node_b -> prev;
	node_a -> next = node_b -> next;
	node_b -> prev -> next = node_a;
	node_b -> next -> prev = node_a;
	temp -> prev -> next = node_b;
	temp -> next -> prev = node_b;
	node_b -> prev = temp -> prev;
	node_b -> next = temp -> next;
	if (node_a == lst -> head)
		lst -> head = node_b;
	else if (node_b == lst -> head)
		lst -> head = node_a;
}
