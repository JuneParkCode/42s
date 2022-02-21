/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 11:54:21 by sungjpar          #+#    #+#             */
/*   Updated: 2022/02/21 17:40:22 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_char_is_printable(const char c)
{
	return (32 <= c && c < 127);
}

void	ft_print_hex(long long n, int length, int depth)
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
		ft_print_hex(n / 16, length, depth + 1);
	write(1, &c, 1);
}

void	ft_print_data_hex(int i, int size, char *addr_cpy)
{
	int	j;
	int	length;
	int	n;

	j = 0;
	length = 46;
	while (j < 16 && (i + j) < size)
	{
		n = addr_cpy[i + j];
		ft_print_hex(n, 2, 1);
		length -= 2;
		if (i + j == size - 1)
			while (length-- > 0)
				write(1, " ", 1);
		if (j != 15)
		{
			length--;
			write(1, " ", 1);
		}
		++j;
	}
}

void	ft_print_data_hex2(int i, int size, char *addr_cpy)
{
	int	j;
	int	length;
	int	n;

	j = 0;
	length = 47;
	while (j < 16 && (i + j) < size)
	{
		n = addr_cpy[i + j];
		ft_print_hex(n, 2, 1);
		length -= 2;
		if (i + j == size - 1)
			while (length-- > 0)
				write(1, " ", 1);
		if (j == 7 && i + j < size - 1)
		{
			length--;
			write(1, " ", 1);
		}
		if (j != 15)
		{
			length--;
			write(1, " ", 1);
		}
		++j;
	}
}

void	ft_print_text(int i, int size, char *addr_char)
{
	int	j;

	j = 0;
	write(1, "|", 1);
	while (j < 16 && (i + j) < size)
	{
		if (ft_char_is_printable(addr_char[i + j]))
			write(1, &addr_char[i + j], 1);
		else
			write(1, ".", 1);
		++j;
	}
	write(1, "|\n", 2);
}
