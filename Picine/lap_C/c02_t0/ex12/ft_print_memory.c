/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sunjpar@student.42seoul.k>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 19:06:28 by sungjpar          #+#    #+#             */
/*   Updated: 2022/02/05 19:06:29 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_char_is_printable(const char c)
{
	return (32 <= c && c < 127);
}

void	ft_print_hex(int n, int length, int depth)
{
	unsigned char	c;
	char			*hex;
	int				i;

	hex = "0123456789abcdef";
	if (n < 0)
		n = -n + 128;
	i = 0;
	c = hex[n % 16];
	if (depth < length)
		ft_print_hex(n / 16, length, depth + 1);
	write(1, &c, 1);
}

void	ft_print_data_hex(int i, int size, int n, short *addr_cpy)
{
	int	j;

	j = 0;
	while (j < 8 && (i + 2 * j) < size)
	{
		n = addr_cpy[i + j];
		ft_print_hex(n, 4, 1);
		write(1, " ", 1);
		++j;
	}
}

void	ft_print_text(int i, int size, char *addr_char)
{
	int	j;

	j = 0;
	while (j < 16 && (i + j) < size)
	{
		if (ft_char_is_printable(addr_char[i + j]))
			write(1, &addr_char[i + j], 1);
		else
			write(1, ".", 1);
		++j;
	}
	write(1, "\n", 1);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	short				*addr_cpy;
	unsigned int		i;
	long				addr_long;
	int					n;

	addr_cpy = (short *) addr;
	i = 0;
	n = 0;
	while (i < size)
	{
		addr_long = (long) &addr_cpy[i];
		ft_print_hex(addr_long, 16, 1);
		write(1, ": ", 2);
		ft_print_data_hex(i, size, n, addr_cpy);
		ft_print_text(i, size, addr);
		i += 16;
	}
	return (addr);
}
