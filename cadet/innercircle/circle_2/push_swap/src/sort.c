/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 14:56:04 by sungjpar          #+#    #+#             */
/*   Updated: 2022/07/02 16:20:27 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort(t_deque *a, t_deque *b, const int size)
{
	if (size <= 5)
		sort_under_five(a, b, size);
	else
		radix_sort(a, b, size);
}
