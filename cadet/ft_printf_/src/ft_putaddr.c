/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 14:41:15 by sungjpar          #+#    #+#             */
/*   Updated: 2022/03/23 15:32:42 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

static void	print_hex(unsigned long long n, int length, int depth)
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
		print_hex(n / 16, length, depth + 1);
	write(1, &c, 1);
}

int	ft_putaddr(void *addr)
{
	print_hex((unsigned long long) addr, 16, 1);
	return (16);
}
