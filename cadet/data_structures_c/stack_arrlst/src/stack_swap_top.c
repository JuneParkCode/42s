/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_swap_top.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 14:37:19 by sungjpar          #+#    #+#             */
/*   Updated: 2022/04/18 14:37:20 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_arrlst.h"

int	stack_swap_top(t_stack *_stack, int (*cmp)(t_item, t_item))
{
	t_item	temp;
	t_item	*item_a;
	t_item	*item_b;
	ssize_t	pos;

	if (stack_get_size(_stack) <= 1)
		return (FUNC_ERR);
	pos = _stack -> lst -> rear - 1;
	if (pos < 0)
		pos = pos + _stack -> max_size;
	item_a = &(_stack -> lst -> items[_stack -> lst -> rear]);
	item_b = &(_stack -> lst -> items[pos]);
	temp = *item_a;
	*item_a = *item_b;
	*item_b = temp;
	return (SUCCESS);
}
