/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bst_insert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 20:19:48 by sungjpar          #+#    #+#             */
/*   Updated: 2022/05/30 10:27:55 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "bst.h"

static void	insert(t_bst_node **node, void *item, int (*cmp)(void *, void *))
{
	t_bst_node	*new_node;
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

void	bst_insert(t_bst *tree, void *item)
{
	insert(&(tree->root), item, tree->cmp);
}
