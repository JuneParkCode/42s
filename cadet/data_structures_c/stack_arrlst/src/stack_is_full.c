/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_is_full.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 14:37:10 by sungjpar          #+#    #+#             */
/*   Updated: 2022/04/18 14:37:11 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_arrlst.h"

int	stack_is_full(t_stack *_stack)
{
	return (_stack -> size == _stack -> max_size);
}
