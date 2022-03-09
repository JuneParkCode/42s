/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 20:30:18 by sungjpar          #+#    #+#             */
/*   Updated: 2022/03/09 21:03:13 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

static size_t	strlen(const char *str)
{
	size_t	length;

	length = 0;
	while (str[length])
		++length;
	return (length);
}

/* Function		:	ft_strnstr
 * Description	:	locate first string needle in string within len bytes
 * Param		
 * 	haystack	:	string where to find string
 * 	needle		:	string to find
 * 	len			:	length of bytes of string to search
 * Return Value	:	address of located needle string in haystack
 */
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	idx_haystack;
	size_t	idx_needle;
	size_t	len_needle;

	idx_haystack = 0;
	idx_needle = 0;
	len_needle = strlen(needle);
	while (idx_haystack < len && idx_needle < len_needle)
	{
		if (haystack[idx_haystack] == needle[idx_needle])
			++idx_needle;
		else
			idx_needle = 0;
		++idx_haystack;
	}
	if (len_needle == idx_needle)
		return ((char *)(haystack + idx_needle));
	else
		return (NULL);
}
