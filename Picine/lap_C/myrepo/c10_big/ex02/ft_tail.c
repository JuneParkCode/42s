/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 11:13:02 by sungjpar          #+#    #+#             */
/*   Updated: 2022/02/22 12:48:45 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>

typedef long long	t_l;

t_l		read_stdin(t_l buffer_size);
void	put_tail_by_byte(char *buffer, t_l length);
void	ft_msg(char *file_name, t_l err_code);
t_l		get_file_size(char *file_name);
void	put_file_name(char *file_name, int flag);
void	buf_control(t_l length, t_l buf_size);
void	bufcpy(char *dest, char *src, t_l length);
char	*g_buf_cur;
char	*g_buf_prev;
char	*g_buf_tail;

void	do_tail_stdin_byte(t_l buf_size)
{
	t_l		flag;
	t_l		idx;

	flag = 0;
	idx = 0;
	while (!flag)
		flag = read_stdin(buf_size);
	put_tail_by_byte(g_buf_tail, buf_size);
	close(STDIN_FILENO);
}

int	do_tail_byte(char *file_name, t_l len, int flag)
{
	t_l		fd;
	t_l		read_size;
	t_l		buf_size;

	read_size = 16;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		ft_msg(file_name, errno);
		return (0);
	}
	while (1)
	{
		buf_size = read_size;
		bufcpy(g_buf_prev, g_buf_cur, len);
		read_size = read(fd, g_buf_cur, len);
		buf_control(len, read_size);
		if (read_size <= 0)
			break;
	}
	if (flag)
		put_file_name(file_name, (flag > 1));
	put_tail_by_byte(g_buf_tail, len);
	close(fd);
	return (1);
}
