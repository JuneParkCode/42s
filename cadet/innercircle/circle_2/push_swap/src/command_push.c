/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 17:54:44 by sungjpar          #+#    #+#             */
/*   Updated: 2022/07/06 10:02:08 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	command_push(t_deque *to, t_deque *from)
{
	t_item	item;

	item = from->get_back(from);
	from->pop_back(from);
	to->push_back(to, item);
}

void	command_pa(t_deque *a, t_deque *b)
{
	command_push(a, b);
	ft_putstr_fd("pa\n", FD_STDOUT);
}

void	command_pb(t_deque *a, t_deque *b)
{
	command_push(b, a);
	ft_putstr_fd("pb\n", FD_STDOUT);
}
