/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bst_find_node.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 20:40:29 by sungjpar          #+#    #+#             */
/*   Updated: 2022/05/30 10:27:40 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bst.h"

t_bst_node	*bst_find_node(t_bst *tree, void *item)
{
	int			(*cmp)(void *, void *);
	bool		found;
	t_bst_node	*node;
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
