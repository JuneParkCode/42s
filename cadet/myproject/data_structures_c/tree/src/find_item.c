/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 20:40:29 by sungjpar          #+#    #+#             */
/*   Updated: 2022/05/29 20:41:45 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"

#define false 0
#define true 1

t_tree_node	*find_node(t_tree *tree, void *item)
{
	int			(*cmp)(void *, void *);
	bool		found;
	t_tree_node	*node;
	int			cmp_res;

	cmp = tree->cmp;
	found = false;
	node = tree->root;
	while (node && !found)
	{
		cmp_res = cmp(node->content, item);
		if (cmp_res == 0)
		{
			return (node);
		}
		else if (cmp_res < 0)
		{
			node = node->left;
		}
		else
		{
			node = node->right;
		}
	}
	return (NULL);
}
