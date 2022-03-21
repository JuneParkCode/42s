/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 11:09:12 by sungjpar          #+#    #+#             */
/*   Updated: 2022/02/10 09:36:13 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(const char *str)
{
	int	length;

	length = 0;
	while (str[length])
		length++;
	return (length);
}

void	ft_putstr(const char *str)
{
	int	length;

	length = ft_strlen(str);
	write(1, str, length);
}

int	ft_itoa(int nb, int i, char *numbers, int sign)
{
	unsigned int	n;
	char			c;
	int				length;

	if (nb < 0)
	{
		n = -nb;
		numbers[i++] = '-';
		sign = 0;
	}
	n = nb;
	c = n % 10 + '0';
	if (n >= 10)
	{
		length = ft_itoa(n / 10, i + 1, numbers, sign);
		numbers[length - i - sign] = c;
		return (length);
	}
	else
	{
		numbers[!sign] = c;
		numbers[i] = 0;
		return (i);
	}
}

void	ft_putnbr(int nb)
{
	char	numbers[20];

	if (nb == 0)
		ft_putstr("0");
	ft_itoa(nb, 0, numbers, 1);
	ft_putstr(numbers);
}
