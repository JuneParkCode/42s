/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clst_get_length.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 17:28:18 by sungjpar          #+#    #+#             */
/*   Updated: 2022/04/15 17:29:29 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "circular_list.h"

size_t	clst_get_length(t_clist *lst)
{
	size_t	length;
	t_dnode	*node;

	length = 0;
	node = lst -> head;
	while (node)
	{
		node = node -> next;
	}
	return (length);
}
