/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.k       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 19:40:07 by sungjpar          #+#    #+#             */
/*   Updated: 2022/06/27 21:32:29 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h> // for atoi
#include "../include/push_swap.h"

t_item atoll(const char *str)
{
	t_item	n;
	int		idx;

	n = 0;
	idx = str[0] == '-';
	while (str[idx])
	{
		n *= 10;
		n += str[idx] - '0';
		++idx;
	}
	if (str[0] == '-')
		n *= -1;
	return (n);
}

int	main(int argc, char *argv[])
{
	const int SIZE = argc - 1;
	t_deque	*a = make_deque(SIZE);
	t_deque	*b = make_deque(SIZE);
	int	i;

	i = 1;
	while (!(a->is_full_deque(a)))
	{
		a->push_front(a, atoll(argv[i++]));
	}
	radix_sort(a, b, SIZE);
}
