/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 19:43:23 by sungjpar          #+#    #+#             */
/*   Updated: 2022/03/23 22:28:09 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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
		nb /= 16;
		++size;
	}
	return (size);
}

int	ft_puthex(unsigned int n, int flag)
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

