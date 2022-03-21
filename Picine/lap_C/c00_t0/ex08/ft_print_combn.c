/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft_print_combn.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 10:02:44 by sungjpar          #+#    #+#             */
/*   Updated: 2022/02/03 13:20:28 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_combn(int n);
void	ft_putnbr(int nb, int digits, int depth);
void	ft_combn(const int digits, int depth, int cur_num, int result);
int		ft_is_last(int n, int size);

void	ft_print_combn(int n)
{
	if (n < 1 || n > 9 )
		return ;
	ft_combn(n, 0, 0, 0);
}

void	ft_combn(const int digits, int depth, int cur_num, int result)
{
	int	r;

	if (digits == depth)
	{
		ft_putnbr(result, digits, 0);
		if (!ft_is_last(result, digits))
			write(1, ", ", 2);
		return ;
	}
	while (cur_num <= (9 - digits + depth + 1))
	{
		r = result * 10 + cur_num;
		ft_combn(digits, depth + 1, ++cur_num, r);
	}
}

void	ft_putnbr(int nb, int digits, int depth)
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
	if (depth < digits - 1)
		ft_putnbr(n, digits, ++depth);
	write(1, &c, 1);
}

int	ft_is_last(int n, int size)
{
	int	i;

	i = 1;
	while (n > 9)
	{
		n /= 10;
		++i;
	}
	return (n == (10 - size) && i == size);
}
