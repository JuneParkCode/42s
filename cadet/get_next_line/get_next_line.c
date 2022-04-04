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
#include "./get_next_line.h"

size_t	has_lr(const char *str)
{
	size_t	idx;

	if (str == NULL)
		return (BUFFER_SIZE);
	idx = 0;
	while (str[idx] && str[idx] != '\n')
		++idx;
	if (str[idx] == '\n')
		return (idx);
	return (BUFFER_SIZE);
}

char	*ft_substr(const char *str, size_t start, size_t len)
{
	char		*res;
	size_t	idx_res;

	if (len == BUFFER_SIZE)
		len = BUFFER_SIZE - start;
	res = malloc(sizeof(char) *(len + 1));
	if (res == NULL)
		return (NULL);
	idx_res = 0;
	while (idx_res < len && str[start])
		res[idx_res++] = str[start++];
	res[idx_res] = 0;
	return (res);
}

char	*get_line(t_list *cur_node)
{
	size_t	idx;
	char		*str;
	char		*res;

	str = cur_node -> content;
	idx = has_lr(str);
	if (idx == BUFFER_SIZE)
		return (NULL);
	res = ft_substr(str, 0, idx + 1);
	str = ft_substr(str, idx + 1, -1);
	free(cur_node -> content);
	cur_node -> content = str;
	return (res);
}

char	*join_str(char *s1, char *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	size_t	res_size;
	size_t	idx_res;
	char		*res;

	len_s1 = 0;
	len_s2 = 0;
	while (s1 && s1[len_s1])
		++len_s1;
	while (s2[len_s2])
		++len_s2;
	res_size = len_s1 + len_s2 + 1;
	res = malloc(res_size);
	idx_res = 0;
	while (idx_res < len_s1)
		res[idx_res++] = *(s1++);
	while (idx_res < res_size)
		res[idx_res++] = *(s2++);
	res[idx_res] = 0;
	free(s1);
	free(s2);
	return (res);
}

char	*get_next_line(int fd)
{
	static t_list *lst;
	t_list				*cur_node;
	char					buf[BUFFER_SIZE];
	char					*res;
	int						flag;

	if (fd < 0)
		return (NULL);
	if (lst == NULL)
		lst_addback(&lst, lst_newnode(fd, NULL));
	cur_node = lst_find(lst, fd);
	res = get_line(cur_node);
	if (res != NULL)
		return (res);
	flag = BUFFER_SIZE;
	while (flag == BUFFER_SIZE)
	{
		flag = read(fd, buf, BUFFER_SIZE);
		if (flag != BUFFER_SIZE)
			return (ft_substr(buf, 0, flag));
		flag = has_lr(buf);
		if (flag != BUFFER_SIZE)
			cur_node -> content = ft_substr(buf, flag + 1, BUFFER_SIZE - flag);
		res = join_str(res, ft_substr(buf, 0, flag));
	}
	return (res);
}
