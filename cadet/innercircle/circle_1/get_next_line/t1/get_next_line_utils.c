/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 17:41:04 by sungjpar          #+#    #+#             */
/*   Updated: 2022/04/04 21:45:38 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "./get_next_line.h"

t_list	*lst_newnode(int fd, char *content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (node == NULL)
		return (NULL);
	node -> fd = fd;
	node -> content = content;
	node -> prev = NULL;
	node -> next = NULL;
	return (node);
}

char	*lst_delone(t_list **lst, t_list *node)
{
	if (node -> prev)
		node -> prev -> next = node -> next;
	if (node -> next)
		node -> next -> prev = node -> prev;
	if (node -> content)
		free(node -> content);
	if (*lst == node)
		*lst = node -> next;
	free(node);
	return (NULL);
}

t_list	*lst_addback(t_list	**lst, t_list *node)
{
	t_list	*cur_node;

	if (lst == NULL || *lst == NULL)
	{
		*lst = node;
		return (node);
	}
	cur_node = *lst;
	while (cur_node -> next)
		cur_node = cur_node -> next;
	cur_node -> next = node;
	node -> prev = cur_node;
	return (node);
}

t_list	*lst_find(t_list **lst, int fd)
{
	t_list	*cur_node;

	cur_node = *lst;
	while (cur_node)
	{
		if (fd == cur_node -> fd)
			return (cur_node);
		cur_node = cur_node -> next;
	}
	return (lst_addback(lst, lst_newnode(fd, NULL)));
}

void	*my_free(void *addr)
{
	if (addr)
		free(addr);
	return (NULL);
}
