/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 14:37:18 by sungjpar          #+#    #+#             */
/*   Updated: 2022/04/18 14:37:19 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_arrlst.h"

int	stack_swap(t_stack *_stack, t_item item_a, t_item item_b, \
		int (*cmp)(t_item, t_item))
{
	if (arrlst_swap(_stack -> lst, item_a, item_b, cmp) == FUNC_ERR)
		return (FUNC_ERR);
	else
		return (SUCCESS);
}
