/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_get_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 14:37:07 by sungjpar          #+#    #+#             */
/*   Updated: 2022/04/18 14:37:08 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_arrlst.h"

int	stack_get_size(t_stack *_stack)
{
	return (_stack -> size);
}