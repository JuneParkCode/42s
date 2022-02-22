/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 00:57:53 by sungjpar          #+#    #+#             */
/*   Updated: 2022/02/23 01:05:08 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_list.h"

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	t_list	*cur;

	cur = begin_list;
	if (!cur)
		return (0);
	while (cur && nbr > 0)
	{
		nbr--;
		cur = cur -> next;
	}
	if (nbr == 0)
		return (cur);
	return (0);
}
