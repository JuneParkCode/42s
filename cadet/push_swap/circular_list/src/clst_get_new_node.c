/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clst_get_new_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 18:00:09 by sungjpar          #+#    #+#             */
/*   Updated: 2022/04/15 18:01:34 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "circular_list.h"

t_dnode	*clst_get_new_node(void *content)
{
	t_dnode	*node;

	node = malloc(sizeof(t_dnode));
	node -> prev = NULL;
	node -> next = NULL;
	node -> content = content;
	return (node);
}
