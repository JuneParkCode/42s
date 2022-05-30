/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bst_delete_item.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 20:35:24 by sungjpar          #+#    #+#             */
/*   Updated: 2022/05/30 10:29:57 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "bst.h"

void	bst_delete_item(t_bst *tree, void *item)
{
	t_bst_node	*node;

	node = find_node(tree, item);
	if (node == NULL)
		return ;
}
