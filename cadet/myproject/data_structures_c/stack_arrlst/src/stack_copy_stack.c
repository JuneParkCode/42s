/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_copy_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 14:37:04 by sungjpar          #+#    #+#             */
/*   Updated: 2022/04/18 14:37:04 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_arrlst.h"

int	stack_copy_stack(t_stack *dest, t_stack *src)
{
	if (dest -> size < src -> size)
		return (FUNC_ERR);
	if (arrlst_copy_list(dest -> lst, src -> lst) == FUNC_ERR)
		return (FUNC_ERR);
	dest -> size = src -> size;
	dest -> top = dest -> lst -> rear;
	return (SUCCESS);
}
