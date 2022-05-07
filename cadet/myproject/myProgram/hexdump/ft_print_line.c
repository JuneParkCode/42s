/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 21:23:57 by sungjpar          #+#    #+#             */
/*   Updated: 2022/02/23 12:48:13 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_putstr(char *str);
void	ft_print_hex(long long n, int length, int depth);
void	ft_print_data_hex(int i, int size, char *addr_cpy);
void	ft_print_data_hex2(int i, int size, char *addr_cpy);
void	ft_print_text(int i, int size, char *addr_char);

long	g_addr;
int		g_buf;
int		g_flag;

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

void	print_line(char *buf_current, char *buf_prev, int *flag)
{
	if ((*flag == -1 && !g_flag) || is_equal_buf(buf_current, buf_prev) == 0
		|| g_flag == 2)
	{
		ft_print_hex(g_addr, 7, 1);
		ft_putstr(" ");
		ft_print_data_hex(0, g_buf, buf_current);
		ft_putstr("\n");
		bufcpy(buf_prev, buf_current);
		*flag = 1;
		g_flag = 1;
	}
	else if (*flag == 1 && is_equal_buf(buf_current, buf_prev))
	{
		ft_putstr("*\n");
		*flag = 2;
	}
}

void	print_line_c(char *buf_current, char *buf_prev, int *flag)
{
	if ((*flag == -1 && !g_flag) || is_equal_buf(buf_current, buf_prev) == 0
		|| g_flag == 2)
	{
		ft_print_hex(g_addr, 8, 1);
		ft_putstr("  ");
		ft_print_data_hex2(0, g_buf, buf_current);
		ft_putstr("  ");
		ft_print_text(0, g_buf, buf_current);
		bufcpy(buf_prev, buf_current);
		*flag = 1;
		g_flag = 1;
	}
	else if (*flag == 1 && is_equal_buf(buf_current, buf_prev))
	{
		ft_putstr("*\n");
		*flag = 2;
	}
}
