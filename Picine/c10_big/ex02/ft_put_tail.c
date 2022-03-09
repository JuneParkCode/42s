/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_tail.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 10:51:27 by sungjpar          #+#    #+#             */
/*   Updated: 2022/02/22 12:51:39 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

typedef long long	t_l;

void	ft_put(char *str, unsigned long long size);

void	put_tail_by_byte(char *buffer, t_l length)
{
	ft_put(buffer, length);
	ft_put("\n", 1);
}
