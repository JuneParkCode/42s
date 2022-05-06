/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_resize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 14:37:16 by sungjpar          #+#    #+#             */
/*   Updated: 2022/04/18 14:37:17 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_arrlst.h"

ssize_t	stack_resize(t_stack *_stack, ssize_t size)
{
	if (arrlst_resize(&(_stack -> lst), size) == -1)
		return (-1);
	_stack -> max_size = size;
	return (_stack -> max_size);
}
