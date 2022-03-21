/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sunjpar@student.42seoul.k>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 19:06:20 by sungjpar          #+#    #+#             */
/*   Updated: 2022/02/05 19:06:21 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_char_is_printable(const char c)
{
	return (32 <= c && c < 127);
}

void	ft_print_hex(int n, int length, int depth)
{
	char	*hex;
	int		i;
	char	c;

	hex = "0123456789abcdef";
	i = 0;
	c = hex[n % 16];
	if (depth < length)
		ft_print_hex(n / 16, length, depth + 1);
	write(1, &c, 1);
}

void	ft_putstr_non_printable(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!ft_char_is_printable(str[i]))
		{
			write(1, "\\", 1);
			ft_print_hex(str[i], 2, 1);
		}
		else
			write(1, &str[i], 1);
		++i;
	}
}
