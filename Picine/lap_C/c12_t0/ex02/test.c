/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 23:24:27 by sungjpar          #+#    #+#             */
/*   Updated: 2022/02/22 23:48:57 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>
#include <stdio.h>
t_list	*ft_create_elem(void *data)
{
	t_list	*new_list;

	new_list = malloc(sizeof(t_list));
	new_list -> data = data;
	new_list -> next = 0;
	return (new_list);
}

void ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*new_list;
	t_list	*head;

	new_list = ft_create_elem(data);
	head = *begin_list;
	if (!head)
		*begin_list = new_list;
	else
	{
		new_list -> next = head;
		head -> next = head -> next;
		*begin_list = new_list;
	}
}
