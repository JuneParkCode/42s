/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 14:41:15 by sungjpar          #+#    #+#             */
/*   Updated: 2022/03/24 10:49:35 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../include/ft_printf.h"

int	ft_putaddr(void *addr)
{
	if (addr == 0)
	{
		ft_putchar('0');
		return (1);
	}
	return (ft_puthex((unsigned long long) addr, 0));
}
