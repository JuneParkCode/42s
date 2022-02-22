/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 10:37:53 by sungjpar          #+#    #+#             */
/*   Updated: 2022/02/22 12:42:32 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef long long t_l;

char	*g_buf_cur;
char	*g_buf_prev;
char	*g_buf_tail;

void	bufcpy(char *dest, char *src, t_l length)
{
	int	idx;

	idx = 0;
	while (idx < length)
	{
		dest[idx] = src[idx];
		idx++;
	}
}

void	buf_control(t_l length, t_l buf_size)
{
	int	idx_tail;
	int	idx_cur;
	int	idx_prev;

	idx_tail = 0;
	idx_cur = 0;
	idx_prev = 0;
	if (buf_size == length)
		bufcpy(g_buf_tail,g_buf_cur, length);
	else
	{
		while (idx_tail < buf_size)
			g_buf_tail[idx_tail++] = g_buf_cur[idx_cur++];
		while (idx_tail < length)
			g_buf_tail[idx_tail++] = g_buf_prev[idx_prev++];
	}
}
