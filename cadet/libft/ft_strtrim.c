/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 16:41:42 by sungjpar          #+#    #+#             */
/*   Updated: 2022/03/14 00:29:51 by sungjpar         ###   ########.fr       */
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
	char			*res;
	size_t			idx_res;
	size_t			start;
	size_t			end;
	size_t			size;

	idx_res = 0;
	start = 0;
	while (is_in_set(s1[start], set) && s1[start])
		++start;
	end = ft_strlen(s1) - 1;
	while (is_in_set(s1[end], set) && start < end)
		--end;
	size = end - start + 2;
	res = malloc(sizeof(char) * (size));
	if (res == NULL)
		return (NULL);
	ft_memset(res, 0, size);
	while (idx_res + 1 < size)
		res[idx_res++] = s1[start++];
	return (res);
}
