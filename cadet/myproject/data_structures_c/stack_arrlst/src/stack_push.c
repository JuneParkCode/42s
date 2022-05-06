/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 14:37:15 by sungjpar          #+#    #+#             */
/*   Updated: 2022/04/18 14:37:15 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_arrlst.h"

int	stack_push(t_stack *_stack, t_item item)
{
	if (stack_is_full(_stack))
		return (FUNC_ERR);
	arrlst_push_back(_stack -> lst, item);
	_stack -> top = _stack -> lst -> rear;
	++(_stack -> size);
	return (SUCCESS);
}
