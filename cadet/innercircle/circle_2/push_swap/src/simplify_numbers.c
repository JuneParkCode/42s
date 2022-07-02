/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simplify_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 09:49:08 by sungjpar          #+#    #+#             */
/*   Updated: 2022/07/02 13:22:46 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../include/libft.h"
#include "../include/push_swap.h"

static void	move_element_deque_to_array(t_deque *from, t_item arr[])
{
	int	idx;

	idx = 0;
	while (!(from->is_empty_deque(from)))
	{
		arr[idx] = from->get_back(from);
		from->pop_back(from);
		++idx;
	}
}

static void	move_element_arr_to_deque(t_item arr[], t_deque *to, const int size)
{
	int	idx;

	idx = 0;
	while (idx < size)
	{
		to->push_front(to, arr[idx]);
		++idx;
	}
}

static void	index_numbers(t_item arr[], t_item idx_arr[], const int size)
{
	int	idx;
	int	inner_idx;
	int	val;

	idx = 0;
	while (idx < size)
	{
		inner_idx = 0;
		val = 0;
		while (inner_idx < idx)
		{
			if (arr[inner_idx] < arr[idx])
				++val;
			if (arr[inner_idx] > arr[idx])
				++idx_arr[inner_idx];
			++inner_idx;
		}
		idx_arr[idx] = val;
		++idx;
	}
	idx = 0;
}

void	simplify_numbers(t_deque *from, t_deque *to)
{
	const int	size = from->current_size;
	t_item		*arr;
	t_item		*idx_arr;

	arr = malloc(sizeof(t_item) * size);
	idx_arr = malloc(sizeof(t_item) * size);
	move_element_deque_to_array(from, arr);
	ft_bzero(idx_arr, sizeof(t_item) * size);
	index_numbers(arr, idx_arr, size);
	move_element_arr_to_deque(idx_arr, to, size);
}
