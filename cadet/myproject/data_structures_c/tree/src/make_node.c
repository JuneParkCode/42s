/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 20:01:42 by sungjpar          #+#    #+#             */
/*   Updated: 2022/05/29 20:01:46 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "tree.h"

t_tree_node	*make_node(void *content)
{
	t_tree_node	*new_node;
	
	new_node = malloc(sizeof(t_tree_node));
	new_node->left = NULL;
	new_node->right = NULL;
	new_node->content = content;
	return (new_node);
}
