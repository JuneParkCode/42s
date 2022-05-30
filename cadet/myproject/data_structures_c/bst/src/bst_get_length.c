/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bst_get_length.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 20:06:13 by sungjpar          #+#    #+#             */
/*   Updated: 2022/05/30 10:27:48 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bst.h"

static	size_t	count_length(t_bst_node *node)
{
	if (node == NULL)
		return (0);
	else
		return (count_length(node->left) + count_length(node->right) + 1);
}

size_t	bst_get_length(t_bst *tree)
{
	return (count_length(tree->root));
}
