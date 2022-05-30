/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bst_make_node.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 20:01:42 by sungjpar          #+#    #+#             */
/*   Updated: 2022/05/30 10:28:10 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "bst.h"

t_bst_node	*bst_make_node(void *content)
{
	t_bst_node	*new_node;

	new_node = malloc(sizeof(t_bst_node));
	new_node->left = NULL;
	new_node->right = NULL;
	new_node->content = content;
	return (new_node);
}
