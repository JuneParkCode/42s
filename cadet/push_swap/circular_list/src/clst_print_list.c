/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clst_print_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 18:02:27 by sungjpar          #+#    #+#             */
/*   Updated: 2022/04/15 19:10:55 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "circular_list.h"
#include "libft.h"

void	clst_print_list(t_clist *lst)
{
	t_dnode	*node;

	node = lst -> head;
	while (node)
	{
		ft_putnbr_fd(*((int *) (node -> content)), 1);
		ft_putchar_fd('\n', 1);
		node = node -> next;
		if (node == lst -> head)
			break ;
	}
}
