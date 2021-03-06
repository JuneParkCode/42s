/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 11:13:02 by sungjpar          #+#    #+#             */
/*   Updated: 2022/02/21 22:26:55 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>

typedef long long	t_l;

t_l		read_stdin(char *buffer, t_l *idx, t_l buffer_size);
void	put_tail_by_byte(char *buffer, t_l length, t_l size);
void	ft_msg(char *file_name, t_l err_code);
t_l		get_file_size(char *file_name);
void	put_file_name(char *file_name, int flag);

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
	put_tail_by_byte(buffer, length, idx);
	close(STDIN_FILENO);
	free(buffer);
}

int	do_tail_byte(char *file_name, t_l len, int flag)
{
	char	*buffer;
	t_l		fd;
	t_l		read_size;
	t_l		buffer_size;

	buffer_size = get_file_size(file_name);
	buffer = malloc(buffer_size);
	if (!buffer)
		return (0);
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		ft_msg(file_name, errno);
		free(buffer);
		return (0);
	}
	read_size = read(fd, buffer, buffer_size);
	if (flag)
		put_file_name(file_name, (flag > 1));
	if (read_size > 0)
		put_tail_by_byte(buffer, len, read_size);
	close(fd);
	free(buffer);
	return (1);
}
