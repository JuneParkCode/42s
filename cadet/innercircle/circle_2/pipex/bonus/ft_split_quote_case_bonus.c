/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_quote_case_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 14:52:52 by sungjpar          #+#    #+#             */
/*   Updated: 2022/07/20 19:55:43 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "pipex_bonus.h"

static char	**convert_lst_to_array(t_list *lst)
{
	const size_t	lst_size = ft_lstsize(lst);
	size_t			idx;
	char			**result_array;

	result_array = malloc_errctl(sizeof(char *) * (lst_size + 1));
	idx = 0;
	while (lst)
	{
		result_array[idx] = ft_strdup((char *)lst->content);
		lst = lst->next;
		++idx;
	}
	result_array[idx] = NULL;
	return (result_array);
}

static char	*get_word(const char *s, const int end, const int start)
{
	char	*word;

	word = malloc_errctl(sizeof(char) * (end - start + 1));
	ft_memset(word, 0, end - start + 1);
	ft_memcpy(word, &s[start], end - start);
	return (word);
}

static int	skip_character(const char *s, int idx, char c)
{
	int	idx_str;

	idx_str = idx;
	while (s[idx_str] == c && s[idx_str])
		++idx_str;
	return (idx_str);
}

static int	skip_until_char(const char *s, int idx, char c)
{
	int	idx_str;

	idx_str = idx;
	while (s[idx_str] != c && s[idx_str])
		++idx_str;
	idx_str += (s[idx_str] == c);
	return (idx_str);
}

char	**ft_split_quote_case(char const *s, char c)
{
	t_list	*lst;
	char	**res;
	size_t	idx_str;
	size_t	idx_start;

	lst = NULL;
	idx_str = skip_character(s, 0, c);
	while (s[idx_str])
	{
		idx_start = idx_str;
		if (s[idx_start] == '\'')
			idx_str = skip_until_char(s, idx_str + 1, '\'');
		else
		{
			while (s[idx_str] != c && s[idx_str])
				++idx_str;
		}
		ft_lstadd_back(&lst, ft_lstnew(get_word(s, idx_str, idx_start)));
		idx_str = skip_character(s, idx_str, c);
	}
	res = convert_lst_to_array(lst);
	ft_lstclear(&lst, free);
	return (res);
}
