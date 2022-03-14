/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 16:43:25 by sungjpar          #+#    #+#             */
/*   Updated: 2022/03/14 18:11:36 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/* Function		:	ft_substr
 * Description	:	Allocates (with malloc(3)) and returns a substring
 *					from the string ’s’.
 *					The substring begins at index ’start’ and is of
 *					maximum size ’len’.
 * Param		
 * 		s		: 	The string from which to create the substring.
 * 		start	:	The start index of the substring in the string
 * 		len		:	The maximum length of the substring.
 * Return Value	:	address of result (substring)
 * 					NULL : allocation failed
 */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	idx_str;
	size_t	len_str;
	size_t	size;

	if (!s)
		return (0);
	len_str = ft_strlen(s);
	if (start >= len_str)
		size = 0;
	else if ((len_str - start) < len)
		size = len_str - start;
	else
		size = len;
	res = malloc(sizeof(char) * (size + 1));
	if (res == NULL)
		return (NULL);
	ft_memset(res, 0, size + 1);
	idx_str = 0;
	while (idx_str < len && (start + idx_str) < len_str)
	{
		res[idx_str] = s[start + idx_str];
		++idx_str;
	}
	return (res);
}
