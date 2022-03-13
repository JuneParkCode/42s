/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 16:41:42 by sungjpar          #+#    #+#             */
/*   Updated: 2022/03/12 17:23:04 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	is_in_set(const char c, const char *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		++set;
	}
	return (0);
}

static size_t	get_num_set_chars(const char *str, const char *set)
{
	size_t	idx_str;
	size_t	res;

	idx_str = 0;
	res = 0;
	while (str[idx_str])
	{
		res += is_in_set(str[idx_str], set);
		++idx_str;
	}
	return (res);
}

/* Function		:	ft_strtrim
 * Description	:	Allocates (with malloc(3)) and returns a copy of ’s1’ with 
 * 					the characters specified in ’set’ removed from the beginnin
 * 					g and the end of the string.
 * Param		
 * 			s1	: 	address of bytes
 * 			set	:	number to find
 * Return Value	:	address of copy of s1 with the chars specified in set
 * 					NULL : Memory allocation error
 */
char	*ft_strtrim(char const *s1, char const *set)
{
	const size_t	size = ft_strlen(s1) - get_num_set_chars(s1, set) + 1;
	char			*res;
	size_t			idx_res;
	size_t			idx_s1;

	res = malloc(sizeof(char) * (size));
	if (res == NULL)
		return (NULL);
	ft_memset(res, 0, size);
	idx_res = 0;
	idx_s1 = 0;
	while (s1[idx_s1])
	{
		if (!is_in_set(s1[idx_s1], set))
		{
			res[idx_res] = s1[idx_s1];
			++idx_res;
		}
		++idx_s1;
	}
	return (res);
}
