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

#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#define BUF_SIZE 2000

char	*get_line(char *str, int *idx)
{
	char	*line;
	int		len;

	len = 0;
	idx = 0;
	while (str[len] && str[len] != '\n')
		len++;
	line = malloc(sizeof(char) * len);
	while (str[*idx] != '\n')
	{
		line[*idx] = str[*idx];
		(*idx)++;
	}
	line[*idx] = 0;
	return (line);
}

int	get_file_size(char *file_name)
{
	int		fd;
	int		read_size;
	int		file_size;
	char	buffer[BUF_SIZE];

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		ft_puterr(file_name, errno);
		return (-1);
	}
	while (1)
	{
		read_size = read(file_name, buffer, BUF_SIZE);
		if (read_size <= 0)
			break ;
		file_size += read_size;
	}
	return (file_size);
}

int	get_line_num(char *str)
{
	int	line_num;

	line_num = 0;
	while (*str)
		line_num += (*(str++) == '\n');
	return (line_num);
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
		lines[idx_lines++] = get_line(&buffer[idx_buffer], &idx_buffer);
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
	{
		ft_puterr(file_name, errno);
		return (0);
	}
	read_size = read(file_name, buffer, file_size);
	if (read_size < 0)
	{
		ft_puterr(file_name, errno);
		return (0);
	}
	return (get_lines(buffer, get_line_num(buffer)));
}
