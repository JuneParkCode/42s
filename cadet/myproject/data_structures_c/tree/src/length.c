/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 20:06:13 by sungjpar          #+#    #+#             */
/*   Updated: 2022/05/29 20:12:20 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"

static	size_t	count_length(t_tree_node *node)
{
	if (node == NULL)
		return (0);
	else
		return (count_length(node->left) + count_length(node->right) + 1);
}

size_t	length(t_tree *tree)
{
	return (count_length(tree->root));
}
