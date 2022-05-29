/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_item.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 20:19:48 by sungjpar          #+#    #+#             */
/*   Updated: 2022/05/29 20:35:18 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "tree.h"

static void	insert(t_tree_node **node, void *item, int (*cmp)(void *, void *))
{
	t_tree_node	*new_node;
	int			cmp_res;

	if (node == NULL)
	{
		new_node = make_node(item);
		*node = new_node;
		return ;
	}
	cmp_res = cmp((*node)->content, item);
	if (cmp_res < 0)
		insert(&((*node)->right), item, cmp);
	else
		insert(&((*node)->left), item, cmp);
}

void	insert_item(t_tree *tree, void *item)
{
	insert(&(tree->root), item, tree->cmp);
}
