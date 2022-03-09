/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 09:43:45 by sungjpar          #+#    #+#             */
/*   Updated: 2022/02/22 11:29:00 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <libgen.h>
#include <stdio.h>
#include <stdlib.h>

long long	ft_strcmp(char *s1, char *s2);
void		do_tail_stdin_byte(long long buffer_size);
void		do_tail_stdin_line(long long buffer_size);
int			do_tail_line(char *file_name, long long len, int flag);
int			do_tail_byte(char *file_name, long long len, int flag);
void		ft_putstr(char *str);
int			ft_atoi(char *str);
void		put_err_offset(char *str);
char		*g_bs_name;
char		*g_buf_cur;
char		*g_buf_prev;
char		*g_buf_tail;

int	get_length(char *str, long long *length)
{
	*length = ft_atoi(str);
	if (*length < 0)
	{
		put_err_offset(str);
		return (-1);
	}
	return (*length);
}

void	do_tail_mult(int argc, char *argv[], int flag, long long length)
{
	int	idx;

	idx = 1;
	if (!ft_strcmp(argv[idx], "-c"))
	{
		if (get_length(argv[++idx], &length) == -1)
			return ;
		g_buf_cur = malloc(length);
		g_buf_prev = malloc(length);
		g_buf_tail = malloc(length);
		if (argc == 3)
			do_tail_stdin_byte(length);
		else
		{
			flag = argc > 4;
			while (++idx < argc)
				flag += do_tail_byte(argv[idx], length, flag);
		}
		return ;
	}
	free(g_buf_cur);
	free(g_buf_prev);
	free(g_buf_tail);
}

int	main(int argc, char *argv[])
{
	long long	length;
	int			flag;

	flag = 0;
	length = 0;
	g_bs_name = basename(argv[0]);
	if (argc < 3)
		return (1);
	else
		do_tail_mult(argc, argv, flag, length);
	return (0);
}
