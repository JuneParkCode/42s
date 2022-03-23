/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 14:12:41 by sungjpar          #+#    #+#             */
/*   Updated: 2022/03/23 16:05:45 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../include/libft_printf.h"

static int	get_size(const int n, const unsigned int base)
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
		nb /= base;
		++size;
	}
	return (size);
}

int	ft_putnbr_base(const int n, const char *base)
{
	const unsigned int		len_base = ft_strlen(base);
	const unsigned int		size = get_size(n, len_base);
	unsigned int			nb;
	unsigned int			idx;
	char					str[size];

	idx = size;
	if (n < 0)
	{
		nb = -n;
		str[0] = '-';
	}
	else
		nb = n;
	while (nb >= len_base)
	{
		str[--idx] = base[n % len_base];
		nb /= len_base;
	}
	write(1, str, size);
	return (size);
}
