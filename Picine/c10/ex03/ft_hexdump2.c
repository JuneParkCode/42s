/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 15:25:32 by sungjpar          #+#    #+#             */
/*   Updated: 2022/02/21 15:35:47 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>

void	ft_msg(char *file_name, int err_code);
void	ft_print_hex(long long n, int length, int depth);
void	print_line(char *buf_current, char *buf_prev, int *is_first);
void	print_line_c(char *buf_current, char *buf_prev, int *is_first);
int		ft_strcmp(char *s1, char *s2);
void	ft_putstr(char *str);
int		g_buf;
long	g_addr;

void	hexdumpl(char *file_name, char *buf_current, char *buf_prev)
{	
	int	fd;
	int	flag;
	int	tmp;

	fd = open(file_name, O_RDONLY);
	flag = -1;
	if (fd == -1)
		ft_msg(file_name, errno);
	tmp = g_buf;
	g_buf = read(fd, &buf_current[g_buf], 16 - g_buf);
	if (g_buf < 0)
	{
		ft_msg(file_name, errno);
		g_buf = tmp;
		return ;
	}
	while (g_buf == 16)
	{
		g_buf = 16;
		print_line(buf_current, buf_prev, &flag);
		g_buf = 0;
		g_addr += 16;
		g_buf = read(fd, &buf_current[g_buf], 16 - g_buf);
	}
	close(fd);
}

void	hexdump_cl(char *file_name, char *buf_current, char *buf_prev)
{	
	int	fd;
	int	flag;
	int	tmp;

	fd = open(file_name, O_RDONLY);
	flag = -1;
	if (fd == -1)
		ft_msg(file_name, errno);
	tmp = g_buf;
	g_buf = read(fd, &buf_current[g_buf], 16 - g_buf);
	if (g_buf < 0)
	{
		ft_msg(file_name, errno);
		g_buf = tmp;
		return ;
	}
	while (g_buf == 16)
	{
		g_buf = 16;
		print_line_c(buf_current, buf_prev, &flag);
		g_buf = 0;
		g_addr += 16;
		g_buf = read(fd, &buf_current[g_buf], 16 - g_buf);
	}
	close(fd);
}
