/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_pop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 14:37:13 by sungjpar          #+#    #+#             */
/*   Updated: 2022/04/18 14:37:14 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_arrlst.h"

/* if stack is empty, behavior is undefined */
t_item	stack_pop(t_stack *_stack)
{
	t_item	item;

	item = arrlst_pop_back(_stack -> lst);
	_stack -> top = _stack -> lst -> rear;
	--(_stack -> size);
	return (item);
}
