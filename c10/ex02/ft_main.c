/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 09:43:45 by sungjpar          #+#    #+#             */
/*   Updated: 2022/02/21 15:53:49 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <libgen.h>
#include <stdio.h>
#define BUFFER_SIZE 2000000

long long	ft_strcmp(char *s1, char *s2);
void		do_tail_stdin_byte(long long buffer_size, long long length);
void		do_tail_stdin_line(long long buffer_size);
int			do_tail_line(char *file_name, long long len, int flag);
int			do_tail_byte(char *file_name, long long len, int flag);
void		ft_putstr(char *str);
int			ft_atoi(char *str);
char		*g_bs_name;

void	do_tail_mult(int argc, char *argv[], int flag, long long length)
{
	int	idx;

	idx = 1;
	if (!ft_strcmp(argv[idx], "-c"))
	{
		length = ft_atoi(argv[++idx]);
		if (argc == 3)
			do_tail_stdin_byte(BUFFER_SIZE, length);
		else
		{
			flag = argc > 4;
			while (++idx < argc)
				flag += do_tail_byte(argv[idx], length, flag);
		}
		return ;
	}
	length = ft_atoi(argv[idx++]);
	if (!length)
	{
		length = 10;
		idx = 1;
	}
	flag = argc > 3;
	while (idx < argc)
		flag += do_tail_line(argv[idx++], length, flag);
}

int	main(int argc, char *argv[])
{
	long long	length;
	int			flag;

	flag = 0;
	length = 0;
	g_bs_name = basename(argv[0]);
	if (argc == 1)
		do_tail_stdin_line(BUFFER_SIZE);
	else if (argc == 2)
		do_tail_line(argv[1], 10, 0);
	else
		do_tail_mult(argc, argv, flag, length);
	return (0);
}
