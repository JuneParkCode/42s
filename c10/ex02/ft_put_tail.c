/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_tail.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 10:51:27 by sungjpar          #+#    #+#             */
/*   Updated: 2022/02/20 15:35:31 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

typedef long long	t_l;

void	put_lines(char *str);
void	ft_put(char *str, unsigned long long size);

t_l	get_line_nums(char *buffer, t_l size, t_l buffer_size)
{
	t_l	idx;
	t_l	n;

	idx = 0;
	n = 0;
	while (idx < buffer_size && idx < size)
		n += (buffer[idx++] == '\n');
	return (n);
}

char	*get_line(char *buffer, t_l *idx, t_l size, t_l buffer_size)
{
	char	*line;
	t_l		length;
	t_l		start;
	t_l		idx_line;

	length = 0;
	start = *idx;
	while (buffer[*idx] != '\n' && *idx < size && *idx < buffer_size)
		(*idx)++;
	length = *idx - start + 1;
	line = malloc(sizeof(char) * length);
	idx_line = 0;
	while (start < *idx)
		line[idx_line++] = buffer[start++];
	line[idx_line] = '\n';
	(*idx)++;
	return (line);
}

void	put_tail_by_line(char *buffer, t_l length, t_l size, t_l buffer_size)
{
	t_l		num_line;
	t_l		idx_line;
	t_l		idx_buffer;
	char	**lines;

	num_line = get_line_nums(buffer, size, buffer_size);
	lines = malloc(sizeof(char *) * (num_line + 1));
	idx_line = 0;
	idx_buffer = 0;
	while (idx_line < num_line)
		lines[idx_line++] = get_line(buffer, &idx_buffer, size, buffer_size);
	idx_line = num_line - length;
	if (num_line < length)
	{
		idx_line = 0;
		while (idx_line < num_line)
			put_lines(lines[idx_line++]);
	}
	while (idx_line < num_line)
		put_lines(lines[idx_line++]);
}

void	put_tail_by_byte(char *buffer, t_l length, t_l size, t_l buffer_size)
{
	ft_put(&buffer[size - length], length);
}
