/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clst_del_node.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 14:36:46 by sungjpar          #+#    #+#             */
/*   Updated: 2022/04/18 14:55:24 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "circular_list.h"

void	clst_del_node(t_dnode *node, void (*f_del)(void *))
{
	f_del(node -> content);
	free(node);
}
