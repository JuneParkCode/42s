/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 00:26:17 by sungjpar          #+#    #+#             */
/*   Updated: 2022/02/23 00:57:09 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
	t_list	*cur;
	t_list	*next;
	cur = begin_list;
	if (!cur)
		return ;
	while (cur)
	{
		next = cur -> next;
		free_fct(cur -> data);
		free(cur);
		cur = next;
	}
}
