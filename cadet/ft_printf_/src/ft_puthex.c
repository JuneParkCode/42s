/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 19:43:23 by sungjpar          #+#    #+#             */
/*   Updated: 2022/03/24 10:50:16 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../include/ft_printf.h"

static int	get_size(unsigned long long n)
{
	int				size;

	size = (n < 0);
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 16;
		++size;
	}
	return (size);
}

int	ft_puthex(unsigned long long n, int flag)
{
	const int		len = get_size(n);
	char			str[len];
	char			*hex;
	int				idx;

	if (flag)
		hex = "0123456789ABCDEF";
	else
		hex = "0123456789abcdef";
	idx = len;
	while (idx)
	{
		str[--idx] = hex[n % 16];
		n /= 16;
	}
	write(1, str, len);
	return (len);
}

