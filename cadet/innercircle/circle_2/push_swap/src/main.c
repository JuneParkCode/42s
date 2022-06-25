/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.k       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 19:40:07 by sungjpar          #+#    #+#             */
/*   Updated: 2022/06/26 04:55:42 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h> // for atoi
#include "../include/push_swap.h"

int	main(int argc, char *argv[])
{
	const int SIZE = argc - 1;
	t_deque	*a = make_deque(SIZE);
	t_deque	*b = make_deque(SIZE);
	int	i;

	i = 1;
	while (!(a->is_full_deque(a)))
	{
		a->push_front(a, atoi(argv[i++]));
	}
	sort(a, b, 0, SIZE - 1);
	int n = SIZE;
	while (n--)
		command_pa(a, b);
}
