/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 20:25:25 by sungjpar          #+#    #+#             */
/*   Updated: 2022/07/04 17:19:38 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static void	delete_dqs(t_deque *a, t_deque *b)
{
	delete_deque(a);
	delete_deque(b);
}

static t_status	get_and_check_input(
	int argc, char *argv[], t_deque **a, t_deque **b)
{
	t_deque	*tmp;

	tmp = make_deque(10000);
	if (get_input(argc, argv, tmp) == FAILED)
	{
		delete_deque(tmp);
		return (FAILED);
	}
	*a = make_deque(tmp->current_size);
	*b = make_deque(tmp->current_size);
	simplify_numbers(tmp, *a);
	delete_deque(tmp);
	if (has_duplicate_number(*a) == TRUE)
	{
		delete_dqs(*a, *b);
		return (FAILED);
	}
	return (SUCCESS);
}

t_status	push_swap(const int argc, char **argv)
{
	t_deque	*a;
	t_deque	*b;

	if (get_and_check_input(argc, argv, &a, &b) == FAILED)
		return (FAILED);
	sort(a, b, a->max_size);
	delete_dqs(a, b);
	return (SUCCESS);
}
