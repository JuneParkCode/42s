/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_tail.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 10:51:27 by sungjpar          #+#    #+#             */
/*   Updated: 2022/02/21 22:43:56 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

typedef long long	t_l;

void	ft_put(char *str, unsigned long long size);

void	put_tail_by_byte(char *buffer, t_l length, t_l size)
{
	if (length > size)
		ft_put(&buffer[0], size);
	else
		ft_put(&buffer[size - length], length);
}
