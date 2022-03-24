/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 14:12:41 by sungjpar          #+#    #+#             */
/*   Updated: 2022/03/24 10:50:23 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../include/ft_printf.h"

static int	get_size(const long long n)
{
	unsigned int	nb;
	int				size;

	size = (n < 0);
	if (n == 0)
		return (1);
	else if (n < 0)
		nb = -n;
	else
		nb = n;
	while (nb > 0)
	{
		nb /= 10;
		++size;
	}
	return (size);
}

int	ft_putnbr(const long long n)
{
	unsigned int		size = get_size(n);
	unsigned int		nb;
	unsigned int		idx;
	char				str[size];

	idx = size;
	if (n < 0)
	{
		nb = -n;
		str[0] = '-';
	}
	else
		nb = n;
	while (nb >= 10)
	{
		str[--idx] = nb % 10 + '0';
		nb /= 10;
	}
	str[--idx] = nb % 10 + '0';
	write(1, str, size);
	return (size);
}
