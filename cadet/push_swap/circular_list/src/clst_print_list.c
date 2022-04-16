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

void	clst_print_list(t_clist *lst, void (*f_print)(void *))
{
	t_dnode	*node;

	node = lst -> head;
	while (node)
	{
		f_print(node -> content);
		ft_putchar_fd('\n', 1);
		node = node -> next;
		if (node == lst -> head)
			break ;
	}
}

void	f_print_nbr(void *content)
{
	int	*n;
	
	n = (int *) content;
	ft_putnbr_fd(*n, 1);
}

void	f_print_str(void *content)
{
	char	*str;

	str = (char *)content;
	ft_putstr_fd(str, 1);
}

void	f_print_chr(void *content)
{
	char	*c;
	
	c = (char *)content;
	ft_putchar_fd(*c, 1);
}
