/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clst_last.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 17:24:31 by sungjpar          #+#    #+#             */
/*   Updated: 2022/04/15 18:54:57 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "circular_list.h"

t_dnode	*clst_last(t_clist *lst)
{
	t_dnode	*node;

	node = lst -> head;
	if (node == NULL)
		return (NULL);
	while (node -> next != lst -> head)
	{
		node = node -> next;
	}
	return (node);
}
