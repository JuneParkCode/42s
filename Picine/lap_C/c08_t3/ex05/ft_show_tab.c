/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 10:40:42 by sungjpar          #+#    #+#             */
/*   Updated: 2022/02/19 11:19:22 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"
int	ft_strlen_(char *str)
{
	int	length;

	length = 0;
	while (str[length])
		length++;
	return (length);
}

void	ft_putnbr(int nb)
{
	unsigned int	n;
	char			c;

	if (nb < 0)
	{
		n = -nb;
		write(1, "-", 1);
	}
	else
		n = nb;
	c = n % 10 + '0';
	n /= 10;
	if (n > 0)
		ft_putnbr(n);
	write(1, &c, 1);
}

void	ft_show_tab(struct s_stock_str *par)
{
	while (par -> str)
	{
		write(1, (par -> str), ft_strlen_(par -> str));
		write(1, "\n", 1);
		ft_putnbr(par -> size);
		write(1, "\n", 1);
		write(1, (par -> copy), ft_strlen_(par -> copy));
		write(1, "\n", 1);
		++par;
	}
}
