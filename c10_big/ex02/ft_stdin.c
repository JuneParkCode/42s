/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 10:52:00 by sungjpar          #+#    #+#             */
/*   Updated: 2022/02/22 11:29:38 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

typedef long long	t_l;

t_l		ft_strcmp(char *s1, char *s2);
char	*g_buf_cur;
char	*g_buf_prev;
char	*g_buf_tail;
void	bufcpy(char *dest, char *src, t_l length);
void	buf_control(t_l lengthm, t_l size);

t_l	read_stdin(t_l buffer_size)
{
	t_l	read_size;

	while (1)
	{
		bufcpy(g_buf_prev, g_buf_cur, buffer_size);
		read_size = read(STDIN_FILENO, g_buf_cur, buffer_size);
		buf_control(buffer_size, read_size);
		if (read_size == 0)
			return (1);
	}
	return (0);
}
