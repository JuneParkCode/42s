/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_find_item.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 14:37:05 by sungjpar          #+#    #+#             */
/*   Updated: 2022/04/18 14:37:06 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_arrlst.h"

ssize_t	stack_find_item(t_stack *_stack, t_item item, \
		int (*cmp)(t_item, t_item))
{
	return (arrlst_find_item(_stack -> lst, item, cmp));
}
