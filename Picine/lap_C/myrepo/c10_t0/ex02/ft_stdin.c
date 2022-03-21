/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 10:52:00 by sungjpar          #+#    #+#             */
/*   Updated: 2022/02/21 22:01:15 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

typedef long long	t_l;

t_l	ft_strcmp(char *s1, char *s2);

t_l	read_stdin(char *buffer, t_l *idx, t_l buffer_size)
{
	t_l	read_size;

	read_size = read(STDIN_FILENO, buffer, buffer_size);
	if (!read_size)
		return (1);
	*idx += read_size;
	while (read_size > 0)
	{
		read_size = read(STDIN_FILENO, &buffer[*idx], buffer_size);
		*idx += read_size;
		if (read_size == 0)
			return (1);
	}
	return (0);
}
