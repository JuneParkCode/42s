/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clst_is_empty.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 17:27:15 by sungjpar          #+#    #+#             */
/*   Updated: 2022/04/15 17:59:12 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "circular_list.h"

int	clst_is_empty(t_clist *lst)
{
	if (lst -> head == NULL)
		return (1);
	else
		return (0);
}
