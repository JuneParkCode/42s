/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 16:48:48 by sungjpar          #+#    #+#             */
/*   Updated: 2022/07/04 17:21:00 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_all_elements_of_b_to_a(t_deque *a, t_deque *b)
{
	while (b->current_size != 0)
		command_pa(a, b);
}

static void	split(t_deque *a, t_deque *b, const int digit, const int size)
{
	int	n;
	int	target_value;

	n = 0;
	while (n != size)
	{
		target_value = a->get_back(a);
		if (((target_value >> digit) & 1) == 0)
			command_pb(a, b);
		else
			command_ra(a);
		++n;
	}
}

void	radix_sort(t_deque *a, t_deque *b, const int size)
{
	const int	max_len = sizeof(t_item) * 8;
	int			digit;

	digit = 0;
	while ((max_len - digit) && !is_sorted((a)))
	{
		split(a, b, digit, size);
		move_all_elements_of_b_to_a(a, b);
		++digit;
	}
}
