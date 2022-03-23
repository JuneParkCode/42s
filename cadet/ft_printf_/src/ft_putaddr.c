/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 14:41:15 by sungjpar          #+#    #+#             */
/*   Updated: 2022/03/23 21:39:17 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../include/libft_printf.h"

static int	ft_putaddr_rec(size_t n, int length, int depth)
{
	unsigned char	c;
	char			*hex;
	int				i;
	
	hex = "0123456789abcdef";
	if (n < 0)
		n = -n;
	i = 0;
	c = hex[n % 16];
	if (depth < length)
		ft_putaddr_rec(n / 16, length, depth + 1);
	write(1, &c, 1);
	return (16);
}

int	ft_putaddr(void *addr)
{
	if (addr == 0)
	{
		ft_putchar('0');
		return (1);
	}
	ft_putaddr_rec((intptr_t) addr, 12, 1);
	return (12);
}
