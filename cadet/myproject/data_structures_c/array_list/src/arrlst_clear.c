/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrlst_clear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 14:36:08 by sungjpar          #+#    #+#             */
/*   Updated: 2022/04/18 14:39:48 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array_list.h"

void	arrlst_clear(t_arrlist *lst)
{
	lst -> front = -1;
	lst -> rear = -1;
	lst -> size = 0;
}
