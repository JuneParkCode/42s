/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_clear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 14:37:02 by sungjpar          #+#    #+#             */
/*   Updated: 2022/04/18 14:37:03 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_arrlst.h"

void	stack_clear(t_stack *_stack)
{
	arrlst_clear(_stack -> lst);
	_stack -> size = 0;
	_stack -> top = _stack -> lst -> rear;
}
