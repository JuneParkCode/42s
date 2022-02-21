/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 14:25:21 by sungjpar          #+#    #+#             */
/*   Updated: 2022/02/21 22:48:13 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <libgen.h>
#define BUFFER_SIZE 16

void	print_line(char *buf_current, char *buf_prev, int *flag);
void	print_line_c(char *buf_current, char *buf_prev, int *flag);
void	ft_print_hex(long long n, int length, int depth);
void	ft_putstr(char *str);
int		ft_strcmp(char *s1, char *s2);
void	do_hexdump(int argc, char *argv[], char *buf_current, char *buf_prev);
long	g_addr;
int		g_buf;
char	*g_bs_name;

int	main(int argc, char *argv[])
{
	char	buf_current[BUFFER_SIZE];
	char	buf_prev[BUFFER_SIZE];
	int		flag;

	g_addr = 0;
	g_buf = 0;
	g_bs_name = basename(argv[0]);
	flag = -1;
	do_hexdump(argc, argv, buf_current, buf_prev);
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
