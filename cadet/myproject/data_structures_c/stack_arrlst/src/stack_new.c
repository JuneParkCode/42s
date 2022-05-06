/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 14:37:12 by sungjpar          #+#    #+#             */
/*   Updated: 2022/04/18 14:37:12 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "stack_arrlst.h"

t_stack	*stack_new(size_t size)
{
	t_stack	*new_stack;

	new_stack = malloc(sizeof(t_stack));
	if (new_stack == NULL)
		return (NULL);
	new_stack -> lst = arrlst_new_list(size);
	if (new_stack -> lst == NULL)
		return (NULL);
	new_stack -> max_size = size;
	new_stack -> size = 0;
	new_stack -> top = new_stack -> lst -> front;
	return (new_stack);
}
