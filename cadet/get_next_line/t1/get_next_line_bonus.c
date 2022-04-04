/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 17:40:43 by sungjpar          #+#    #+#             */
/*   Updated: 2022/04/04 22:02:00 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "./get_next_line.h"

char	*get_next_line(int fd)
{
	static t_list	*lst;
	char			*res;
	char			buf[BUFFER_SIZE + 1];
	t_list			*node;
	int				read_size;

	if (fd < 0)
		return (NULL);
	node = lst_find(&lst, fd);
	res = f_get_line(node);
	if (res)
		return (res);
	res = f_substr(node -> content, 0, &node);
	read_size = BUFFER_SIZE;
	while (read_size == BUFFER_SIZE)
	{
		read_size = read(fd, buf, BUFFER_SIZE);
		if (read_size <= 0 && lst_delone(&lst, node) == 0)
			return (res);
		buf[read_size] = 0;
		read_size = f_find_char(buf, '\n');
		res = f_strnjoin(res, buf, read_size + 1);
	}
	node -> content = f_substr(buf, read_size + 1, &node);
	return (res);
}

size_t	f_find_char(const char *str, const char c)
{
	size_t	idx;

	idx = 0;
	if (str == NULL)
		return (BUFFER_SIZE);
	while (str[idx] && str[idx] != c)
		++idx;
	if (str[idx] == c)
		return (idx);
	else
		return (BUFFER_SIZE);
}

char	*f_strnjoin(char *s1, const char *s2, size_t len)
{
	char	*res;
	size_t	len_s1;
	size_t	len_s2;
	size_t	idx_res;

	len_s1 = 0;
	len_s2 = 0;
	idx_res = 0;
	while (s1 && s1[len_s1])
		++len_s1;
	res = malloc(sizeof(char) * (len_s1 + len + 1));
	if (res == NULL)
		return (NULL);
	while (s1 && *s1)
		res[idx_res++] = *(s1++);
	while (idx_res < (len_s1 + len))
		res[idx_res++] = *(s2++);
	res[idx_res] = 0;
	my_free(s1 - len_s1);
	return (res);
}

char	*f_substr(const char *str, size_t idx, t_list **node)
{
	size_t	len_str;
	size_t	res_size;
	size_t	idx_res;
	char	*res;

	len_str = 0;
	idx_res = 0;
	while (str && str[len_str])
		++len_str;
	res_size = len_str - idx + 1;
	if (res_size <= 1)
		return (NULL);
	res = malloc(sizeof(char) * res_size);
	if (res == NULL)
		return (NULL);
	while (str && str[idx])
		res[idx_res++] = str[idx++];
	res[idx_res] = 0;
	(*node)->content = my_free((*node)->content);
	return (res);
}

char	*f_get_line(t_list *node)
{
	size_t	idx_lr;
	size_t	size_res;
	size_t	idx_res;
	char	*res;
	char	*str;

	str = node -> content;
	idx_lr = f_find_char(str, '\n');
	if (idx_lr == BUFFER_SIZE)
		return (NULL);
	size_res = idx_lr + 2;
	res = malloc(sizeof(char) * size_res);
	idx_res = 0;
	while (idx_res <= idx_lr)
	{
		res[idx_res] = str[idx_res];
		++idx_res;
	}
	res[idx_res] = 0;
	node -> content = my_free(node -> content);
	node -> content = f_substr(str, idx_lr + 1, &node);
	return (res);
}
