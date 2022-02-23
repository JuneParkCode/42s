/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 17:52:29 by sungjpar          #+#    #+#             */
/*   Updated: 2022/02/23 17:57:08 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 16:49:23 by sungjpar          #+#    #+#             */
/*   Updated: 2022/02/23 17:26:58 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_detach(t_list **begin_list, t_list *current)
{
	t_list	*cur;

	cur = *begin_list;
	if (*begin_list == current)
		*begin_list = 0;
	while (cur -> next == current)
		cur = cur -> next;
	cur -> next = current -> next;
	current -> next = 0;
	return (current);
}

void ft_list_remove_if(t_list **begin_list, void *data_ref, \
		int (*cmp)(), void (*free_fct)(void *))
{
	t_list	*cur;
	t_list	*tmp;

	cur = *begin_list;
	while (cur)
	{
		tmp = cur -> next;
		if (cmp(cur -> data, data_ref) == 0)
			ft_list_detach(begin_list, cur);
		cur = tmp;
	}
}
