/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bst_delete_item.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 20:35:24 by sungjpar          #+#    #+#             */
/*   Updated: 2022/05/30 11:10:17 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "bst.h"

/*
	Delete cases
	case #1
		: left, right -> empty
	case #2
		: only one (left or right) node is empty
	case #3
		: left and right node is exists
*/
void	bst_delete_item(t_bst *tree, void *item)
{
	t_bst_node	*node;

	node = find_node(tree, item);
	if (node == NULL)
		return ;
	// 나중에 짜죠
}
