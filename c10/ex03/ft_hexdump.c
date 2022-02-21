/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 20:48:07 by sungjpar          #+#    #+#             */
/*   Updated: 2022/02/20 22:16:48 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>

void	ft_msg(char *file_name, int err_code);
void	print_line(char *buf_current, char *buf_prev, int *is_first, long addr);

long	hexdump(char *file_name, char *buf_current, char *buf_prev, long addr)
{
	int	fd;
	int	read_size;
	int	residue;
	int	flag;

	fd = open(file_name, O_RDONLY);
	flag = -1;
	if (fd == -1)
	{
		ft_msg(file_name, errno);
		return (0);
	}
	residue = 0;
	read_size = read(fd, buf_current, 16);
	while (read_size > 0)
	{
		if ((16 - read_size) != 0)
			residue = 16 - read_size;
		else
		{
			residue = 16;
			print_line(buf_current, buf_prev, &flag, addr);
			addr += 16;
		}
		read_size = read(fd, &buf_current[16 - residue], residue);
	}
	addr += 16 - residue;
	// 남은 buffer 출력 및 hex_address 출력
	close(fd);
	return (addr);
}

void	hexdump_c(char *file_name, char *buf_current, char *buf_prev)
{
}

void	hexdump_stdin(char *buf_current, char *buf_prev)
{
}

