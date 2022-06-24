/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bst_new_tree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 20:01:51 by sungjpar          #+#    #+#             */
/*   Updated: 2022/05/30 10:27:17 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../include/bst.h"

t_bst	*bst_new_tree(t_bst_node *root, int (*cmp)(void *, void *))
{
	t_bst	*new_tree;

	new_tree = malloc(sizeof(t_bst));
	new_tree->root = root;
	new_tree->cmp = cmp;
	return (new_tree);
}
