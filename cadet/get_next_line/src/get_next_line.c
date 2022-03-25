/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 17:40:43 by sungjpar          #+#    #+#             */
/*   Updated: 2022/03/25 18:13:57 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "../include/get_next_line.h"
#define BUF_SIZE 100

size_t	has_lr(const char *buf)
{
	size_t	idx;

	idx = 0;
	while (buf[idx] && buf[idx] != '\n')
		++idx;
	if (idx == BUF_SIZE)
		return (-1);
	else
		return (idx);
}

char	*get_residue(const char *buf, size_t flag)
{
	char	*res;
	size_t	idx;

	res = malloc(sizeof(char) * flag);
	idx = 0;
	while (idx < flag)
	{
	}
}

char	*get_next_line(int fd)
{
	static char	*residue;
	char		*result;
	char		buf[BUF_SIZE];
	size_t		flag;
	size_t		read_size;

	flag = -1;
	while (flag < 0)
	{
		read_size = read(fd, buf, BUF_SIZE);
		flag = has_lr(buf);
		if (flag)
		{
			if (residue)
				free(residue);
			residue = get_residue(buf, flag);
		}
		else
		{
			result = 
		}
	}
	return (result);
}
