/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clst_print_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 18:02:27 by sungjpar          #+#    #+#             */
/*   Updated: 2022/04/15 19:10:55 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "circular_list.h"

void	clst_print_list(t_clist *lst, void (*f_print)(void *))
{
	t_dnode	*node;

	node = lst -> head;
	while (node)
	{
		f_print(node -> content);
		node = node -> next;
		if (node == lst -> head)
			break ;
	}
}