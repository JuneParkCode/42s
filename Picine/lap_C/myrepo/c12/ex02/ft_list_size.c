/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 23:40:32 by sungjpar          #+#    #+#             */
/*   Updated: 2022/02/22 23:45:34 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	int		size;
	t_list	*cur;

	size = 0;
	cur = begin_list;
	while (cur)
	{
		cur = cur -> next;
		size++;
	}
	return (size);
}
