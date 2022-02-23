/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:05:02 by sungjpar          #+#    #+#             */
/*   Updated: 2022/02/23 19:51:16 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#define BUF_SIZE 2000


int	get_file_size(char *file_name)
{
	int		fd;
	int		read_size;
	int		file_size;
	char	buffer[BUF_SIZE];

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (-1);
	while (1)
	{
		read_size = read(fd, buffer, BUF_SIZE);
		if (read_size <= 0)
			break ;
		file_size += read_size;
	}
	return (file_size);
}

int	get_line_num(char *str, long long size)
{
	int	line_num;
	int	idx_str;

	line_num = 0;
	idx_str = 0;
	while (idx_str < size)
		line_num += (str[idx_str++] == '\n');
	return (line_num);
}

char	*get_line(char *str)
{
	char	*line;
	int		len;
	int		idx_line;

	len = 0;
	idx_line = 0;
	while (str[len] && str[len] != '\n')
		len++;
	line = malloc(sizeof(char) * (len + 1));
	while (idx_line < len)
	{
		line[idx_line] = str[idx_line];
		idx_line++;
	}
	line[len] = 0;
	return (line);
}

char	**get_lines(char *buffer, int line_num)
{
	char	**lines;
	char	*line;
	int		idx_lines;
	int		idx_buffer;

	lines = malloc(sizeof(char *) * (line_num + 1));
	idx_lines = 0;
	idx_buffer = 0;
	while (idx_lines < line_num)
	{
		lines[idx_lines] = get_line(&buffer[idx_buffer]);
		idx_buffer += ft_strlen(lines[idx_lines]) + 2;
		idx_lines++;
	}
	lines[line_num] = 0;
	return (lines);
}

char	**read_file(char *file_name)
{
	long long	file_size;
	long long	read_size;
	int			idx_buf;
	int			fd;
	char		*buffer;

	file_size = get_file_size(file_name);
	buffer = malloc(file_size);
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (0);
	read_size = read(fd, buffer, file_size);
	if (read_size < 0)
		return (0);
	return (get_lines(buffer, get_line_num(buffer, read_size)));
}
