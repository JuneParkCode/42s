/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 14:36:34 by sungjpar          #+#    #+#             */
/*   Updated: 2022/04/18 14:36:36 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "circular_list.h"
#include "libft.h"

void	f_print_nbr(void *content)
{
	int	*n;
	
	n = (int *) content;
	ft_putnbr_fd(*n, 1);
	ft_putchar_fd('\n', 1);
}

void	f_print_str(void *content)
{
	char	*str;

	str = (char *)content;
	ft_putstr_fd(str, 1);
	ft_putchar_fd('\n', 1);
}

void	f_print_chr(void *content)
{
	char	*c;
	
	c = (char *)content;
	ft_putchar_fd(*c, 1);
	ft_putchar_fd('\n', 1);
}

int	main(void)
{
	t_clist	lst;
	t_dnode	*node;

	lst.head = NULL;
	for (int i = 0; i < 10; ++i)
	{
		int	*x;
		x = malloc(sizeof(int));
		*x = i;
		ft_printf("input : %d\n",i);
		node = clst_get_new_node(x);
		clst_addback(&lst, node); 
	}
	clst_print_list(&lst, f_print_nbr);

	ft_printf("length : %d\n", clst_get_length(&lst));
	int	n = 0;
	int	m = 9;

	ft_printf("find test\n");
	node = clst_find_node(&lst, (void *)(&n), f_ptr_intcmp);
	if (node)
	{
		ft_printf("FOUND\n");
		f_print_nbr(node -> content);
		ft_printf("\n");
	}
	
	t_dnode	*node2;
	node2 = clst_find_node(&lst, (void *)(&m), f_ptr_intcmp);
	if (node2)
	{
		ft_printf("FOUND\n");
		f_print_nbr(node2 -> content);
		ft_printf("\n");
	}
	ft_printf("TEST SWAP\n");
	clst_swap_node(&lst, node, node2);
	clst_print_list(&lst, f_print_nbr);
	t_dnode	*temp_node = lst.head;
	clst_clear(&lst, free);
	lst.head = temp_node;
	clst_print_list(&lst, f_print_nbr);
	clst_clear(&lst, free);
	ft_printf("%p", lst.head);
}

