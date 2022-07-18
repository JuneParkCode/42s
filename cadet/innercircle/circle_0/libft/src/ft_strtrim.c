//* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 16:41:42 by sungjpar          #+#    #+#             */
/*   Updated: 2022/07/18 16:26:04 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static size_t	set_start_point(const char *s1, const char *set)
{
	size_t	idx;

	idx = 0;
	while (ft_isinset(s1[idx], set) && s1[idx])
		++idx;
	return (idx);
}

static size_t	set_end_point(const char *s1, const char *set)
{
	size_t	idx;

	if (s1[0] == 0)
		return (0);
	idx = ft_strlen(s1) - 1;
	if (!ft_isinset(s1[idx], set))
		return (idx + 1);
	while (ft_isinset(s1[idx], set) && idx > 0)
		--idx;
	return (idx);
}

static int	get_size_of_trimmed_string(int start, int end)
{
	if (end <= start)
		return (1);
	else
		return (end - start + 2);
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
	size_t			start;
	size_t			end;
	size_t			size;

	start = set_start_point(s1, set);
	end = set_end_point(s1, set);
	size = get_size_of_trimmed_string(start, end);
	res = malloc(sizeof(char) * (size));
	if (res == NULL)
		return (NULL);
	ft_memset(res, 0, size);
	if (size == 1)
		return (res);
	ft_strlcpy(res, s1 + start, size);
	return (res);
}
