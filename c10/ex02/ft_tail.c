/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 11:13:02 by sungjpar          #+#    #+#             */
/*   Updated: 2022/02/20 17:08:31 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>

typedef long long	t_l;

t_l		read_stdin(char *buffer, t_l *idx, t_l buffer_size);
void	put_tail_by_line(char *buffer, t_l length, t_l size, t_l buffer_size);
void	put_tail_by_byte(char *buffer, t_l length, t_l size, t_l buffer_size);
void	ft_msg(char *file_name, t_l err_code);
t_l		get_file_size(char *file_name);

void	do_tail_stdin_line(t_l buffer_size)
{
	t_l		flag;
	t_l		idx;
	char	*buffer;

	flag = 0;
	idx = 0;
	buffer = malloc(buffer_size);
	if (!buffer)
		return ;
	while (!flag)
		flag = read_stdin(buffer, &idx, buffer_size);
	put_tail_by_line(buffer, 10, idx, buffer_size);
	close(STDIN_FILENO);
	free(buffer);
}

void	do_tail_stdin_byte(t_l buffer_size, t_l length)
{
	t_l		flag;
	t_l		idx;
	char	*buffer;

	flag = 0;
	idx = 0;
	buffer = malloc(buffer_size);
	if (!buffer)
		return ;
	while (!flag)
		flag = read_stdin(buffer, &idx, buffer_size);
	put_tail_by_byte(buffer, length, idx, buffer_size);
	close(STDIN_FILENO);
	free(buffer);
}

int	do_tail_line(char *file_name, t_l len, int argc)
{
	char	*buffer;
	t_l		fd;
	t_l		read_size;
	t_l		buffer_size;

	buffer_size = get_file_size(file_name);
	buffer = malloc(buffer_size);
	if (!buffer)
	{
		ft_msg(file_name, errno);
		return (0);
	}
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		ft_msg(file_name, errno);
		free(buffer);
		return (0);
	}
	read_size = read(fd, buffer, buffer_size);
	if (read_size > 0)
		put_tail_by_line(buffer, len, read_size, buffer_size);
	close(fd);
	free(buffer);
	return (1);
}

int	do_tail_byte(char *file_name, t_l len, int argc)
{
	char	*buffer;
	t_l		fd;
	t_l		read_size;
	t_l		buffer_size;

	buffer_size = get_file_size(file_name);
	buffer = malloc(buffer_size);
	if (!buffer)
	{
		ft_msg(file_name, errno);
		return (0);
	}
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		ft_msg(file_name, errno);
		free(buffer);
		return (0);
	}
	read_size = read(fd, buffer, buffer_size);
	if (read_size > 0)
		put_tail_by_byte(buffer, len, read_size, buffer_size);
	close(fd);
	free(buffer);
	return (1);
}
