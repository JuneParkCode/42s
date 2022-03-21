/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 14:25:21 by sungjpar          #+#    #+#             */
/*   Updated: 2022/02/22 21:07:03 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <libgen.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#define BUFFER_SIZE 16

void	print_line(char *buf_current, char *buf_prev, int *flag);
void	print_line_c(char *buf_current, char *buf_prev, int *flag);
void	ft_print_hex(long long n, int length, int depth);
void	ft_putstr(char *str);
int		ft_strcmp(char *s1, char *s2);
void	do_hexdump(int argc, char *argv[], char *buf_current, char *buf_prev);
void	ft_msg(char *file_name, int err_code);
long	g_addr;
int		g_flag;
int		g_buf;
char	*g_bs_name;

void	do_badfd(char *file_name)
{
	int		fd;
	int		temp;
	char	buf[10];

	fd = open(file_name, O_RDONLY);
	temp = read(fd, buf, 10);
	ft_msg(file_name, errno);
}

int	main(int argc, char *argv[])
{
	char	buf_current[BUFFER_SIZE];
	char	buf_prev[BUFFER_SIZE];
	int		flag;

	g_addr = 0;
	g_buf = 0;
	g_bs_name = basename(argv[0]);
	g_flag = 0;
	flag = -1;
	do_hexdump(argc, argv, buf_current, buf_prev);
	if (!g_flag)
		do_badfd(argv[argc - 1]);
	if (g_buf >= 0 && (g_buf != 0 || g_addr != 0))
	{
		if (argc > 1 && ft_strcmp(argv[1], "-C") == 0)
			print_line_c(buf_current, buf_prev, &flag);
		else
			print_line(buf_current, buf_prev, &flag);
		g_addr += g_buf;
		ft_print_hex(g_addr, 7 + \
				(argc > 1 && ft_strcmp(argv[1], "-C") == 0), 1);
		ft_putstr("\n");
	}
	return (0);
}
