/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clst_add_front.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 14:36:39 by sungjpar          #+#    #+#             */
/*   Updated: 2022/04/18 14:53:33 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "circular_list.h"

void	clst_add_front(t_clist *lst, t_dnode *node)
{
	t_dnode	*last_node;

	if (lst == NULL)
		return ;
	if (lst -> head == NULL)
	{
		lst -> head = node;
		last_node = node;
	}
	else
		last_node = clst_last(lst);
	last_node -> next = node;
	lst -> head = node;
	node -> prev = last_node;
	node -> next = lst -> head;
}
