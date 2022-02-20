/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 21:23:57 by sungjpar          #+#    #+#             */
/*   Updated: 2022/02/20 22:12:01 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
void	ft_putstr(char *str);
void	ft_print_hex(long n, int length, int depth);
void	ft_print_data_hex2(int i, int size, char *addr_cpy);

void	bufcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		dest[i] = src[i];
		++i;
	}
}

int	is_equal_buf(char *buf1, char *buf2)
{
	int	i;

	i = 0;
	while (i < 16 && buf1[i] == buf2[i])
		++i;
	return (i == 16);
}

void	print_line(char *buf_current, char *buf_prev, int *flag, long n)
{
	if (*flag == -1)
	{
		ft_print_hex(n, 7, 1);
		ft_putstr(" ");
		ft_print_data_hex2(0, 16, buf_current);
		bufcpy(buf_prev, buf_current);
		*flag = 0;
	}
	else if (*flag == 0 && is_equal_buf(buf_current, buf_prev))
	{
		ft_putstr("*");
		*flag = 1;
	}
	else
	{
		ft_print_hex(n, 7, 1);
		ft_putstr(" ");
		ft_print_data_hex2(0, 16, buf_current);
		bufcpy(buf_prev, buf_current);
		*flag = 0;
	}
	ft_putstr("\n");
}
