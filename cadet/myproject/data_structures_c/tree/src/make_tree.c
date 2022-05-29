/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_tree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 20:01:51 by sungjpar          #+#    #+#             */
/*   Updated: 2022/05/29 20:04:08 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "tree.h"

t_tree	*make_tree(t_tree_node *root, int (*cmp)(void *, void *))
{
	t_tree	*new_tree;

	new_tree = malloc(sizeof(t_tree));
	new_tree->root = root;
	new_tree->cmp = cmp;
	return (new_tree);
}
