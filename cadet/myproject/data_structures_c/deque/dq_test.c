/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dq_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.k       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 16:13:00 by sungjpar          #+#    #+#             */
/*   Updated: 2022/06/25 17:03:29 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "deque.h"

int	main(void)
{
	const int	SIZE = 10;
	int			var = 0;

	t_deque	*dq = make_deque(SIZE);
	while (!(dq->is_full_deque(dq)))
	{
		dq->push_front(dq, ++var);
	}
	while (!(dq->is_empty_deque(dq)))
	{
		printf("%d ", dq->get_back(dq));
		dq->pop_back(dq);
	}
	printf("\n==========\n");
	var = 0;
	while (!(dq->is_full_deque(dq)))
	{
		if (var & 1)
		{
			dq->push_front(dq, ++var);
		}
		else
		{
			dq->push_back(dq, ++var);
		}
	}
	printf("\n==========\n");
	printf("\nfront %d\n back %d\n", dq->front_idx, dq->back_idx);
	
	int	v = 0;
	while (!(dq->is_empty_deque(dq)))
	{
		if (v % 2 == 1)
		{
			printf("%d ", dq->get_back(dq));
			dq->pop_back(dq);
		}
		else
		{
			printf("%d ", dq->get_front(dq));
			dq->pop_front(dq);
		}
		++v;
	}
	printf("\n============\n");
	printf("\nfront %d\n back %d\n", dq->front_idx, dq->back_idx);
	for (int i = 0; i < SIZE; ++i)
	{
		printf("%d ", dq->datas[i]);
	}
	return (0);
}

