/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_item.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 20:35:24 by sungjpar          #+#    #+#             */
/*   Updated: 2022/05/29 20:42:42 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "tree.h"

void	delete_item(t_tree *tree, void *item)
{
	t_tree_node	*node;

	node = find_node(tree, item);
	if (node == NULL)
		return ;
	// delete process.......
}
