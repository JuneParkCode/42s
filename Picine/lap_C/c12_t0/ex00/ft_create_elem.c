/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 23:17:18 by sungjpar          #+#    #+#             */
/*   Updated: 2022/02/22 23:23:41 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>
t_list	*ft_create_elem(void *data)
{
	t_list	*new_list;

	new_list = malloc(sizeof(t_list));
	new_list -> data = data;
	new_list -> next = 0;
	return (new_list);
}
