/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.k       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 20:25:25 by sungjpar          #+#    #+#             */
/*   Updated: 2022/06/29 22:40:12 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../include/push_swap.h"

static void	push_inputs_to_stack(t_item *numbers, int size, t_deque *stack)
{
	int	idx;

	idx = 0;
	while (idx < size)
	{
		stack->push_front(stack, numbers[idx]);
		++idx;
	}
}

void	push_swap(const int argc, char **argv)
{
	t_deque	*stack_a;
	t_deque	*stack_b;
	t_item	*numbers;
	t_item	*simplified_numbers;
	int		size;

	numbers = convert_inputs_to_number_array(argc, argv, size);
	simplified_numbers = simplify_numbers(numbers);
	stack_a = make_deque(size);
	stack_b = make_deque(size);
	push_inputs_to_stack(simplified_numbers, size, stack_a);
	radix_sort(stack_a, stack_b, size);
	delete_deque(stack_a);
	delete_deque(stack_b);
	free(numbers);
	free(simplified_numbers);
}
