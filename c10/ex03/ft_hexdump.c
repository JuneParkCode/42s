/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 20:48:07 by sungjpar          #+#    #+#             */
/*   Updated: 2022/02/21 15:29:02 by sungjpar         ###   ########.fr       */
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
void	hexdumpl(char *file_name, char *buf_current, char *buf_prev);
void	hexdump_cl(char *file_name, char *buf_current, char *buf_prev);
int		g_buf;
long	g_addr;

void	hexdump(char *file_name, char *buf_current, char *buf_prev)
{	
	int	fd;
	int	flag;

	fd = open(file_name, O_RDONLY);
	flag = -1;
	if (fd == -1)
	{
		ft_msg(file_name, errno);
		return ;
	}
	g_buf = read(fd, &buf_current[g_buf], 16 - g_buf);
	if (g_buf < 0)
		ft_msg(file_name, errno);
	while (g_buf > 0)
	{
		g_buf = 16;
		print_line(buf_current, buf_prev, &flag);
		g_buf = 0;
		g_addr += 16;
		g_buf = read(fd, &buf_current[g_buf], 16 - g_buf);
		if (g_buf != 16)
			break ;
	}
	close(fd);
}

void	hexdump_c(char *file_name, char *buf_current, char *buf_prev)
{
	int	fd;
	int	flag;

	fd = open(file_name, O_RDONLY);
	flag = -1;
	if (fd == -1)
	{
		ft_msg(file_name, errno);
		return ;
	}
	g_buf = read(fd, &buf_current[g_buf], 16 - g_buf);
	if (g_buf < 0)
		ft_msg(file_name, errno);
	while (g_buf > 0)
	{
		g_buf = 16;
		print_line_c(buf_current, buf_prev, &flag);
		g_buf = 0;
		g_addr += 16;
		g_buf = read(fd, &buf_current[g_buf], 16 - g_buf);
		if (g_buf != 16)
			break ;
	}
	close(fd);
}

void	hexdump_stdin(char *buf_current, char *buf_prev)
{
	int	read_size;
	int	flag;

	flag = -1;
	while (1)
	{
		if (g_buf == 16)
		{
			print_line(buf_current, buf_prev, &flag);
			g_buf = 0;
			g_addr += 16;
		}
		read_size = read(STDIN_FILENO, &buf_current[g_buf], \
				16 - g_buf);
		g_buf += read_size;
		if (read_size == 0)
			break ;
	}
}

void	hexdump_c_stdin(char *buf_current, char *buf_prev)
{
	int	read_size;
	int	flag;

	flag = -1;
	while (1)
	{
		if (g_buf == 16)
		{
			print_line_c(buf_current, buf_prev, &flag);
			g_buf = 0;
			g_addr += 16;
		}
		read_size = read(STDIN_FILENO, &buf_current[g_buf], \
				16 - g_buf);
		g_buf += read_size;
		if (read_size == 0)
			break ;
	}
}

void	do_hexdump(int argc, char *argv[], char *buf_current, char *buf_prev)
{
	int	idx;
	int	flag;

	flag = -1;
	idx = 1;
	if (argc == 1)
		hexdump_stdin(buf_current, buf_prev);
	else if (ft_strcmp(argv[1], "-C") == 0)
	{
		idx = 2;
		if (argc == 2)
			hexdump_c_stdin(buf_current, buf_prev);
		else
		{
			while (idx < argc - 1)
				hexdump_c(argv[idx++], buf_current, buf_prev);
			hexdump_cl(argv[idx], buf_current, buf_prev);
		}
	}
	else
	{
		while (idx < argc - 1)
			hexdump(argv[idx++], buf_current, buf_prev);
		hexdumpl(argv[idx], buf_current, buf_prev);
	}
}
