/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bst_retrieve_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 20:13:29 by sungjpar          #+#    #+#             */
/*   Updated: 2022/05/30 10:46:01 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bst.h"

bool	bst_retrieve_item(t_bst *tree, void *item)
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
			return (true);
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
	return (false);
}
