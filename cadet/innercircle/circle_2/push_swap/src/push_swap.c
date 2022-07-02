/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 20:25:25 by sungjpar          #+#    #+#             */
/*   Updated: 2022/07/02 20:23:34 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../include/libft.h"
#include "../include/push_swap.h"

static void	delete_dqs(t_deque *a, t_deque *b)
{
	delete_deque(a);
	delete_deque(b);
}

void	push_swap(const int argc, char **argv)
{
	t_deque	*tmp;
	t_deque	*a;
	t_deque	*b;
	t_bool	is_valid_input;

	tmp = make_deque(10000);
	is_valid_input = get_input(argc, argv, tmp);
	if (is_valid_input == FALSE)
	{
		delete_deque(tmp);
		ft_printf("Error\n");
		return ;
	}
	a = make_deque(tmp->current_size);
	b = make_deque(tmp->current_size);
	simplify_numbers(tmp, a);
	delete_deque(tmp);
	if (has_duplicate_number(a) == TRUE)
	{
		ft_printf("Error\n");
		return ;
	}
	sort(a, b, a->max_size);
	delete_dqs(a, b);
	return ;
}
